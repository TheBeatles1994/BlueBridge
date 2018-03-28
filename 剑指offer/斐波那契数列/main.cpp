#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<algorithm>
#include <stack>

using namespace std;

int Fibonacci(int n) {
    int a = 1;
    int b = 1;
    int sum;

    if(n==0)
        return 0;
    if(n==1||n==2)
        return 1;
    for(int i=3;i<=n;i++)
    {
        sum = a+b;
        a=b;
        b=sum;
    }
    return sum;
}

int main(int argc, char *argv[])
{
    int n;
    while(cin>>n)
    {
        cout << Fibonacci(n)<<endl;
    }

    return 0;
}
