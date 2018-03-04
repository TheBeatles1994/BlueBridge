#include <iostream>
#include <string>

using namespace std;

#define MAXLEN 20			//最大字符串长度
/*
 * 函数功能: 返回三数中最大数
 * 创建人:   TheBeatles1994
 */
int Compare3Num(int num1,int num2,int num3)
{
	int max = num1;
	if (max<num2)
	{
		max = num2;
	}
	if (max<num3)
	{
		max = num3;
	}
	return max;
}
/*
 * 函数功能: 最长公共子序列
 * 创建人:   TheBeatles1994
 */
int LCS(char str1[], char str2[])
{
	int str1len = strlen(str1);
	int str2len = strlen(str2);
	int lcs[MAXLEN+1][MAXLEN+1]={0};
	int str1flag=0;
	int str2flag=0;
	//初始化strdist
	for (int i = 1; i <= str1len; i++)
	{
		if (str1[0]==str2[i-1] && str1flag==0)
		{
			str1flag=1;
		}
		if (str2[0]==str1[i-1] && str2flag==0)
		{
			str2flag=1;
		}
		lcs[1][i]=str1flag;
		lcs[i][1]=str2flag;
	}
	for (int i = 1; i <= str1len; i++)
	{
		for (int j = 1; j <= str2len; j++)
		{
			int cmp[3];
			cmp[0] = lcs[i-1][j-1]+(str1[i-1]==str2[j-1]?1:0);
			cmp[1] = lcs[i][j-1];
			cmp[2] = lcs[i-1][j];
			lcs[i][j]=Compare3Num(cmp[0],cmp[1],cmp[2]);
		}
	}

	return lcs[str1len][str2len];
}

int main()
{
	char str1[MAXLEN + 1];
	char str2[MAXLEN + 1];

	gets_s(str1);
	gets_s(str2);

	cout << LCS(str1, str2) << endl;

	system("pause");
	return 0;
}