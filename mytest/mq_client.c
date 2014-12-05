#include "defs.h"
#include <mqueue.h>

int main(int argc, char *argv[]) {
    int i;
	mqd_t server = (mqd_t) -1, client = (mqd_t) -1;
	ssize_t nread;
    struct {
        pid_t client_pid;
        char sm_data[200];
    } msg;
    char mqname_server[] = "/mq", mqname_client[100] = "";
    struct mq_attr attr = {0};

    attr.mq_maxmsg = 10;
    attr.mq_msgsize = sizeof(msg);

    char *work[] = {
    	"applesauce",
    	"tiger",
    	"mountain",
    	NULL
    };

    printf("client %ld started\n", (long)getpid());
    snprintf(mqname_client, 100, "/mq_%ld", (long) getpid());

    ec_neg1(server = mq_open(mqname_server, O_WRONLY));
    ec_neg1(client = mq_open(mqname_client, O_RDONLY | O_CREAT, PERM_FILE, &attr));

    for (i = 0; work[i] != NULL; i++) {
        msg.client_pid = getpid();
        snprintf(msg.sm_data, 200, "%ld ", (long) msg.client_pid);
	strncat(msg.sm_data, work[i], 200 - 1);
	ec_neg1(mq_send(server, (const char *) &msg, sizeof(msg), 0));
	ec_neg1(nread = mq_receive(client, (char *) &msg, sizeof(msg), NULL));
	printf("client %ld: %s --> %s\n", (long) getpid(), work[i], msg.sm_data);
        sleep(i);
    }
    mq_close(server);
    mq_unlink(mqname_client);
    exit(EXIT_SUCCESS);

EC_CLEANUP_BGN
    exit(EXIT_FAILURE);
EC_CLEANUP_END
}
