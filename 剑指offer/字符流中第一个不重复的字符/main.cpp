#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <string>

using namespace std;

string str="";
int index=-1;
set<char> newset;
set<char> repset;
//Insert one char from stringstream
void Insert(char ch)
{
    str.append({ch});
    /* 检查该字符是否在重复字符串中 */
    if(newset.find(ch) == newset.end())     //不在
    {
        newset.insert(ch);
        if(index == -1)
        {
            index = str.size()-1;
        }
        return;
    }
    else                                    //在
    {
        if(str[index] == ch)
        {
            repset.insert(ch);
            int i =index+1;
            for(;i<str.size();i++)
            {
                if(repset.find(str[i]) == repset.end())
                {
                    index = i;
                    break;
                }
            }
            if(i == str.size())
                index = -1;
        }
        else
        {
            repset.insert(ch);
        }
    }
}
//return the first appearence once char in current stringstream
char FirstAppearingOnce()
{
    if(index == -1)
    {
        return '#';
    }
    else
        return str[index];
}

int main(int argc, char *argv[])
{
    char ch;

    while(cin>>ch)
    {
        Insert(ch);
        cout<<FirstAppearingOnce()<<endl;
    }

    return 0;
}
