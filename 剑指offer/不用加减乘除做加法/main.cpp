#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int Add(int num1, int num2)
{
    int YH;
    int Yleft;

    YH = num1 ^ num2;
    Yleft = (num1 & num2)<<1;
    num1 = YH;
    num2 = Yleft;

    while(Yleft!=0)
    {
        YH = num1 ^ num2;
        Yleft = (num1 & num2)<<1;
        num1 = YH;
        num2 = Yleft;
    }

    return YH;
}

int main(int argc, char *argv[])
{
    int n,m;

    while(cin>>n>>m)
    {
        cout<<Add(n, m)<<endl;
    }


    return 0;
}
