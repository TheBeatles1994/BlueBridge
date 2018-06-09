#include <iostream>
#include <vector>

using namespace std;
/* 简单选择排序 */
void InsertSort(vector<int> &data)
{
    for(int i=0;i<data.size()-1;i++)
    {
        int min=i;
        for(int j=i+1;j<data.size();j++)
        {
            if(data[min]>data[j])
            {
                min = j;
            }
        }
        if(min!=i)
        {
            int temp = data[min];
            data[min] = data[i];
            data[i] = temp;
        }
    }
}

int main()
{
    vector<int> data = {7,8,5,6,1,3,4,9,6,5};

    InsertSort(data);

    for(auto i:data)
        cout << i<<" ";
    return 0;
}
