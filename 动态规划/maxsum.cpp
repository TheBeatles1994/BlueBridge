#include <iostream>
#include <string>

using namespace std;

#define MAXLEN 50			//最大数字长度
#define MAX(x,y) x>y?x:y

typedef struct
{
	int sum;		//SumDP[n].sum：当以元素n结尾时的最大连续子序列的和
	int start;		//SumDP[n].start：当以元素n结尾时的最大连续子序列和的起始元素序号
}SumDP;

/*
 * 函数功能: 最长连续子序列和
 * 创建人:   TheBeatles1994
 */
int MaxSum(int num[],int n)
{
	SumDP *dp;
	int maxDp;

	dp = (SumDP *)malloc(sizeof(SumDP)*n);

	dp[0].sum = num[0];
	dp[0].start = 0;
	maxDp = dp[0].sum;
	for (int i=1;i<n;i++)
	{
		if (dp[i-1].sum+num[i]>=0 && dp[i-1].sum>=0)
		{
			dp[i].sum = dp[i-1].sum+num[i];
			dp[i].start = dp[i-1].start;
		} 
		else
		{
			dp[i].sum = num[i];
			dp[i].start = i;
		}

		if (dp[i].sum>maxDp)
		{
			maxDp = dp[i].sum;
		}
	}

	return maxDp;
}

int main()
{
	int num[MAXLEN];
	int N;

	cin>>N;

	for (int i=0;i<N;i++)
	{
		cin >>num[i];
	}

	cout << "MAXSUM:"<<MaxSum(num,N) << endl;

	system("pause");
	return 0;
}