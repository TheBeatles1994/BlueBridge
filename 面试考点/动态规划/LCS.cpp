#include <iostream>
#include <string>

using namespace std;

#define MAXLEN 20			//最大字符串长度
#define MAX(x,y) x>y?x:y

/*
 * 函数功能: 输出所有LCS序列
 * 创建人:   TheBeatles1994
 */
void ShowAllValue(int lcs[][MAXLEN+1],char str1[],char str2[], int row,int col)
{
	if (row-1<0 || col-1<0)
	{
		cout <<endl;
		return;
	}

	if (str1[row] == str2[col])
	{
		ShowAllValue(lcs,str1,str2,row-1,col-1);
		cout << str1[row];
	} 
	else
	{
		if (lcs[row][col-1]>lcs[row-1][col])
		{
			ShowAllValue(lcs,str1,str2,row,col-1);
		}
		else if (lcs[row][col-1]<=lcs[row-1][col])
		{
			ShowAllValue(lcs,str1,str2,row-1,col);
		}
		else
		{
			//关于如何得到所有结果，自己还没尝试，现在只有一个结果
			ShowAllValue(lcs,str1,str2,row,col-1);
			ShowAllValue(lcs,str1,str2,row-1,col);
		}
	}
}

/*
 * 函数功能: 最长公共子序列
 * 创建人:   TheBeatles1994
 */
int LCS(char str1[], char str2[])
{
	int str1len = strlen(str1)-1;
	int str2len = strlen(str2)-1;
	int lcs[MAXLEN+1][MAXLEN+1]={0};
	int str1flag=0;
	int str2flag=0;
	//初始化strdist
	for (int i = 1; i <= str1len; i++)
	{
		if (str1[1]==str2[i] && str1flag==0)
		{
			str1flag=1;
		}
		if (str2[1]==str1[i] && str2flag==0)
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
			if (str1[i]==str2[j])
			{
				lcs[i][j]= lcs[i-1][j-1]+1;				//最后一个值相同
			} 
			else
			{
				lcs[i][j]=MAX(lcs[i][j-1],lcs[i-1][j]);	//最后一个值不同
				//lcs[i][j-1]：表示去掉第二组元素的最后一个值
				//lcs[i-1][j]：表示去掉第一组元素的最后一个值
			}
		}
	}

	ShowAllValue(lcs,str1,str2,str1len,str2len);
	cout <<endl;

	return lcs[str1len][str2len];
}

int main()
{
	char str1[MAXLEN + 1];
	char str2[MAXLEN + 1];
	char strSpace1[MAXLEN + 2] = " ";
	char strSpace2[MAXLEN + 2] = " ";

	gets_s(str1);
	gets_s(str2);

	strcat_s(strSpace1,MAXLEN,str1);
	strcat_s(strSpace2,MAXLEN,str2);

	cout << "LCS:"<<LCS(strSpace1, strSpace2) << endl;

	system("pause");
	return 0;
}