#include "defs.h"

void fsort(void);

int main(int argc, char  *argv[]) {
    fsort();
    return 0;
}

void fsort(void) {
    int pfdout[2], pfdin[2], fd;
    ssize_t nread;
    pid_t pid;
    char buf[512];

    ec_neg1(pipe(pfdout));
    ec_neg1(pipe(pfdin));
    ec_neg1(pid = fork());
    if (pid == 0) {
        ec_neg1(dup2(pfdout[0], STDIN_FILENO));
        ec_neg1(close(pfdout[0]));
        ec_neg1(close(pfdout[1]));
        ec_neg1(dup2(pfdin[1], STDOUT_FILENO));
        ec_neg1(close(pfdin[0]));
        ec_neg1(close(pfdin[1]));
        execlp("sort", "sort", NULL);
        EC_FAIL
    }

    ec_neg1(close(pfdout[0]));
    ec_neg1(close(pfdin[1]));

    ec_neg1(fd = open("datafile", O_RDONLY));
    while (true) {
        ec_neg1(nread = read(fd, buf, sizeof(buf)));
        if (nread == 0)
            break;
        ec_neg1(write(pfdout[1], buf, nread));
    }
    ec_neg1(close(fd));
    ec_neg1(close(pfdout[1]));

    while (true) {
        ec_neg1(nread = read(pfdin[0], buf, sizeof(buf)));
        if (nread == 0)
            break;
        ec_neg1(write(STDOUT_FILENO, buf, nread));
    }

    ec_neg1(close(pfdin[0]));
    ec_neg1(waitpid(pid, NULL, 0));
    return;
EC_CLEANUP_BGN
    EC_FLUSH("fsort");
EC_CLEANUP_END
}
