#include "defs.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

static int* getaddr(void) {
    key_t key;
    int shmid, *p;

    close(open("/tmp/shmseg", O_WRONLY | O_CREAT, 0));
    ec_neg1(key = ftok("/tmp/shmseg", 1));
    ec_neg1(shmid = shmget(key, sizeof(int), IPC_CREAT | PERM_FILE));
    ec_neg1(p = shmat(shmid, NULL, 0));
    return p;
EC_CLEANUP_BGN
    return NULL;
EC_CLEANUP_END
}

int main(int argc, char  *argv[]) {
    pid_t pid;

    if ((pid = fork()) == 0) {
        int *p, prev = 0;

        ec_null(p = getaddr());

        while (*p != 99) {
            if (prev != *p) {
                printf("child saw %d\n", *p);
                prev = *p;
            }
        }
        printf("child is done\n");
    } else {
        int *p;

        ec_null(p = getaddr());
        for (*p = 1; *p < 4; (*p)++) {
            sleep(1);
        }
        *p = 99;
    }

    exit(EXIT_SUCCESS);
EC_CLEANUP_BGN
    exit(EXIT_FAILURE);
EC_CLEANUP_END
}
