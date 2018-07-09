#include<iostream>
#include<algorithm>
#include<vector>

int n,m;
using namespace std;
vector<vector<int> > mymap;

bool func(vector<vector<int> > &data)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mymap[i][j] == 0 && data[i][j]==1)
                return false;
        }
    }
    return true;
}

void operate(int i, int j)
{
    //i行填充0
    for(int col=0;col<m;col++)
    {
        mymap[i][col] = 0;
    }
    //j列填充0
    for(int row=0;row<n;row++)
    {
        mymap[row][j] = 0;
    }
}

int main(int argc, char *argv[])
{
    while(cin>>n>>m)
    {
        vector<vector<int> > data;
        data.reserve(n);
        mymap.reserve(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mymap[i].push_back(1);  //初始化
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int in;
                cin>>in;
                data[i].push_back(in);
                if(in == 0)
                   operate(i, j);
            }
        }
        if(func(data))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        mymap.clear();
    }

    return 0;
}

