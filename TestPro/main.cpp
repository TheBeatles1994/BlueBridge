#include<iostream>

using namespace std;

int rectCover(int number) {
    int num[1000]={0};

    num[1]=1;
    num[2]=2;

    for(int i=3;i<=number;i++)
    {
        num[i]=num[i-1]+num[i-2];
    }

    return num[number];
}

int main(int argc, char *argv[])
{
    int n;

    while(cin>>n)
    {
        cout<<rectCover(n)<<endl;
    }

    return 0;
}

