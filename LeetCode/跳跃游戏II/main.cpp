#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
#define MAXVALUE 10000000
#if 0
int jump(vector<int>& nums)
{
    int sz = nums.size();
    if(sz == 1)
        return 0;
    int dp[sz];

    dp[0] = 0;
    int i=1;
    while(1)
    {
        for(int j=0;j<i;j++)
        {
            if(j+nums[j]>=sz-1)
            {
                return (dp[j]+1);
            }
            if(j+nums[j]>=i)
            {
                dp[i]=dp[j]+1;
                break;
            }
        }
        i++;
    }

    return dp[sz-1];
}
#else
int jump(vector<int>& nums) {
    int n = nums.size();
    if(n <= 1)
        return 0;
    int cur = nums[0];  //当前跳到的最远距离
    int next = nums[0]; //下一步能跳到的最远距离
    int step = 1;
    for(int i = 1; i< n; i++){
        if(cur < i){
            cur = next;
            step++;
        }
        if(i + nums[i] > next){
            next = i + nums[i];
        }
        if(cur >= n-1)
            return step;
    }
    return 0;
}
#endif

int main(int argc, char *argv[])
{
    vector<int> data;
    for(int i=0;i<25000;i++)
        data.push_back(1);

    cout<<jump(data)<<endl;

    return 0;
}

