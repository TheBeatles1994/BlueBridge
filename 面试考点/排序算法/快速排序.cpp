#include <iostream>
#include <vector>

using namespace std;
/* 快速排序 */
int Partition(vector<int> &data, int start, int end)
{
	/* 可以不要下面的pivot_value */
    int pivot_value=data[start];
    while(start<end)
    {
        while(start<end && data[end]>=pivot_value)      //注意此处是大于等于
            end--;
        //交换数据
//        if(start == end)
//            break;
        int temp = data[end];
        data[end] = data[start];
        data[start] = temp;

        while(start<end && data[start]<=pivot_value)    //注意此处是小于等于
            start++;
        //交换数据
//        if(start == end)
//            break;
        temp = data[end];
        data[end] = data[start];
        data[start] = temp;
    }

    return start;
}

void QSort(vector<int> &data, int start, int end)
{
    if(start<end)
    {
        int pivot=Partition(data, start, end);
        QSort(data, start, pivot-1);
        QSort(data, pivot+1, end);
    }
}

void QuickSort(vector<int> &data)
{
    QSort(data, 0, data.size()-1);
}

int main()
{
    vector<int> data = {5,1,9,3,7,4,8,6,2};

    QuickSort(data);

    for(int i=0;i<data.size();i++)
        cout << data[i]<<" ";
    return 0;
}
