#include <iostream>
#include <thread>
#include <exception>
using namespace std;

bool doNot = 1; // this bool will prevent func1 and func2 from doing their tasks
thread* fn1; // pointer to t1 thread (defined in main function)
thread* fn2; // pointer to t2 thread (defined in main function)
void func1(bool x)
{
    while(doNot) {;} // waiting for changing doNot to false (doing it in main function)
    ::fn2->join(); // trying to cause deadlock
}

void func2(bool x)
{
    while(doNot) {;} // waiting for changing doNot to false (doing it in main function)
    ::fn1->join(); // trying to cause deadlock
}


int main()
{
    // entire code of main() in 'try'
    try
    {
        thread t1(func1, 1);
        thread t2(func2, 1);
        ::fn1 = &t1;
        ::fn2 = &t2;
        ::doNot = 0;
        t1.join();
        t2.join();
        cout << "Hello!";
    }
    catch(exception& e) // catching it. You can type 'std::system_error& e', according to the code's output
    {
        e.what();
        // ...
        cout<<"error"<<endl;
    }
    return 0;
}
