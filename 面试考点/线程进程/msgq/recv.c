/***************** recv.c *****************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>


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

	msgid = msgget(9999, 0444);
	if(msgid < 0) {
		printf("%d : Error number is %d\n", __LINE__, errno);
		exit(1);
	}

	//for(nloop=0;nloop<5;nloop++) {
	while(1){
		bzero(msgp.mtext, 100);
		i = msgrcv(msgid, &msgp, 100, 1, IPC_NOWAIT);
		if(i < 0) {
			continue;
			printf("%d : Error number is %d\n", __LINE__, errno);
			exit(1);
		}

		msgp.mtext[strlen(msgp.mtext)] = '\0';

		fwrite(msgp.mtext, sizeof(char), strlen(msgp.mtext), stdout);
		printf("message is: %s\n", msgp.mtext);
	}

	// if(msgctl(msgid, IPC_RMID, NULL) < 0) {
	// 	printf("%d : Error number is %d\n", __LINE__, errno);
	// 	exit(1);
	// }

	return 0;
}


