#include <iostream>
#include <string>

using namespace std;

#define MAXLEN 50			//最大数字长度
#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x<y?x:y)

/*
 * 函数功能: 最长连续子序列积
 * 创建人:   TheBeatles1994
 */
int MaxMulti(int num[],int n)
{
	int *dp;
	int maxDp;
	int max,min;

	dp = (int *)malloc(sizeof(int)*n);
	max = num[0];
	min = num[0];
	maxDp = max;

	for (int i=1;i<n;i++)
	{
		int maxtemp = max;
		int mintemp = min;
		/* 将下面的num[i]分别换成max和min后，此函数功能变为最大序列积是错的！！！！ */
		/* 最大序列积四个数都要进行比较！！！！ */
#if 0
		max = MAX(num[i], MAX(num[i]*maxtemp, num[i]*mintemp));
		min = MIN(num[i], MIN(num[i]*maxtemp, num[i]*mintemp));
#else
		max = MAX(MAX(maxtemp,num[i]), MAX(num[i]*maxtemp, num[i]*mintemp));
		min = MIN(MIN(num[i],mintemp), MIN(num[i]*maxtemp, num[i]*mintemp));
#endif
		if (max>maxDp)
		{
			maxDp = max;
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

	cout << "MaxMulti:"<<MaxMulti(num,N) << endl;

	system("pause");
	return 0;
}