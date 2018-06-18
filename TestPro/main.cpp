#include <iostream>
#include <vector>

using namespace std;
/* 归并排序 */
void Merge(vector<int> &data, int begin, int mid, int end)
{
    vector<int> datacopy(data);
    int i, j, index=0;
    i = begin;
    j = mid+1;
    index = begin;

    while(i<=mid && j<=end)
    {
        if(datacopy[i]<=datacopy[j])
            data[index++] = datacopy[i++];
        else
            data[index++] = datacopy[j++];
    }

    while(i<=mid)
        data[index++] = datacopy[i++];
    while(j<=end)
        data[index++] = datacopy[j++];

}

void MSort(vector<int> &data, int start, int end)
{
    if(start >= end)
        return;

    int mid = start + (end-start)/2;

    MSort(data, start, mid);
    MSort(data, mid+1, end);
    Merge(data, start, mid, end);
}

void MergeSort(vector<int> &data)
{
    MSort(data, 0, data.size()-1);
}

int main()
{
    vector<int> data = {10,9,8,7,6,5,4,3,2,1};

    MergeSort(data);

    for(int i=0;i<data.size();i++)
        cout << data[i]<<" ";
    return 0;
}
