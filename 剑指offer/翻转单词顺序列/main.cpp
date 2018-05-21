#include <iostream>
#include <string>

using namespace std;

string ReverseSentence(string str)
{
    string rst;
    size_t pos;

    while((pos = str.find_last_of(' '))!= string::npos)
    {
        rst.append(str.substr(pos+1));
        rst.append(" ");
        str.erase(pos);
    }
    rst.append(str);

    return rst;
}

int main(int argc, char *argv[])
{
    string str = "student. a am I";
//    while(cin>>str)
//    {
        cout<<ReverseSentence(str)<<endl;
//    }
}
