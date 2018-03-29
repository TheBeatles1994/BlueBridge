#include<iostream>

using namespace std;

int NumberOf1(int n) {
    int count=0;
    int offset=1;

    while(offset!=0)
    {
        if((n&offset) == offset)
            count++;

        offset<<=1;

        //cout << hex<<offset<<endl;
    }

    return count;
}

int main(int argc, char *argv[])
{
    int n;

    while(cin>>n)
    {
        cout<<NumberOf1(n)<<endl;
    }

    return 0;
}

