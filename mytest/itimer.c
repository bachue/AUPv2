#include "defs.h"
#include <sys/time.h>

int main(int argc, char  *argv[]) {
    int signum;
    sigset_t set;
    struct itimerval itv;

    ec_neg1( sigemptyset(&set) );
    ec_neg1( sigaddset(&set, SIGALRM) );
    ec_neg1( sigaddset(&set, SIGINT) );
    ec_neg1( sigprocmask(SIG_BLOCK, &set, NULL) );

    itv.it_interval.tv_sec = 3;
    itv.it_interval.tv_usec = 250000;
    itv.it_value.tv_sec = 0;
    itv.it_value.tv_usec = 500000;
    ec_neg1(setitimer(ITIMER_REAL, &itv, NULL));
    printf("Waiting for timer\n");

    while( sigwait(&set, &signum) != -1 )  {
        printf("received signal %d\n", signum);
        printf("alarm(0) returns %d\n", alarm(0));
    }

    fprintf(stderr, "sigwait returns error\n");
    ec_neg1( sigprocmask(SIG_UNBLOCK, &set, NULL) );

    exit(EXIT_SUCCESS);
EC_CLEANUP_BGN
    exit(EXIT_FAILURE);
EC_CLEANUP_END
}
