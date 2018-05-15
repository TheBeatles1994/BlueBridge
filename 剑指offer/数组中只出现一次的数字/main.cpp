#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2)
{
    vector<int> num;

    for(auto it=data.begin();it!=data.end();it++)
    {
        auto findIt = find(num.begin(), num.end(), *it);
        if(findIt == num.end())
            num.push_back(*it);
        else
            num.erase(findIt);
    }

    *num1 = num[0];
    *num2 = num[1];
}

int main(int argc, char *argv[])
{
    vector<int> vec = {4,6,1,1,1,1};
    int num1=0;
    int num2=0;

    FindNumsAppearOnce(vec, &num1, &num2);

    cout<<num1<<" "<<num2<<endl;

    return 0;
}
