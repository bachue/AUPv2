#include "defs.h"

#define LOCKDIR "/tmp/"
#define MAXTRIES 10
#define NAPLENGTH 1
#define LOCKPERM (S_IRUSR | S_IRGRP | S_IROTH)

static char* lockpath(char *name);
bool lock(char* name);
bool unlock(char* name);
void testlock();

int main() {
    testlock();
}

static char* lockpath(char *name) {
    static char path[100];
    if (snprintf(path, sizeof(path), "%s%s", LOCKDIR, name) > sizeof(path)) {
        return NULL;
    }
    return path;
}

bool lock(char* name) {
    char *path;
    char login[100];
    int fd, tries;
    ec_null(path = lockpath(name))
    tries = 0;
    while ((fd = open(path, O_WRONLY | O_CREAT | O_EXCL, LOCKPERM)) == -1 && errno == EEXIST) {
        if (++tries >= MAXTRIES) {
            errno = EAGAIN;
            EC_FAIL
        }
        ec_neg1( fd = open(path, O_RDONLY) );
        ec_neg1( read(fd, login, sizeof(login)) );
        ec_neg1( close(fd) );
        fprintf(stderr, "ERROR: file has locked by %s\n", login);
        sleep(NAPLENGTH);
    }
    if (fd == -1) EC_FAIL

    getlogin_r(login, sizeof(login));
    write(fd, login, strlen(login));

    ec_neg1(close(fd))
    return true;
EC_CLEANUP_BGN
    return false;
EC_CLEANUP_END
}

bool unlock(char *name) {
    char *path;
    ec_null(path = lockpath(name))
    ec_neg1(unlink(path))
    return true;
EC_CLEANUP_BGN
    return false;
EC_CLEANUP_END
}

void testlock() {
    int i;
    for (i = 1; i <= 4; i++) {
        if(lock("accounts")) {
            printf("Process %ld got the lock\n", (long) getpid());
            sleep(rand() % 2 + 3);
            ec_false(unlock("accounts"));
            printf("Process %ld removed the lock\n", (long) getpid());
        } else {
            if (errno = EAGAIN) {
                printf("Process %ld tired of waiting\n", (long) getpid());
                ec_reinit();
            } else {
                EC_FAIL
            }
        }
        sleep(rand() % 5);
    }
    return;
EC_CLEANUP_BGN
    EC_FLUSH("testlock");
EC_CLEANUP_END
}
