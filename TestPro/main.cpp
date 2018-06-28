#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>

using namespace std;

class parent
{
public:
    parent(int a):num(a){}
    int getnum(){return num;}
private:
    int num;
};

class child:public parent
{
public:
    child(int a):parent(a){}

};

int main()
{
    child *p = NULL;

    parent myparent(4);
    child mychild(8);

    p = &myparent;

    cout<<p->getnum()<<endl;

    p = &mychild;
    cout<<p->getnum()<<endl;


    return 0;
}
