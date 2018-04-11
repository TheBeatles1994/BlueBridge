#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
/*
 * 函数功能：
 * 第一个只出现一次的字符
 */
int FirstNotRepeatingChar(const string &str) {
    if(str.empty())
        return -1;

    for(int i=0;i<str.length()-1;i++)
    {
        if(str.find(str[i])==str.rfind(str[i]))
            return i;
    }

    return -1;
}

int main(int argc, char *argv[])
{
    string str;

    while(cin>>str)
    {
        cout << FirstNotRepeatingChar(str)<<endl;
    }

    return 0;
}

