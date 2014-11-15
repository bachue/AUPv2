#include "defs.h"

int main(int argc, char *argv[]) {
    int c;
    setbuf(stdout, NULL);
    while (true) {
        c = tc_keystroke();
        putchar(c);
        if (c == 5) { /* ^E */
            ec_false( tc_restore() );
	    printf("\n%s\n", "Exiting...");
            exit(EXIT_SUCCESS);
        } 
    }
    return 0;
EC_CLEANUP_BGN
    EC_FLUSH("main");
    return 0;
EC_CLEANUP_END
}
