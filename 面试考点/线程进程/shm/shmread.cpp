#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

extern int errno;

#define SIZE	1

char *read_key;
int shmid;

int shared_init()
{
	//9999:This key is used to allocate a shared memory segment.
	//The IPC_CREAT flag (third parameter) suggests that a new shared memory segment has to be created, with read-write permissions (IPC_CREAT logically OR ed with 0666). 
	if((shmid = shmget(9999, SIZE, IPC_CREAT | 0666)) < 0) {
		printf("Error in shmget. errno is: %d\n", errno);
		return -1;
	}
	if((read_key = (char *)shmat(shmid, NULL, 0)) < 0) {
		printf("Error in shm attach. errno is: %d\n", errno);
		return -1;
	}
	return 0;
}

void read_char()
{
	char c;
	while(1) {
		c = getchar();
		if(c == '\n') {
			c = getchar();
		}
		strncpy(read_key, &c, SIZE);
		printf("read_key now is %s\n", read_key);
		if(isalnum(*read_key)) {
			shmdt(read_key);
			shmctl(shmid, IPC_RMID, NULL);
			exit(1);
		}
	}
}

int main()
{
	if(shared_init() < 0) {
		printf("Problems with shared memory\n");
		exit(1);
	}
	read_char();
	return 0;
}