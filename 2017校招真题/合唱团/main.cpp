#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

#define MAXCOUNT 50
#define KCOUNT 10
#define MAXVALUE 6550000
#define MINVALUE -6550000

/*
 * 先只求正值
 */
long long func(int data[], int n, int k, int d)
{
    long long dpmax[MAXCOUNT+1][KCOUNT+1]={0};
    long long dpmin[MAXCOUNT+1][KCOUNT+1]={0};
    long long max, min;

    for(int i=1; i<=n;i++)                  //选择学生j：1
    {
        dpmax[i][1] = data[i];
        dpmin[i][1] = data[i];
    }

    for(int j=2;j<=k;j++)                   //选择学生j：2~k
    {
        for(int i=j;i<=n;i++)               //所有学生i：j~n
        {
            max = MINVALUE;
            min = MAXVALUE;
            for(int m=j-1;m<=i-1;m++)         //选择m：1~i-1之间的最大值和最小值
            {
                if(max<dpmax[m][j-1] && i-m<=d)
                    max = dpmax[m][j-1];
                if(min>dpmin[m][j-1] && i-m<=d)
                    min = dpmin[m][j-1];
            }
            if(data[i]>0)
            {
                dpmax[i][j] = data[i] * max;
                dpmin[i][j] = data[i] * min;
            }
            else
            {
                dpmax[i][j] = data[i] * min;
                dpmin[i][j] = data[i] * max;
            }
        }
    }
    max = MINVALUE;
    for(int i=k;i<=n;i++)
    {
        if(max<dpmax[i][k])
            max = dpmax[i][k];
    }

    return max;
}

int main(int argc, char *argv[])
{
    int n, k, d;
    int data[MAXCOUNT + 1];

    cin>>n;
    for(int i=1; i<=n;i++)
        cin >> data[i];
    cin >> k>>d;
    cout << func(data, n, k, d) <<endl;

    return 0;
}

