#include "defs.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define REQUEST "GET / HTTP/1.0\r\n\r\n"

int main(int argc, char  *argv[]) {
    struct sockaddr_in sa;
    int fd_skt;
    char buf[1000];
    ssize_t nread;

    sa.sin_family = AF_INET;
    sa.sin_port = htons(3000);
    sa.sin_addr.s_addr = inet_addr("192.168.1.4");

    ec_neg1(fd_skt = socket(AF_INET, SOCK_STREAM, 0));
    ec_neg1(connect(fd_skt, (struct  sockaddr *) &sa, sizeof(sa)));
    ec_neg1(write(fd_skt, REQUEST, strlen(REQUEST)));
    ec_neg1(nread = read(fd_skt, buf, sizeof(buf)));

    write(STDOUT_FILENO, buf, nread);
    ec_neg1(close(fd_skt));

    exit(EXIT_SUCCESS);
EC_CLEANUP_BGN
    exit(EXIT_FAILURE);
EC_CLEANUP_END
}
