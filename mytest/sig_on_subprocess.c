#include "defs.h"
#include <sys/prctl.h>

int main(int argc, char  *argv[]) {
    int child_pid, signum;
    sigset_t set;

    switch (child_pid = fork()) {
    case 0:
        ec_neg1( sigfillset(&set) );
        ec_neg1( sigprocmask(SIG_SETMASK, &set, NULL) );

        for (;;) {
            ec_neg1( sigwait(&set, &signum) );
            printf("%d (from %d) receives sig %d\n", getpid(), getppid(), signum);
        }

        ec_neg1( sigemptyset(&set) );
        ec_neg1( sigprocmask(SIG_SETMASK, &set, NULL) );
        sleep(1000);
        break;
    case -1:
        EC_FAIL
    default:
        printf("Will sacrifice, current pid: %d, child pid: %d\n", getpid(), child_pid);
        sleep(10);
    }

    exit(EXIT_SUCCESS);
EC_CLEANUP_BGN
    exit(EXIT_FAILURE);
EC_CLEANUP_END
}
