#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LastRemaining_Solution(int n, int m)
{
    vector<int> vec;

    vec.reserve(n);
    for(int i=0;i<n;i++)
    {
        vec.push_back(i);
    }

    auto rname = vec.begin();
    while(vec.size() != 1)
    {
        for(int i=0;i<m;i++)
        {
            if(rname == vec.end())
                rname = vec.begin();
            rname++;
        }
        rname = vec.erase(rname);
        if(rname == vec.end())
            rname = vec.begin();
    }

    return vec[0];
}

int main(int argc, char *argv[])
{
    vector<int> array={0,1,2,3,4,5,6,7,8,9};
    int n, m;

    while(cin>>n>>m)
    {
        cout <<LastRemaining_Solution(n, m)<<endl;
    }


    return 0;
}
