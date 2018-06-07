#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

struct STU
{

    char ch1;
            int a;
    char ch2;

};

int main()
{
    struct STU stu;
    cout<<sizeof(stu)<<endl;
    cout<<offsetof(STU,ch1)<<endl;
    cout<<offsetof(STU,a)<<endl;
    cout<<offsetof(STU,ch2)<<endl;
    return 0;
}
