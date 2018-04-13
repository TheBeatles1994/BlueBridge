#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
#if 1
#define SIZE    32
#define N       10000000    //最大上限个数
#define MASK    0x1F        //掩码，用来求余数使用
#define SHIFT   5           //偏移量，用来除32使用

int num[N/SIZE +1];

/* 设置相应位为1 */
void set(int i)
{
    num[i>>SHIFT] |= (1 << (i&MASK));
}
/* 初始化相应位为0 */
void clr(int i)
{
    num[i>>SHIFT] &= ~(1 << (i&MASK));
}
/* 测试所在位是否为1 */
int test(int i)
{
    return (num[i>>SHIFT] & (1<<(i & MASK)));
}
int main()
{
    int in;

    for(int i=0;i<N;i++)
    {
        clr(i);
    }

    while(cin>>in)
    {
        if(in!=-1)
        {
            set(in);
        }
        else
            break;
    }

    while(cin>>in)
    {
        if(test(in))
            cout<<in<<endl;
    }

    return 0;
}
#else
#endif
