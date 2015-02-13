#include "defs.h"
#include <sys/time.h>

int main(int argc, char  *argv[]) {
    struct timespec ts;
    time_t tm;

    ec_neg1( time(&tm) );
    printf("time() Time: %ld secs.\n", (long) tm);
    printf("CLOCK_REALTIME:\n");
    ec_neg1( clock_gettime(CLOCK_REALTIME, &ts) );
    printf("Time: %ld.%09ld secs.\n", (long) ts.tv_sec, (long) ts.tv_nsec);
    ec_neg1( clock_getres(CLOCK_REALTIME, &ts) );
    printf("Time: %ld.%09ld secs.\n", (long) ts.tv_sec, (long) ts.tv_nsec);

    exit(EXIT_SUCCESS);
EC_CLEANUP_BGN
    EC_FLUSH("clocks");
    exit(EXIT_FAILURE);
EC_CLEANUP_END
}
