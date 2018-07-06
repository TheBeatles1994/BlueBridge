/****************************** listing2.c ******************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>

extern int errno;
void *addr;
int offset;

#define TEST_FILE	"test_file"
#define HELLO_STR	"hello"
#define HELLO_STR_LEN	strlen(HELLO_STR)
#define NTHLOOP		500000

void create_test_file()
{
	int file_des;
	int count;
	creat(TEST_FILE, 0666);
	file_des = open(TEST_FILE, O_RDWR);
	if(file_des == -1) {
		printf("errno is %d\n", errno);
		exit(1);
	}
	count = write(file_des, HELLO_STR, HELLO_STR_LEN);
	if(count < 0) {
		printf("errno is %d\n", errno);
		exit(1);
	} else {
		printf("count = %d\n", count);
	}
	close(file_des);
}

void remove_test_file()
{
	unlink(TEST_FILE);
}
	

int main()
{
	int fd;
	int i;
	int j;
	char temp_buf[10];

	create_test_file();
	
	for(j=0;j < NTHLOOP; j++) {
		temp_buf[0] = '\0';
		fd = open(TEST_FILE, O_RDONLY);
		i = read(fd, temp_buf, HELLO_STR_LEN);
		if(i < 0) {
			printf("errno is %d\n", errno);
			exit(1);
		}
		temp_buf[HELLO_STR_LEN] = '\0';
		printf("%s %d\n", temp_buf, j);
		close(fd);
	}
	
	remove_test_file();

	return 0;
}


