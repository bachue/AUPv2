#define SOCKETNAME "/tmp/MySocket"
#include "defs.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/un.h>

static bool run_server(struct sockaddr_un *sap);

int main(int argc, char  *argv[]) {
    struct sockaddr_un sa;

    unlink(SOCKETNAME);
    strcpy(sa.sun_path, SOCKETNAME);
    sa.sun_family = AF_UNIX;

    if (fork() == 0) {
        int fd_skt;
        char buf[100];

        ec_neg1(fd_skt = socket(AF_UNIX, SOCK_STREAM, 0));
        while (connect(fd_skt, (struct sockaddr *) &sa, sizeof(sa)) == -1) {
            if (errno == ENOENT) {
                sleep(1);
                continue;
            } else {
                EC_FAIL
            }
        }
        ec_neg1(write(fd_skt, "Hello!", sizeof("Hello!")));
        ec_neg1(read(fd_skt, buf, sizeof(buf)));
        printf("Client got \"%s\"\n", buf);
        ec_neg1(close(fd_skt));
        exit(EXIT_SUCCESS);
    } else {
        if (run_server(&sa))
            exit(EXIT_SUCCESS);
    }
EC_CLEANUP_BGN
    exit(EXIT_FAILURE);
EC_CLEANUP_END
}

static bool run_server(struct sockaddr_un *sap) {
    int fd_skt, fd_client, fd_hwm = 0, fd;
    char buf[100];
    fd_set set, read_set;
    ssize_t nread;

    ec_neg1(fd_skt = socket(AF_UNIX, SOCK_STREAM, 0));
    ec_neg1(bind(fd_skt, (struct sockaddr *) sap, sizeof(*sap)));
    ec_neg1(listen(fd_skt, SOMAXCONN));
    if (fd_skt > fd_hwm) fd_hwm = fd_skt;
    FD_ZERO(&set);
    FD_SET(fd_skt, &set);
    while (true) {
        read_set = set;
        ec_neg1(select(fd_hwm + 1, &read_set, NULL, NULL, NULL));
        for (fd = 0; fd <= fd_hwm; fd++) {
            if (FD_ISSET(fd, &read_set)) {
                if (fd == fd_skt) {
                    ec_neg1(fd_client = accept(fd_skt, NULL, 0));
                    FD_SET(fd_client, &set);
                    if (fd_client > fd_hwm) fd_hwm = fd_client;
                } else {
                    ec_neg1(nread = read(fd, buf, sizeof(buf)));
                    if (nread == 0) {
                        FD_CLR(fd, &set);
                        if (fd == fd_hwm) fd_hwm--;
                        ec_neg1(close(fd));
                    } else {
                        printf("Server got \"%s\"\n", buf);
                        ec_neg1(write(fd, "Goodbye!", sizeof("Goodbye!")));
                    }
                }
            }
        }
    }
    ec_neg1(close(fd_skt));
    return true;
EC_CLEANUP_BGN
    return false;
EC_CLEANUP_END
}
