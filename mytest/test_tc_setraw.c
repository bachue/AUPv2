#include "defs.h"

int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);
    printf("Initial attributes:\n");
    system("stty | fold -s -w 60");
    printf("\r\nRaw attributes:\n");
    tc_setraw();
    system("stty | fold -s -w 60");
    tc_restore();
    printf("\r\nRestored attributes:\n");
    system("stty | fold -s -w 60");
    return 0;
}
