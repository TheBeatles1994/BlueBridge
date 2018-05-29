#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>

using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    vector<int> rst;

    if(num.empty())
        return rst;

    for(int i=0;i<num.size()-size+1;i++)
    {
        int max=num[i];
        for(int j=1;j<size;j++)
        {
            if(max<num[i+j])
                max = num[i+j];
        }
        rst.push_back(max);
    }

    return rst;
}

int main()
{
    while(1)
    {
        int n;
        cin>>n;
    }
    return 0;
}
