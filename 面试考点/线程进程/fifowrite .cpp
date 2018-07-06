#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

extern int errno;

void *read_char(void *id)
{
    char c;
    int fd;
    printf("Entering routine to read character.........\n");
    while(1) {
        c = getchar();
        fd = open("fifo", O_WRONLY);
        if(c == '\n')
            c = getchar();
        write(fd, &c, 1);
        if(isalnum(c)) {
            exit(1);
        }
        close(fd);
    }
}

int main()
{
    int i;
    pthread_t tid1;
    i = mkfifo("fifo", 0666);
    if(i < 0) {
        printf("Problems creating the fifo\n");
        if(errno == EEXIST) {
            printf("fifo already exists\n");
        }
        printf("errno is set as %d\n", errno);
    }
    i = pthread_create(&tid1, NULL, read_char, NULL);
    if(i == 0) while(1);
    return 0;
}
