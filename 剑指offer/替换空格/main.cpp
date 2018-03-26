#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<stdlib.h>

using namespace std;
#define MAXLEN 100
/*
 * Function:
 *
 */
void replaceSpace(char *str,int length) {
    int spaceCount=0;
    int oldStrLen=0;
    int newStrLen=0;

    while(str[oldStrLen]!='\0')
    {
        if(str[oldStrLen] == ' ')
            spaceCount++;
        oldStrLen++;
    }

    newStrLen = oldStrLen + 2*spaceCount;   //总个数已包含休止符
    if (newStrLen >= length)
        return;

    str[newStrLen--] = '\0';
    oldStrLen--;    //不包含休止符
    while(oldStrLen>=0)
    {
        if(str[oldStrLen] == ' ')
        {
            str[newStrLen--]='0';
            str[newStrLen--]='2';
            str[newStrLen--]='%';
        }
        else
        {
            str[newStrLen--]=str[oldStrLen];
        }

        oldStrLen--;
    }

}

int main(int argc, char *argv[])
{
    char str[MAXLEN];

    gets(str);
    replaceSpace(str,MAXLEN);
    printf("%s", str);

    return 0;
}
