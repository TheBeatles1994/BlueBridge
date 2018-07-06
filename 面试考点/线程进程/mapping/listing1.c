/****************************** listing1.c ******************************/

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
    FILE *fptr;

    create_test_file();

    fptr = fopen(TEST_FILE, "r");
    if (fptr == NULL) {
        printf("Error in opening file. errno is %d\n", errno);
        exit(1);
    }

    fd = fileno(fptr);

    fseek(fptr, 0, SEEK_END);
    offset = ftell(fptr);

    printf("offset is = %d\n", offset);

    addr = mmap(0, offset, PROT_READ, MAP_SHARED, fd, 0);
    if(addr == MAP_FAILED)
    {
        printf("mmap error\n");
        exit(1);
    }
    for(j=0;j < NTHLOOP; j++) {
        i = 0;
        while(i < offset){
            putchar(*((char *)addr + i));
            i++;
        }
        printf(" %d\n",j);
    }

    fclose(fptr);
    remove_test_file();

    return 0;
}
