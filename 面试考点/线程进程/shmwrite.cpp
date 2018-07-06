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

char *detect_key;
int shmid;

int shared_init()
{
	//注意此处是0444，即表明不会创建新的共享内存块,0444指只读
	if((shmid = shmget(9999, SIZE, 0444)) < 0) {
		printf("Error in shmget. errno is: %d\n", errno);
		return -1;
	}
	if((detect_key = (char *)shmat(shmid, NULL, SHM_RDONLY)) < 0) {
		printf("Error in shm attach. errno is: %d\n", errno);
		return -1;
	}
//	detect_key = NULL;
	return 0;
}

void detect_hit()
{
	char c;
	c = *detect_key;
	while(1) {
		if(c != *detect_key) {
			if(isalnum(detect_key[0])) {
				printf("detect_key is %s\n", detect_key);
				shmdt(detect_key);
				shmctl(shmid, IPC_RMID, NULL);
				exit(1);
			} else {
				printf("detect_key is %s\n", detect_key);
			}
			c = *detect_key;
		}
	}
}

int main()
{
	if(shared_init() < 0) {
		printf("Problems with shared memory\n");
		exit(1);
	}
	detect_hit();
	return 0;
}
