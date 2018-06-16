#include <iostream>
#include <string>

using namespace std;

#define MAXLEN 50			//������ֳ���
#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x<y?x:y)

/*
 * ��������: ����������л�
 * ������:   TheBeatles1994
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
		/* �������num[i]�ֱ𻻳�max��min�󣬴˺������ܱ�Ϊ������л��Ǵ�ģ������� */
		/* ������л��ĸ�����Ҫ���бȽϣ������� */
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