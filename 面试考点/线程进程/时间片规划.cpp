#include<iostream>
#include<algorithm>
#include<vector>
#include<pthread.h>
#include<unistd.h>

using namespace std;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void myprint(int n)
{
    pthread_mutex_lock(&lock);
    printf("%d\n", n);
    pthread_mutex_unlock(&lock);
}

void* newthread1(void *)
{
    while(1)
    {
        myprint(1);
        sleep(3);
    }
}

void* newthread2(void *)
{
    while(1)
    {
        myprint(2);
        sleep(3);
    }
}

void* newthread3(void *)
{
    while(1)
    {
        myprint(3);
        sleep(3);
    }
}

int main(int argc, char *argv[])
{
    pthread_t mythread[3];
    void *status;

    pthread_create(&mythread[0], NULL, newthread1, NULL);
    sleep(1);
    pthread_create(&mythread[1], NULL, newthread2, NULL);
    sleep(1);
    pthread_create(&mythread[2], NULL, newthread3, NULL);

    pthread_join(mythread[0], &status);
    pthread_join(mythread[1], &status);
    pthread_join(mythread[2], &status);

    return 0;
}

