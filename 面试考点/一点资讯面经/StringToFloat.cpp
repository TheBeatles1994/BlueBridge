#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

//#include "test.h"

using namespace std;

double StringToFloat(string str)
{
    double rst=0;

    int decimal = str.find('.');
    for(int i=0;i<decimal;i++)
    {
        rst += (str[i]-'0')*pow(10, decimal-1-i);
    }
    for(int i=decimal+1;i<str.length();i++)
    {
        rst += (str[i]-'0')*pow(10,decimal-i);
    }

    return rst;
}

int main()
{
    string str;
    while(cin>>str)
    {
        cout <<setprecision(15)<<StringToFloat(str)<<endl;
    }

    return 0;
}
