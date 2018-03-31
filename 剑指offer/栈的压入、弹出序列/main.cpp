#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    if(pushV.size() == 0 || popV.size() == 0)
        return false;

    stack<int> temp;
    int pushi=0;
    int popi=0;

    while(popi != popV.size())
    {
        if(temp.empty())
            temp.push(pushV[pushi++]);

        if(temp.top() == popV[popi])
        {
            temp.pop();
            popi++;
        }
        else
        {
            if(pushi == pushV.size())
                return false;
            temp.push(pushV[pushi++]);
        }
    }

    return true;
}

int main(int argc, char *argv[])
{
    int n, temp;
    vector<int> pushV, popV;

    cin >> n;

    for(int i=0;i<n;i++)
    {
        cin>>temp;
        pushV.push_back(temp);
    }
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        popV.push_back(temp);
    }

    if(IsPopOrder(pushV,popV))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    return 0;
}

