#include "defs.h"

void fsort0(void);

int main(int argc, char  *argv[]) {
    fsort0();
    return 0;
}

void fsort0(void) {
    int pfd[2], fd;
    ssize_t nread;
    pid_t pid;
    char buf[512];

    ec_neg1(pipe(pfd));
    ec_neg1(pid = fork());
    if (pid == 0) {
        ec_neg1(dup2(pfd[0], STDIN_FILENO));
        ec_neg1(close(pfd[0]));
        ec_neg1(dup2(pfd[1], STDOUT_FILENO));
        ec_neg1(close(pfd[1]));
        execlp("sort", "sort", NULL);
        EC_FAIL
    }

    ec_neg1(fd = open("datafile", O_RDONLY));
    while (true) {
        ec_neg1(nread = read(fd, buf, sizeof(buf)));
        if (nread == 0)
            break;
        ec_neg1(write(pfd[1], buf, nread));
    }
    ec_neg1(close(fd));
    ec_neg1(close(pfd[1]));

    while (true) {
        ec_neg1(nread = read(pfd[0], buf, sizeof(buf)));
        if (nread == 0)
            break;
        ec_neg1(write(STDOUT_FILENO, buf, nread));
    }

    ec_neg1(close(pfd[0]));
    ec_neg1(waitpid(pid, NULL, 0));
    return;
EC_CLEANUP_BGN
    EC_FLUSH("fsort0");
EC_CLEANUP_END
}
