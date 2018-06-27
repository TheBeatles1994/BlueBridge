#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int done = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void thread_exit()
{
    pthread_mutex_lock(&mutex);

    done = 1;
    //pthread_cond_signal函数的作用是发送一个信号给另外一个正在处于阻塞等待状态的线程,使其脱离阻塞状态,继续执行.如果没有线程处在阻塞等待状态,pthread_cond_signal也会成功返回。
    pthread_cond_signal(&cond);
    //释放锁，使得pthread_cond_wait可以正常运行
    pthread_mutex_unlock(&mutex);
}

void *child(void *args)
{
    printf("child\n");

    thread_exit();

    return NULL;
}

void thread_join()
{
    //先于child线程，把mutex拿到，并上锁
    pthread_mutex_lock(&mutex);
    /*pthread_cond_wait()函数一进入wait状态就会自动release mutex。
     * 当其他线程通过pthread_cond_signal()或pthread_cond_broadcast，把该线程唤醒，使pthread_cond_wait()通过（返回）时，该线程又自动获得该mutex。*/
    while(done == 0)
        pthread_cond_wait(&cond, &mutex);
    //上面的pthread_cond_wait被唤醒线程后，mutex又重新上锁，故此处必须重新解锁
    pthread_mutex_unlock(&mutex);
}

int main()
{
    pthread_t p;

    printf("parent begin\n");

    pthread_create(&p, NULL, child, NULL);

    thread_join();

    printf("parend end\n");

    pthread_join(p, NULL);

    return 0;
}
