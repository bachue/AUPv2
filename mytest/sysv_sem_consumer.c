#include "defs.h"
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
    key_t key;
    int sm_semid = -1;
    union semun {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
    } arg;
    struct sembuf sop;
    char name[] = "/tmp/msg";
    
    close(open(name, O_WRONLY | O_CREAT, 0));
    ec_neg1(key = ftok(name, 1));
    
    if ((sm_semid = semget(key, 1, PERM_FILE | IPC_CREAT)) != -1) {
        arg.val = 0;
        ec_neg1(semctl(sm_semid, 0, SETVAL, arg));
        sop.sem_num = sop.sem_op = sop.sem_flg = 0;
        ec_neg1(semop(sm_semid, &sop, 1));
    } else {
        EC_FAIL
    }

    sop.sem_num = 0;
    sop.sem_op = -1;
    sop.sem_num = 0;

    while(true) {
        ec_neg1(semop(sm_semid, &sop, 1));
        printf("consumed\n");
    }

    ec_neg1(semctl(sm_semid, 0, IPC_RMID));
    return EXIT_SUCCESS;
EC_CLEANUP_BGN
    if (sm_semid != -1) ec_neg1(semctl(sm_semid, 0, IPC_RMID));
    return EXIT_FAILURE;
EC_CLEANUP_END
}
