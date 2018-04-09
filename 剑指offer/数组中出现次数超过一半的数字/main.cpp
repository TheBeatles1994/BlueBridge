#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;
/*
 * 函数功能：
 * 数组中出现次数超过一半的数字
 */
int MoreThanHalfNum_Solution(vector<int> numbers)
{
    if(numbers.size() == 0)
        return 0;
    if(numbers.size() == 1)
        return numbers[0];

    int maxArrayNumber, curArrayNumber;
    int maxArrayCount, curArrayCount;

    sort(numbers.begin(), numbers.end());

    maxArrayNumber = 0;
    maxArrayCount = 0;
    curArrayNumber = numbers[0];
    curArrayCount = 0;

    for(int i=0;i<numbers.size();i++)
    {
        if(curArrayNumber == numbers[i])
            curArrayCount++;
        else
        {
            if(curArrayCount>maxArrayCount)
            {
                maxArrayCount = curArrayCount;
                maxArrayNumber = numbers[i-1];
                curArrayNumber = numbers[i];
                curArrayCount = 1;
            }
        }
    }

    if(maxArrayCount > numbers.size()/2)
        return maxArrayNumber;
    else
        return 0;
}

int main(int argc, char *argv[])
{
    vector<int> data={1,2,3,2,2,2,5,4,2, 4, 4, 5, 4, 4};

    cout << MoreThanHalfNum_Solution(data)<<endl;

    return 0;
}

