#include "defs.h"

int main(int argc, char const *argv[]) {
    int i, fd, pid;
    char str[10];
    char *path = "/tmp/test";

    ec_neg1(fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR));

    for (i = 0; i < 10; ++i) {
        pid = fork();
        if (pid == 0) {
            snprintf(str, sizeof(str), "%d\n", getpid());
            for (i = 0; i < 100; ++i) {
                ec_neg1( lseek(fd, 0, SEEK_END) );
                ec_neg1( write(fd, str, strlen(str)) );
            }
            exit(0);
        }
    }

    return 0;
EC_CLEANUP_BGN
    return -1;
EC_CLEANUP_END
}
