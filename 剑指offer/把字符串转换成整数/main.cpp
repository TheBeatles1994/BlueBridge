#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int StrToInt(string str)
{
    int rst=0;
    bool isABS=true;

    for(auto it:str)
    {
        if((ispunct(it) && it!='+' && it!='-') || isalpha(it))
            return 0;
        if(it == '-')
            isABS = false;
        else if(it == '+')
            isABS = true;
        else
            rst = 10*rst + it-48;
    }

    return (isABS ? (rst):(-rst));
}

int main(int argc, char *argv[])
{
    string str;

    while(cin>>str)
    {
        cout<<StrToInt(str)<<endl;
    }


    return 0;
}
