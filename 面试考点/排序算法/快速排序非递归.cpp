#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stack>

using namespace std;

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
void QuickSort(vector<int> &data)
{
    stack<int> mystack;
    int begin = 0, end = data.size()-1;
    int mid;
    mystack.push(begin);
    mystack.push(end);

    while(!mystack.empty())
    {
        end = mystack.top();
        mystack.pop();
        begin = mystack.top();
        mystack.pop();
        if(begin<end)
        {
            mid = Partition(data, begin, end);
            mystack.push(begin);
            mystack.push(mid-1);
            mystack.push(mid+1);
            mystack.push(end);
        }
    }
}

int main()
{
    vector<int> data={10,3,2,6,5,4,9};

    QuickSort(data);
    for(auto i:data)
    {
        cout<<i<<" ";
    }

    return 0;
}
