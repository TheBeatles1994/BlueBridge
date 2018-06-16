#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;、
/*
每两位存储一位数字，00表示未出现， 01表示出现一次， 10表示出现多次
*/
#if 1
#define SIZE    16
#define N       1000        //最大上限个数
#define MASK    0x0F        //掩码，用来求余数使用
#define SHIFT   4           //偏移量，用来除16使用

int num[N/SIZE +1];

/* 设置相应位为1 */
void set(int i)
{
    int temp = num[i>>SHIFT] & (3 << ((i&MASK)<<1));
    temp = temp >> ((i&MASK)<<1);

    if(temp == 0)   //为0置1
    {
        num[i>>SHIFT] |= (1 << ((i&MASK)<<1));
    }
    else            //非0置2
    {
        num[i>>SHIFT] &= ~(3 << ((i&MASK)<<1));
        num[i>>SHIFT] |= (2 << ((i&MASK)<<1));
    }
}
/* 初始化相应位为0 */
void clr(int i)
{
    num[i>>SHIFT] &= ~(3 << ((i&MASK)<<1));
}
/* 测试所在位是否为1 */
int test(int i)
{
    int temp = num[i>>SHIFT] & (3 << ((i&MASK)<<1));
    temp = temp >> ((i&MASK)<<1);

    return temp;
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
        cout<<test(in)<<endl;
    }

    return 0;
}
#else
#endif
