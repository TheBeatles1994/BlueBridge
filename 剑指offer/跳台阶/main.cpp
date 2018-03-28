#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<algorithm>
#include <stack>

using namespace std;

int countJump = 0;

int jumpFloor(int number) {
    if(number == 1)
    {
        return 1;
    }
    else if(number == 2)
    {
        return 2;
    }

    return (jumpFloor(number-1)+jumpFloor(number-2));
}

int main(int argc, char *argv[])
{
    int n;
    while(cin>>n)
    {
        cout << jumpFloor(n)<<endl;
    }

    return 0;
}
