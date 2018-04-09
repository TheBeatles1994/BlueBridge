#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
/*
 * 函数功能：
 * 最小的k个数
 */
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    set<int> mySet(input.begin(), input.end());
    vector<int> rstVec;

    if(k>input.size())
        return rstVec;

    int i=0;
    for(auto it=mySet.begin();i<k && it!=mySet.end();it++)
    {
        rstVec.push_back(*it);
        i++;
    }

    return rstVec;
}

int main(int argc, char *argv[])
{
    vector<int> data={4,5,1,6,2,7,3,8};
    vector<int> rstData;

    rstData = GetLeastNumbers_Solution(data, 10);
    for(auto i:rstData)
        cout << i<<" ";

    return 0;
}

