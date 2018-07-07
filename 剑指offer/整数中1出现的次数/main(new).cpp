#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
/*
 * 函数功能：
 * 整数中1出现的次数
 */
int NumberOf1Between1AndN_Solution(int n)
{
    string str = to_string(n);
    if(str.length() == 1)
    {
        if(str[0] != '0')
            return 1;
        else
            return 0;
    }

    int count = 0;
    /* 根据最高位不同处理方式略有不同 */
    if(str[0] == '1')
    {
        count += stoi(str.substr(1)) + 1 + NumberOf1Between1AndN_Solution(stoi(str.substr(1)));
        count += NumberOf1Between1AndN_Solution(((int)pow(10,str.length()-1)-1));
    }
    else
    {
        count += (int)pow(10, str.length()-1);
        count += (str[0] - '0') * (str.length()-1) * (int)pow(10, str.length()-2);
        count += NumberOf1Between1AndN_Solution(stoi(str.substr(1)));
    }

    return count;
}

int main(int argc, char *argv[])
{
    int n;

    while(cin>>n)
    {
        cout << NumberOf1Between1AndN_Solution(n)<<endl;
    }

    return 0;
}

