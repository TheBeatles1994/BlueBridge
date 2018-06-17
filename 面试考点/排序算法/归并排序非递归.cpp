#include<iostream>
#include<vector>

using namespace std;

void Merge(vector<int> &data, int begin, int mid, int end)
{
    vector<int> datacopy(data);
    int index1=begin;
    int index2 = mid+1;
    int index = begin;

    while(index1<=mid && index2<=end)
    {
        if(datacopy[index1]<=datacopy[index2])
            data[index++] = datacopy[index1++];
        else
            data[index++] = datacopy[index2++];
    }
    while(index1<=mid)
        data[index++] = datacopy[index1++];
    while(index2<=end)
        data[index++] = datacopy[index2++];
}

void MergeSort(vector<int> &data)
{
    int step=1;
    int begin, mid, end;

    while(step<=data.size()-1)
    {
        begin = 0;
        while(begin+step-1<data.size())
        {
            mid = begin+step-1;
            end = mid+step;
            if(end>data.size()-1)
                end = data.size()-1;
            Merge(data, begin, mid, end);
            begin = end+1;
        }

        step <<= 1;
    }
}

int main(int argc, char *argv[])
{
    vector<int> data= {3, 8,9,7,1};

    MergeSort(data);
    for(int i=0;i<data.size();i++)
        cout<<data[i]<<" ";

    return 0;
}
