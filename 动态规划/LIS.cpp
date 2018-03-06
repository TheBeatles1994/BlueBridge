#include <iostream>
#include <string>

using namespace std;

#define MAXLEN 50			//����ַ�������
#define MAX(x,y) x>y?x:y

/*
 * ��������: ���ַ�����
 * ������:   TheBeatles1994
 */
int BiSearch(int num[],int ins, int left,int right)
{
	int mid;

	mid = left+(right-left)/2;

	while (left<=right)
	{
		if (ins>num[mid])
		{
			left = mid +1;
		} 
		else if(ins<num[mid])
		{
			right = mid -1;
		}
		else
		{
			return mid;			//�ҵ��˸�Ԫ�أ�ֱ�ӷ���
		}

		mid = left+(right-left)/2;
	}

	return mid;					//û���ҵ���Ԫ�أ����ʱ��mid��Ϊ�����λ��
}

/*
 * ��������: �����������
 * ������:   TheBeatles1994
 */
int LIS(int num[],int n)
{
	int *d;
	int len=0;

	d = (int *)malloc(sizeof(int)*n);

	d[0]=num[0];
	for (int i=1;i<n;i++)
	{
		if (num[i]<d[len])
		{
			int tempNum = BiSearch(d,num[i],0,len);	//���ַ����ش�����λ��
			d[tempNum] = num[i];
		}
		else
		{
			len++;
			d[len] = num[i];
		}
	}

	return (len+1);
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

	cout << "LIS:"<<LIS(num,N) << endl;

	system("pause");
	return 0;
}