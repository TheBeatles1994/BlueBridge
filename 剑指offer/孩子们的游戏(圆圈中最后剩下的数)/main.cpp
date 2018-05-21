#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int LastRemaining_Solution(int n, int m)
{
    if(n== 0)
        return -1;

    int count=n;
    map<int, bool> mymap;

    for(int i=0;i<n;i++)
        mymap[i]=false;

    auto rst=mymap.begin();
    while(count!=1)
    {
        for(int i=0;i<m;)
        {
            if(rst==mymap.end())
                rst=mymap.begin();
            if(rst->second == false)
            {
                i++;
            }
            if(i == m)
            {
                rst->second = true;
            }
            rst++;
        }
        count--;
    }

    for(int i=0;i<n;i++)
    {
        if(mymap[i] == false)
            return i;
    }

    return -1;
}

int main(int argc, char *argv[])
{
    int n, m;

    while(cin>>n>>m)
    {
        cout <<LastRemaining_Solution(n, m)<<endl;
    }


    return 0;
}
