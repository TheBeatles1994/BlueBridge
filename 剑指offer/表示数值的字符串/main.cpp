#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <string>

using namespace std;

bool isNumber(string str, bool is_right)
{
    if(str.empty()&&is_right)
        return false;
    for(auto i:str)
    {
        if(!isdigit(i))
            return false;
    }

    return true;
}

bool analyzeSubStr(std::string str,bool is_right)
{
    if(str.empty())
        return false;

    /* 分析+-号 */
    if(str[0] == '+' ||str[0] == '-')
        str=str.substr(1);

    /* 找.的个数 */
    int count=0;
    for(auto i:str)
    {
        if(i=='.')
            count++;
    }

    if(is_right &&count>=1)
        return false;

    if(count>1)
        return false;
    else if(count == 1)
    {
        size_t indexP = str.find('.');
        return isNumber(str.substr(0,indexP), false) && isNumber(str.substr(indexP+1), true);
    }
    else
    {
        return isNumber(str,true);
    }
}

bool isNumeric(char* string)
{
    std::string str(string);

    if(str.empty())
        return false;

    /* 找E的个数 */
    int count=0;
    for(auto i:str)
    {
        if(i=='e' || i=='E')
            count++;
    }

    if(count>1)
        return false;
    else if(count==1)
    {
        size_t indexE = str.find('e');
        if(indexE == std::string::npos)
            indexE = str.find('E');
        return analyzeSubStr(str.substr(0,indexE),false) && analyzeSubStr(str.substr(indexE+1),true);
    }
    else
    {
        return analyzeSubStr(str,false);
    }
}

int main(int argc, char *argv[])
{
    //"+100","5e2","-123","3.1416"和"-1E-16"
    //"12e","1a3.14","1.2.3","+-5"和"12e+4.3"
    char *str = "-.123";

    if(isNumeric(str))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;

    return 0;
}
