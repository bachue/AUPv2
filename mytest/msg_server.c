#include "defs.h"
#include <sys/msg.h>

int main(void)
{
	int server = -1, i;
	ssize_t nread;
        struct {
            int client;
            char sm_data[200];
        } msg;
	char msgname[] = "/tmp/msg";
        key_t key;

	printf("server started\n");
	close(open(msgname, O_WRONLY | O_CREAT, 0));
	// will block waiting for writer
	ec_neg1(key = ftok(msgname, 1));

        if ((server = msgget(key, PERM_FILE)) != -1)
            msgctl(server, IPC_RMID, NULL);
        ec_neg1(server = msgget(key, IPC_CREAT | PERM_FILE));

	while (true) {
		ec_neg1( nread = msgrcv(server, &msg, sizeof(msg), 0, 0) )
		for (i = 0; msg.sm_data[i] != '\0'; i++)
			msg.sm_data[i] = toupper(msg.sm_data[i]);
		ec_neg1(msgsnd(msg.client, msg.sm_data, sizeof(msg.sm_data), 0))
	}
	/* never actually get here */
        msgctl(server, IPC_RMID, NULL);
        unlink(msgname);
	exit(EXIT_SUCCESS);
EC_CLEANUP_BGN
	exit(EXIT_FAILURE);
EC_CLEANUP_END
}
