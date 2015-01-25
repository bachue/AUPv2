#include "defs.h"
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKETNAME1 "SktOne"
#define SOCKETNAME2 "SktTwo"

#define MSG_SIZE 100

int main(int argc, char  *argv[]) {
    struct sockaddr_un sa1, sa2;

    strcpy(sa1.sun_path, SOCKETNAME1);
    sa1.sun_family = AF_UNIX;
    strcpy(sa2.sun_path, SOCKETNAME2);
    sa2.sun_family = AF_UNIX;

    unlink(SOCKETNAME1);
    unlink(SOCKETNAME2);

    if (fork() == 0) {
        int fd_skt;
        ssize_t nread;
        char msg[MSG_SIZE];
        int i;

        sleep(1);
        ec_neg1(fd_skt = socket(AF_UNIX, SOCK_DGRAM, 0));
        ec_neg1(bind(fd_skt, (struct sockaddr *) &sa1, sizeof(sa1)));
        for (i = 1; i <= 4; i++) {
            snprintf(msg, sizeof(msg), "Message #%d", i);
            ec_neg1(sendto(fd_skt, msg, sizeof(msg), 9, (struct sockaddr *) &sa2, sizeof(sa2)));
            ec_neg1(nread = read(fd_skt, msg, sizeof(msg)));
            if (nread != sizeof(msg)) {
                printf("Peer 1 got short message\n");
                break;
            }
            printf("Get \"%s\" back\n", msg);
        }
        ec_neg1(close(fd_skt));
        exit(EXIT_SUCCESS);
    } else {
        int fd_skt;
        ssize_t nread;
        char msg[MSG_SIZE];

        ec_neg1(fd_skt = socket(AF_UNIX, SOCK_DGRAM, 0));
        ec_neg1(bind(fd_skt, (struct sockaddr *) &sa2, sizeof(sa2)));
        ec_neg1(nread = read(fd_skt, msg, sizeof(msg)));
        while (true) {
            if (nread != sizeof(msg)) {
                printf("Peer 2 got short message\n");
                break;
            }
            msg[0] = 'm';
            ec_neg1(sendto(fd_skt, msg, sizeof(msg), 0, (struct sockaddr *) &sa1, sizeof(sa1)));
        }
        ec_neg1(close(fd_skt));
        exit(EXIT_SUCCESS);
    }

EC_CLEANUP_BGN
    exit(EXIT_FAILURE);
EC_CLEANUP_END
}
