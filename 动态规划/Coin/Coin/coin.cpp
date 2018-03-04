#include <iostream>

using namespace std;

#define MAX(x, y) (x>y?x:y)	//特别注意要加括号！！！
#define MINNUM 0
#define MAXROW 50			//最大行数
#define MAXCOL 50			//最大列数

int main()
{
	int N,M;
	int num[MAXROW][MAXCOL]={0};
	int sum[MAXROW][MAXCOL]={0};

	cin >> N >> M;

	for (int i=0;i<N;i++)
	{
		for (int j=0;j<M;j++)
		{
			cin >> num[i][j];
		}
	}

	for (int i=0;i<N;i++)
	{
		for (int j=0;j<M;j++)
		{
			if (i==0 && j==0)
			{
				sum[i][j] = num[i][j];
			}
			else if(i==0 && j!=0)
			{
				sum[i][j] = num[i][j] + sum[i][j-1];
			}
			else if(i!=0 && j==0)
			{
				sum[i][j] = num[i][j] + sum[i-1][j];
			}
			else
			{
				sum[i][j] = MAX(sum[i][j-1],sum[i-1][j]) + num[i][j];
			}
		}
	}
	cout << sum[N-1][M-1] <<endl;

	system("pause");
	return 0;
}