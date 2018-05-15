#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> testNum(int num, const int sum)
{
    vector<int> vNum;
    int temp=0;

    while(temp<sum)
    {
        vNum.push_back(num);
        temp+=num;
        num++;
    }

    if(temp==sum)
        return vNum;
    else
        return vector<int>();
}

vector<vector<int> > FindContinuousSequence(int sum)
{
    vector<vector<int> > vvNum;

    for(int i=1;i<=sqrt(sum*2);i++)
    {
        vector<int> vNum = testNum(i, sum);
        if(!vNum.empty())
            vvNum.push_back(vNum);
    }

    return vvNum;
}

int main(int argc, char *argv[])
{
    int num;
    vector<vector<int> > vecRst;

    while(cin>>num)
    {
        vecRst = FindContinuousSequence(num);

        for(auto ia = vecRst.begin(); ia!=vecRst.end(); ia++)
        {
            for(auto ib = (*ia).begin();ib!=(*ia).end();ib++)
                cout<<*ib<<" ";
            cout<<endl;
        }
    }

    return 0;
}
