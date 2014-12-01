#include "defs.h"
#include <sys/msg.h>

int main(int argc, char *argv[])
{
	int server = -1, client = -1, i;
	ssize_t nread;
        struct {
            long msgtype;
            int client;
            char sm_data[200];
        } msg;
	char msgname[] = "/tmp/msg";
	char *work[] = {
		"applesauce",
		"tiger",
		"mountain",
		NULL
	};
        key_t key;

        printf("client %ld started\n", (long)getpid());
        close(open(msgname, O_WRONLY | O_CREAT, 0));
        ec_neg1(key = ftok(msgname, 1));
        
        ec_neg1(server = msgget(key, 0));
        ec_neg1(client = msgget(IPC_PRIVATE, PERM_FILE));

	for (i = 0; work[i] != NULL; i++) {
                msg.client = client;
                msg.msgtype = 1;
		strcpy(msg.sm_data, work[i]);
		ec_neg1(msgsnd(server, &msg, sizeof(msg.sm_data) + sizeof(msg.client), 0))
		ec_neg1( nread = msgrcv(client, &msg, sizeof(msg.sm_data) + sizeof(msg.client), 0, 0) )
		//printf("client got %d from read\n", nread);
		if (nread == 0) {
			errno = ENETDOWN;
			EC_FAIL
		}
		printf("client %ld: %s --> %s\n", (long)getpid(),
		  work[i], msg.sm_data);
                sleep(i);
	}
        msgctl(client, IPC_RMID, NULL);
	printf("Client %ld done\n", (long)getpid());
	exit(EXIT_SUCCESS);

EC_CLEANUP_BGN
	exit(EXIT_FAILURE);
EC_CLEANUP_END
}
