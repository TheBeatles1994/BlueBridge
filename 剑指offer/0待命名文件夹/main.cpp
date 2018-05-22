#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <string.h>

using namespace std;

bool isPatternOK(char* pattern)
{
    if(strlen(pattern)%2 == 0)  //必须是偶数
    {
        for(int i=1;i<strlen(pattern);i+=2)
        {
            if(pattern[i]!='*') //偶数位必须是*
                return false;
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool match(char* str, char* pattern)
{
    if(strlen(pattern)==0)
    {
        if(strlen(str)!=0)
            return false;
        else
            return true;
    }
    if(strlen(str)==0)
    {
        if(isPatternOK(pattern))
            return true;
        else
            return false;
    }


    bool rst;
    /* 判断*的位置 */
    if(strlen(pattern)>=2)
    {
        if(pattern[1] != '*')           //第二位不是*
        {
            if(str[0] == pattern[0] || pattern[0]=='.')    //第一位不同
                rst = match(str+1, pattern+1);
            else                        //第一位相同
                return false;
        }
        else                            //第二位是*
        {
            if(str[0] == pattern[0] || pattern[0]=='.')  //第一位不同
            {
                rst = match(str+1, pattern+2) || match(str+1, pattern) || match(str, pattern+2);
            }
            else                                        //第一位相同
            {
                rst = match(str, pattern+2);
            }
        }
    }
    else
    {
        if(pattern[0] == str[0] || pattern[0]=='.')
            rst = match(str+1, pattern+1);
        else
            return false;
    }


    return rst;
}

int main(int argc, char *argv[])
{
    char *str = "aaa";
    char *pattern = "a.a";

    if(match(str, pattern))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;

    return 0;
}
