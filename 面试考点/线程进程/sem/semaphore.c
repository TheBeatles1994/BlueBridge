#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <ctype.h>

#define NUM	1

#define SEMAPHORE_KEY	2004

extern int errno;

int semid;
struct sembuf lock_sem_var = {0, -1, IPC_NOWAIT};
struct sembuf ulock_sem_var = {0, 1, IPC_NOWAIT};

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
    struct seminfo *__buf;
};

void init_semaphore()
{
    if((semid = semget(SEMAPHORE_KEY, NUM,
                    IPC_CREAT | 0666)) < 0) {
        printf("semget error: errno is %d\n", errno);
        exit(1);
    }
}

void set_sem_val()
{
    union semun semopts;
    semopts.val = 1;
    semctl(semid, 0, SETVAL, semopts);
}

int semaphore_lock(int flag)
{
    lock_sem_var.sem_num = flag;
    if(semop(semid, &lock_sem_var, 1) == -1)
    {
        return -1;
    }
    return 0;
}

int semaphore_unlock(int flag)
{
    ulock_sem_var.sem_num = flag;
    if(semop(semid, &ulock_sem_var, 1) == -1) {
        printf("unlock error. errno is %d flag is %d\n", errno, flag);
        return -1;
    }
    return 0;
}

void remove_semaphore()
{
    semctl(semid, 0, IPC_RMID);
}

void critical_resource()
{
    char c;
    printf("request from %d\n", getpid());
    while(1) {
        c = getchar();
        if(c != '\n')
            break;
    }
    if(isdigit(c) != 0) {
        printf("found a number. Press CTL + C to exit\n");
        while(1) {}
    }
}

void process_for_write()
{
    int i;
    while(1) {
        i = semaphore_lock(0);
        if(i == 0) {
            printf("resource locked.......\n");
            critical_resource();
            semaphore_unlock(0);
            printf("resource unlocked.......\n");
        }
        sleep(1); /* Donot comment this. */
    }
}

void process_exit(int test)
{
    remove_semaphore();
    exit(1);
}

void init_process_one()
{
    if(fork() == 0) {
        printf("pid is %d\n", getpid());
        signal(SIGINT, process_exit);
        process_for_write();
        while(1);
    }
}

void init_process_two()
{
    if(fork() == 0) {
        printf("pid is %d\n", getpid());
        signal(SIGINT, process_exit);
        process_for_write();
        while(1);
    }
}

int main()
{
    signal(SIGINT, SIG_DFL);
    signal(SIGINT, process_exit);   //將退出信号与process_exit函数绑定
    init_semaphore();
    set_sem_val();
    init_process_one();
    init_process_two();
    while(1);
    return 0;
}


