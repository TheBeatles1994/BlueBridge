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
    string str;
    int count=0;

    for(int i=1;i<=n;i++)
    {
        str = to_string(i);
        for(int j=0;j<str.length();j++)
        {
            if(str[j] == '1')
                count++;
        }
    }

    return count;
}

int main(int argc, char *argv[])
{
    int n;

    cin>>n;
    cout << NumberOf1Between1AndN_Solution(n)<<endl;

    return 0;
}

