#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
/*
 * 函数功能：
 * 把数组排成最小的数
 */
struct SetComp
{
    bool operator()(const string str1, const string str2) const
    {
        string temp1=str1;
        string temp2=str2;

        if(str1.length()>str2.length())
        {
            for(int i=0;i<str1.length()-str2.length();i++)
            {
                temp2.push_back(str2[str2.length()-1]);
            }
        }
        else
        {
            for(int i=0;i<str2.length()-str1.length();i++)
            {
                temp1.push_back(str1[str1.length()-1]);
            }
        }

        return temp1<temp2;
    }
};
string PrintMinNumber(vector<int> numbers) {
    multiset<string, SetComp> myset;
    string rstStr="";

    for(auto i:numbers)
    {
        string tempStr = to_string(i);
        myset.insert(tempStr);
    }

    for(auto it=myset.begin();it!=myset.end();it++)
        rstStr.append(*it);

    return rstStr;
}
int main(int argc, char *argv[])
{
    vector<int> vecNum = {3,323,23,2};

    cout<<PrintMinNumber(vecNum)<<endl;

    return 0;
}

