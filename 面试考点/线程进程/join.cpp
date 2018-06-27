#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

#define NUM_THREADS 5

void *wait(void *t) {
    int i;
    long tid;

    tid = (long)t;

    sleep(1);
    pthread_mutex_lock(&lock);
    cout << "Sleeping in thread " << endl;
    cout << "Thread with id : " << tid << "  ...exiting " << endl;
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main () {
    int rc;
    int i;
    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;
    void *status;

    // Initialize and set thread joinable
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for( i = 0; i < NUM_THREADS; i++ ) {
        cout << "main() : creating thread, " << i << endl;
        rc = pthread_create(&threads[i], &attr, wait, (void *)i );

        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }

    // free attribute and wait for the other threads
    pthread_attr_destroy(&attr);
    for( i = 0; i < NUM_THREADS; i++ ) {
        //The pthread_join() subroutine blocks the calling thread(main thread) until the specified threadid thread terminates.
        rc = pthread_join(threads[i], &status);
        if (rc) {
            cout << "Error:unable to join," << rc << endl;
            exit(-1);
        }
        pthread_mutex_lock(&lock);
        cout << "Main: completed thread id :" << i ;
        cout << "  exiting with status :" << status << endl;
        pthread_mutex_unlock(&lock);
    }

    cout << "Main: program exiting." << endl;
    pthread_exit(NULL);
}

/* 输出 */
/*
    main() : creating thread, 0
    main() : creating thread, 1
    main() : creating thread, 2
    main() : creating thread, 3
    main() : creating thread, 4
    Sleeping in thread
    Thread with id : 0 .... exiting
    Sleeping in thread
    Thread with id : 1 .... exiting
    Sleeping in thread
    Thread with id : 2 .... exiting
    Sleeping in thread
    Thread with id : 3 .... exiting
    Sleeping in thread
    Thread with id : 4 .... exiting
    Main: completed thread id :0  exiting with status :0
    Main: completed thread id :1  exiting with status :0
    Main: completed thread id :2  exiting with status :0
    Main: completed thread id :3  exiting with status :0
    Main: completed thread id :4  exiting with status :0
    Main: program exiting.
*/
