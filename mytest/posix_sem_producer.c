#include "defs.h"
#include <sys/stat.h>
#include <semaphore.h>

int main(int argc, char* argv[]) {
    sem_t *sm_sem = NULL;
    long counter = 0;
    char name[] = "/mq";

    if ((sm_sem = sem_open(name, O_CREAT, PERM_FILE, 0)) == SEM_FAILED)
        EC_FAIL

    while (true) {
        counter++;
        sem_post(sm_sem);
        printf("%ld produced\n", counter);
        sleep(1);
    }

    if (sem_unlink(name) == -1 && errno != ENOENT)
        EC_FAIL

    ec_neg1(sem_close(sm_sem));

    return EXIT_SUCCESS;

EC_CLEANUP_BGN
    if (sm_sem != NULL) sem_close(sm_sem);
    return EXIT_FAILURE;
EC_CLEANUP_END
}
