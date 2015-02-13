#include "defs.h"

int main(int argc, char  *argv[]) {
    int signum;
    sigset_t set;

    ec_neg1( sigemptyset(&set) );
    ec_neg1( sigaddset(&set, SIGALRM) );
    ec_neg1( sigaddset(&set, SIGINT) );
    ec_neg1( sigprocmask(SIG_BLOCK, &set, NULL) );

    alarm(5);
    printf("Waiting for alarm\n");

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
