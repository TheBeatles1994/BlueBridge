#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <iostream>

//pthread中的p是指POSIX。
//POSIX：可移植操作系统接口（Portable Operating System Interface of UNIX）
//为一个POSIX兼容的操作系统编写的程序，应该可以在任何其它的POSIX操作系统（即使是来自另一个厂商）上编译执行。
using namespace std;

#define NUM_THREADS 5

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;       //用来保证每次cout只能被一个线程使用

void myPrint(int id)
{
    //特别注意此处lock需要提供指针
    pthread_mutex_lock(&lock);
    cout << "Hello World! Thread ID, " << id << endl;
    pthread_mutex_unlock(&lock);
}

void mainPrint(int id)
{
    //特别注意此处lock需要提供指针
    pthread_mutex_lock(&lock);
    cout << "main() : creating thread, " << id << endl;
    pthread_mutex_unlock(&lock);
}

void *PrintHello(void *threadid) {
    long tid;
    tid = (long)threadid;
    myPrint(tid);
    //pthread_exit函数用来显式地退出一个线程。 通常，pthread_exit()例程在线程完成其工作并且不再需要存在之后调用。
    pthread_exit(NULL);
}

int main ()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    int i;

    for( i = 0; i < NUM_THREADS; i++ ) {
        rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);
        mainPrint(i);
        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    //如果main()在它创建的线程之前完成，并且使用pthread_exit()退出，其他线程将继续执行。 否则，当main()完成时它们将自动终止。
    pthread_exit(NULL);
}
