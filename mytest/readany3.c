#include "defs.h"
#include <poll.h>

#define MAXFDS 100

int readany3(int fds[], int nfds, int *whichp)
{
        struct pollfd fdinfo[MAXFDS] = { { 0 } };
        int i;
        unsigned char c;

        if (nfds > MAXFDS) {
                errno = E2BIG;
                EC_FAIL
        }
        for (i = 0; i < nfds; i++) {
                fdinfo[i].fd = fds[i];
                fdinfo[i].events = POLLIN | POLLPRI;
        }
        ec_neg1( poll(fdinfo, nfds, -1) )
        for (i = 0; i < nfds; i++) {
                if (fdinfo[i].revents & (POLLIN | POLLPRI)) {
                        c = 0; /* return value for EOF */
                        ec_neg1( read(fdinfo[i].fd, &c, 1) )
                        *whichp = i;
                        return c;
                }
        }
        /* "impossible" to get here */
        errno = 0;
        EC_FAIL

EC_CLEANUP_BGN
        return -1;
EC_CLEANUP_END
}

static void readany_test3(void)
{
        int fds[2] = {-1, -1}, which;
        int c;
        bool ok = false;

        ec_neg1( fds[0] = open("/dev/tty", O_RDWR) )
        ec_neg1( fds[1] = open("/dev/pts/0", O_RDWR) )
        while ((c = readany3(fds, 2, &which)) > 0)
                printf("Got %c from terminal %d\n", isprint(c) ? c : '?', which);
        ec_neg1( c )
        ok = true;
        EC_CLEANUP

EC_CLEANUP_BGN
        if (fds[0] != -1)
                (void)close(fds[0]);
        if (fds[1] != -1)
                (void)close(fds[1]);
        if (!ok)
                EC_FLUSH("readany_test3")
EC_CLEANUP_END
}

int main(int argc, char* argv[]) {
    readany_test3();
    return 0;
}
