#include <iostream>
#include <vector>

using namespace std;
/* 直接插入排序 */
void InsertSort(vector<int> &data)
{
    int temp=0;

    for(int i=1;i<data.size();i++)
    {
        if(data[i]<data[i-1])
        {
            temp = data[i];
            int j;
            for(j=i-1;data[j]>temp && j>=0;j--)
            {
                data[j+1] = data[j];
            }
            data[j+1] = temp;
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
