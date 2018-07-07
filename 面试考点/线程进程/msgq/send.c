/***************** send.c *****************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>

#define NMSGS	5

extern int errno;

struct msgbuf {
	long mtype;
	char mtext[100];
};

int main()
{
	int msgid;
	int i, nloop;
	struct msgbuf msgp;

	char tmp_msg[100];
	
	tmp_msg[0] = '\0';

	msgid = msgget(9999, IPC_CREAT | 0666);
	if(msgid < 0) {
		printf("%d : Error number is %d\n", __LINE__, errno);
		exit(1);
	}

	for(nloop=0;nloop<NMSGS;nloop++) {
		msgp.mtype = 1;
		fgets(tmp_msg, 100, stdin);
		strncpy(msgp.mtext, tmp_msg, strlen(tmp_msg));
		i = msgsnd(msgid, &msgp, strlen(tmp_msg), IPC_NOWAIT);
		if(i < 0) {
			printf("%d : Error number is %d\n", __LINE__, errno);
			exit(1);
		}
		tmp_msg[0] = '\0';
	}
	return 0;
}


