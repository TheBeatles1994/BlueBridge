#include <iostream>
#include <vector>

using namespace std;
/* 传统冒泡排序 */
void BubbleSort(vector<int> &data)
{
    for(int i=0;i<data.size();i++)
    {
        for(int j=data.size()-1;j>i;j--)
        {
            if(data[j]<data[j-1])
            {
                int temp = data[j];
                data[j] = data[j-1];
                data[j-1] = temp;
            }
        }
    }
}
/* 改进后的冒泡排序 */
void BubbleSortImproved(vector<int> &data)
{
    for(int i=0;i<data.size();i++)
    {
        bool isSort = false;
        for(int j=data.size()-1;j>i;j--)
        {
            if(data[j]<data[j-1])
            {
                int temp = data[j];
                data[j] = data[j-1];
                data[j-1] = temp;
                isSort = true;
            }
        }
        if(!isSort)
            break;
    }
}
int main()
{
    vector<int> data = {7,8,5,6,1,3,4,9,6,5};

    BubbleSort(data);

    for(auto i:data)
        cout << i<<" ";
    return 0;
}
