#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int algo(int n)
{
    if(n==0)
        return 0;

    int rst=n;
    rst += algo(n-1);
    return rst;
}

int Sum_Solution(int n) {

    return algo(n);
}

int main(int argc, char *argv[])
{
    int n;

    while(cin>>n)
    {
        cout <<Sum_Solution(n)<<endl;
    }


    return 0;
}
