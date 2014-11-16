#include "defs.h"
#include <aio.h>

int main(int argc, char* argv[]) {
    int fd = -1, num;
    char buf[10];
    struct aiocb cb;
    const struct aiocb *list[1] = { &cb };

    memset(buf, 0, sizeof(buf));
    memset(&cb, 0, sizeof(cb));
    ec_neg1( fd = open("/tmp/datafile.txt", O_RDONLY) );
    cb.aio_fildes = fd;
    cb.aio_buf = buf;
    cb.aio_nbytes = sizeof(buf);
    cb.aio_sigevent.sigev_notify = SIGEV_NONE;
    while (true) {
        ec_neg1( aio_read(&cb) );
        ec_neg1( aio_suspend(list, 1, NULL) );
        ec_neg1( num = aio_return(&cb));
        if (num == 0) break;
        write(STDOUT_FILENO, buf, num);
        cb.aio_offset += num;
    }
    EC_CLEANUP
EC_CLEANUP_BGN
    if (fd > -1)
        close(fd);
    return 0;
EC_CLEANUP_END
}
