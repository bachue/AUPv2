#include "defs.h"
#include <mqueue.h>

int main(void)
{
    int i;
    mqd_t server = (mqd_t) -1;
    ssize_t nread;
    struct {
        pid_t client_pid;
        char sm_data[200];
    } msg;
    char mqname_server[] = "/mq", mqname_client[100] = "";
    struct mq_attr attr = {0};

    printf("server started\n");

    attr.mq_maxmsg = 10;
    attr.mq_msgsize = sizeof(msg);

    mq_unlink(mqname_server);
    ec_cmp(errno, ENOSYS);

    ec_neg1(server = mq_open(mqname_server, O_RDONLY | O_CREAT, PERM_FILE, &attr));

    while (true) {
        mqd_t client;
        ec_neg1(nread = mq_receive(server, (char *) &msg, sizeof(msg), NULL))
        snprintf(mqname_client, 100, "/mq_%ld", (long) msg.client_pid);
        ec_neg1(client = mq_open(mqname_client, O_WRONLY));
        for (i = 0; msg.sm_data[i] != '\0'; i++)
            msg.sm_data[i] = toupper(msg.sm_data[i]);
        ec_neg1(mq_send(client, (const char *) &msg, sizeof(msg), 0))
    }

    mq_close(server);
    mq_unlink(mqname_server);
    exit(EXIT_SUCCESS);
EC_CLEANUP_BGN
    exit(EXIT_FAILURE);
EC_CLEANUP_END
}
