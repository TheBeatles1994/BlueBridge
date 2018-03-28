#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<algorithm>
#include <stack>

using namespace std;

int jumpFloorII(int number) {
    vector<int> num(number+1,0);
    num[0]=1;
    num[1]=1;
    num[2]=2;

    for(int i=3;i<=number;i++)
    {
        for(int j=1;j<=i;j++)
        {
            num[i]+=num[i-j];
        }
    }
    return num[number];
}

int main(int argc, char *argv[])
{
    int n;
    while(cin>>n)
    {
        cout << jumpFloorII(n)<<endl;
    }

    return 0;
}
