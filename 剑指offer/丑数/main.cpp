#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
/*
 * 函数功能：
 * 丑数
 */
int GetUglyNumber_Solution(int index) {
    int index2, index3, index5;
    int temp2, temp3, temp5;
    int *data;
    /* 初始化 */
    index2 = 0;
    index3 = 0;
    index5 = 0;
    data = (int *)calloc(index, sizeof(int));
    data[0] = 1;

    for(int i=1;i<index;i++)
    {
        temp2 = data[index2]*2;
        temp3 = data[index3]*3;
        temp5 = data[index5]*5;

        int minNum = min(temp2, min(temp3, temp5));

        data[i] = minNum;
        if(minNum == temp2)
            index2++;
        if(minNum == temp3)
            index3++;
        if(minNum == temp5)
            index5++;
    }

    return data[index-1];
}
int main(int argc, char *argv[])
{
    int n;

    cin >> n;

    cout<<GetUglyNumber_Solution(n)<<endl;

    return 0;
}

