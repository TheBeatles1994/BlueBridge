#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>

using namespace std;

struct test
{
    double data;
    char data1;
    int data2;
};

int main()
{
    short myshort;

    cout<<sizeof(myshort)<<endl;

    struct test mytest;

    cout<<sizeof(mytest)<<endl;


    return 0;
}
