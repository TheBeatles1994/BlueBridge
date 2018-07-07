#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
/*
 * 函数功能：
 * 数字序列中某一位的数字
 * 来源：《剑指offer》P225
 */
int digitAtIndex(int index)
{
    if(index<0)
        return -1;
    if(index>=0 && index<=9)
        return index;

    int begin = 0;
    int end = 9;
    int flag = 0;
    int rst;
    while(1)
    {
        if(index>end)
        {
            flag++;
            begin = end+1;
            end = end + 9*pow(10,flag)*(flag+1);
        }
        else
        {
            int number = (index-begin)/(flag+1) + pow(10,flag);
            int numberindex = (index-begin)%(flag+1);
            rst = to_string(number)[numberindex] - '0';
            break;
        }
    }

    return rst;
}
int main(int argc, char *argv[])
{
    int n;

    while(cin>>n)
    {
        cout << digitAtIndex(n)<<endl;
    }

    return 0;
}

