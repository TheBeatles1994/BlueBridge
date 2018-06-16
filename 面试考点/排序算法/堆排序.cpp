#include <iostream>
#include <vector>

using namespace std;
void HeapAdjust(vector<int> &data, int l1, int l2);
/* 堆排序 */
void HeapSort(vector<int> &data)
{
    for(int i=(data.size()-1)/2;i>=1;i--)
    {
        HeapAdjust(data, i, data.size()-1);
    }

    for(int i=data.size()-1;i>1;i--)
    {
        data[0] = data[i];
        data[i] = data[1];
        data[1] = data[0];
        HeapAdjust(data, 1, i-1);
    }
}
/* 堆顺序调整 */
//l1为起始点，l2为结束点
void HeapAdjust(vector<int> &data, int l1, int l2)
{
    int i;
    data[0] = data[l1];
    for(i=l1*2;i<=l2;i*=2)
    {
        /* 找出最大子树 */
        if(i<l2)
            if(data[i]<data[i+1])
                i++;
        if(data[0]>data[i])
            break;
        data[l1] = data[i];
        l1 = i;
    }
    data[i/2] = data[0];
}

int main()
{
    vector<int> data = {0,9,1,5,8,3,7,4,6,2,3,5,10,2,5,3};//注意第一位不放数据

    HeapSort(data);

    for(int i=1;i<data.size();i++)
        cout << data[i]<<" ";
    return 0;
}
