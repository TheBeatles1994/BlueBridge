#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>

using namespace std;

multiset<int> myset;

void Insert(int num)
{
    myset.insert(num);
}

double GetMedian()
{
    //if((int)myset.size() & 0x1 != 0x1)   //偶数
    if(myset.size()%2==0)
    {
        auto it=myset.begin();

        for(int count=0;count<myset.size()/2-1;count++)
            it++;
        int num1 = *it;
        int num2 = *(++it);
        return (num1+num2)/2.0;
    }
    else                            //奇数
    {
        auto it=myset.begin();
        for(int count=0;count<(myset.size()+1)/2-1;count++)
            it++;
        return *it;
    }
}

int main()
{
    while(1){
        int n;
        cin>>n;
        Insert(n);
        //cout<<GetMedian()<<endl;
        cout<<(myset.size()&0x1)<<endl;
    }
    return 0;
}
