#include <iostream>
#include <string>

using namespace std;

#define MAXLEN 50			//最大字符串长度
#define MAX(x,y) x>y?x:y

/*
 * 函数功能: 二分法查找
 * 创建人:   TheBeatles1994
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
			return mid;			//找到了该元素，直接返回
		}

		mid = left+(right-left)/2;
	}

	return mid;					//没有找到该元素，则此时的mid即为插入的位置
}

/*
 * 函数功能: 最长递增子序列
 * 创建人:   TheBeatles1994
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
			int tempNum = BiSearch(d,num[i],0,len);	//二分法返回待插入位置
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