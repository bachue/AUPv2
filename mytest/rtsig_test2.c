#include "defs.h"
#include <pthread.h>

#define MYSIG_COUNT SIGRTMIN
#define MYSIG_STOP SIGRTMIN + 1

static void *sig_thread(void *arg) {
    int signum;
    siginfo_t info;

    do {
        signum = sigwaitinfo((sigset_t *) arg, &info);
        if (signum == MYSIG_COUNT) {
            printf("Got MYSIG_COUNT; value: %s\n", (char *) info.si_value.sival_ptr);
        } else if (signum == MYSIG_STOP) {
            printf("Got MYSIG_STOP; terminating thread\n");
            return (void *) true;
        } else {
            printf("Got %d\n", signum);
        }
    } while(signum != 1 || errno == EINTR);
    EC_FAIL

EC_CLEANUP_BGN
    EC_FLUSH("sig_thread");
    return (void *) false;
EC_CLEANUP_END
}

static void dummy_handler(int signum, siginfo_t *info, void *context) {
}

int main(int argc, char  *argv[]) {
    sigset_t set;
    struct sigaction act;
    union sigval value;
    pthread_t tid;

    ec_neg1( sigemptyset(&set) );
    ec_neg1( sigaddset(&set, MYSIG_COUNT) );
    ec_neg1( sigaddset(&set, MYSIG_STOP) );
    ec_rv( pthread_sigmask(SIG_SETMASK, &set, NULL) );
    memset(&act, 0, sizeof(act));
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = dummy_handler;
    ec_neg1( sigaction(MYSIG_COUNT, &act, NULL) );
    ec_neg1( sigaction(MYSIG_STOP, &act, NULL) );
    value.sival_ptr = "One";
    ec_neg1( sigqueue(getpid(), MYSIG_COUNT, value) );
    value.sival_ptr = "Two";
    ec_neg1( sigqueue(getpid(), MYSIG_COUNT, value) );
    value.sival_ptr = "Three";
    ec_neg1( sigqueue(getpid(), MYSIG_COUNT, value) );
    value.sival_ptr = NULL;
    ec_neg1( sigqueue(getpid(), MYSIG_STOP, value) );
    ec_rv( pthread_create(&tid, NULL, sig_thread, &set) );
    ec_rv( pthread_join(tid, NULL) );

    exit(EXIT_SUCCESS);
EC_CLEANUP_BGN
    exit(EXIT_FAILURE);
EC_CLEANUP_END
}
