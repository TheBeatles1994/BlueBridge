#include <iostream>
#include <vector>

using namespace std;
/* 归并排序 */
void Merge(vector<int> &data, int start, int mid, int end)
{
    vector<int> tempdata(end+1);
    int i, j, k=0;
    for(i=start, j=mid+1;i<=mid && j<=end;k++)
    {
        if(data[i]>=data[j])
        {
            tempdata[k] = data[j++];
        }
        else
        {
            tempdata[k] = data[i++];
        }
    }

    for(;i<=mid;k++)
        tempdata[k]=data[i++];
    for(;j<=end;k++)
        tempdata[k]=data[j++];

    for(i=start,j=0;i<=end && j<tempdata.size();i++,j++)
    {
        data[i] = tempdata[j];
    }
}

void MSort(vector<int> &data, int start, int end)
{
    if(start == end)
        return;

    int mid = (start+end)/2;

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
    vector<int> data = {12, 22, 3, 4, 43, 47, 56};

    MergeSort(data);

    for(int i=0;i<data.size();i++)
        cout << data[i]<<" ";
    return 0;
}
