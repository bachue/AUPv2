#include "defs.h"

int main() {
    char str[] = "Hello Word\n";
    ec_neg1( write(STDOUT_FILENO, str, sizeof(str)) );

    return 0;
EC_CLEANUP_BGN
	EC_FLUSH("main");
EC_CLEANUP_END
    return 0;
}
