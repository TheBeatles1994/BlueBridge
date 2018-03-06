#include <iostream>
#include <string>

using namespace std;

#define MAXLEN 50			//����ַ�������
#define MAX(x,y) x>y?x:y

/*
 * ��������: �����������
 * ������:   TheBeatles1994
 */
int DP(int num[],int n)
{
	int *d;
	int len=0;

	d = (int *)malloc(sizeof(int)*n);

	d[0] = 1;
	for (int i=1;i<n;i++)
	{
		int maxLen = 0;
		for (int j=0;j<i;j++)
		{
			if (num[i]>num[j] && maxLen<d[j])
			{
				maxLen = d[j];
			}
		}
		d[i] = maxLen+1;
	}

	int maxLen=1;
	for (int i=0;i<n;i++)
	{
		if (d[i]>maxLen)
		{
			maxLen = d[i];
		}
	}

	return maxLen;
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

	cout << "LIS:"<<DP(num,N) << endl;

	system("pause");
	return 0;
}