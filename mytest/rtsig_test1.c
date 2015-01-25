#include "defs.h"

static void handler(int signum, siginfo_t *info, void *context) {
    printf("signal number: %d\n", info->si_signo);
    printf("sending process ID: %ld\n", (long) info->si_pid);
    printf("real user ID of sending process: %ld\n", (long) info->si_uid);
    switch (info->si_code) {
    case SI_USER:
        printf("Signal from user\n");
        break;
    case SI_QUEUE:
        printf("Signal from sigqueue; value = %d\n", info->si_value.sival_int);
        break;
    case SI_TIMER:
        printf("Signal from timer expiration; value = %d\n", info->si_value.sival_int);
        break;
    case SI_ASYNCIO:
        printf("Signal from asynchronous I/O completion; value = %d\n", info->si_value.sival_int);
        break;
    case SI_MESGQ:
        printf("Signal from message arrival; value = %d\n", info->si_value.sival_int);
        break;
    default:
        printf("Other signal\n");
    }
}

int main(int argc, char  *argv[]) {
    struct sigaction act;
    union sigval val;

    memset(&act, 0, sizeof(act));
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = handler;
    ec_neg1( sigaction(SIGUSR1, &act, NULL) );
    ec_neg1( sigaction(SIGRTMIN, &act, NULL) );
    ec_neg1( kill(getpid(), SIGUSR1) );
    val.sival_int = 1234;
    ec_neg1( sigqueue(getpid(), SIGRTMIN, val) );
    exit(EXIT_SUCCESS);
EC_CLEANUP_BGN
    exit(EXIT_FAILURE);
EC_CLEANUP_END
}
