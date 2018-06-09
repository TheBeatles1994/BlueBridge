#include <iostream>
#include <vector>

using namespace std;
/* 简单选择排序 */
void InsertSort(vector<int> &data)
{
    for(int i=0;i<data.size()-1;i++)
    {
        int min=data[0];
        for(int j=i+1;j<data.size();j--)
        {
            if(min>data[j])
            {
                min = data[j];
            }
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
