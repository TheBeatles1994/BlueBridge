#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <ctype.h>

int filedes[2];

void *read_char(void *id)
{
    char c;
    printf("Entering routine to read character.........\n");
    while(1) {
        /* Get a character in 'c' except '\n'. */
        c = getchar();
        if(c == '\n')
            c = getchar();
        write(filedes[1], &c, 1);
        if(isalnum(c)) {
            sleep(2);
            exit(1);
        }
    }
}

void *check_hit(void *id)
{
    char c;
    printf("Entering routine to check hit.........\n");
    while(1) {
        read(filedes[0], &c, 1);
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
    pthread_t tid1, tid2;
    pipe(filedes);
    /* Create thread for reading characters. */
    i = pthread_create(&tid1, NULL, read_char, NULL);
    /* Create thread for checking hitting of any keyboard key. */
    i = pthread_create(&tid2, NULL, check_hit, NULL);
    if(i == 0) while(1);
    return 0;
}
