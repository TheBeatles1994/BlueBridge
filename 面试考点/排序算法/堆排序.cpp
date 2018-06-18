#include <iostream>
#include <vector>

using namespace std;
void HeapAdjust(vector<int> &data, int begin, int end);
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
void HeapAdjust(vector<int> &data, int begin, int end)
{
    int temp = data[begin];
    int index = 0;
    while(2*begin<=end)     //not a leaf node
    {
        if(2*begin+1<=end)  //have a right child
        {
            if(data[2*begin]>=data[2*begin+1])
            {
                index = 2*begin;
            }
            else
                index = 2*begin+1;
        }
        else
            index = 2*begin;
        if(temp<data[index])
        {
            data[begin] = data[index];
            begin = index;
        }
        else
            break;
    }
    data[begin] = temp;
}

int main()
{
    vector<int> data = {0,9,1,5,8,3,7,4,6,2,3,5,10,2,5,3};//注意第一位不放数据

    HeapSort(data);

    for(int i=1;i<data.size();i++)
        cout << data[i]<<" ";
    return 0;
}

