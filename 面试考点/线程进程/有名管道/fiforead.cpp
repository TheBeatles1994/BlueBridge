#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

extern int errno;

void *check_hit(void *id)
{
	char c;
	int fd;
	int i;
	printf("Entering routine to check hit.........\n");
	while(1) {
		fd = open("fifo", O_RDONLY);
		if(fd < 0) {
			printf("Error opening in fifo\n");
			printf("errno is %d\n", errno);
			continue;
		}
		i = read(fd, &c, 1);
		if(i < 0) {
			printf("Error reading fifo\n");
			printf("errno is %d\n", errno);
		}
		if(isalnum(c)) {
			printf("The key hit is %c\n", c);
			exit(1);
		} else {
			printf("key hit is %c\n", c);
		}
	}
}
		
int main()
{
	int i;
	i = mkfifo("fifo", 0666);
	if(i < 0) {
		printf("Problems creating the fifo\n");
		if(errno == EEXIST) {
			printf("fifo already exists\n");
		}
		printf("errno is set as %d\n", errno);
	}
	pthread_t tid2;
	i = pthread_create(&tid2, NULL, check_hit, NULL);
	if(i == 0) while(1);
	return 0;
}