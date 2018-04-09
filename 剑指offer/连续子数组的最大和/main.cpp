#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
/*
 * 函数功能：
 * 连续子数组的最大和
 */
int FindGreatestSumOfSubArray(vector<int> array)
{
    vector<int> dpArray(array.size(), 0);

    dpArray[0] = array[0];
    for(int i=1;i<array.size();i++)
    {
        if(dpArray[i-1]<=0)
            dpArray[i] = array[i];
        else
            dpArray[i] = array[i] + dpArray[i-1];
    }

    int max = dpArray[0];
    for(int i=1;i<dpArray.size();i++)
    {
        if(max<dpArray[i])
            max = dpArray[i];
    }

    return max;
}

int main(int argc, char *argv[])
{
    vector<int> data={6,-3,-2,7,-15,1,2,2};

    cout<<FindGreatestSumOfSubArray(data)<<endl;

    return 0;
}

