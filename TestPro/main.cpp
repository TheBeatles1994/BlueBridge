#include <iostream>
#include <vector>

using namespace std;

class Base
{
public:
    virtual void Print(){cout<<"base"<<endl;}
};

class Derive:public Base
{
public:
    void Print(){cout<<"derive"<<endl;}
};

int main()
{
    Base *base = new Derive;

    base->Print();
    delete base;

    return 0;
}
