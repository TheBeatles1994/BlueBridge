#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char *str1 = "sunzhsunzhsunzhsunzh";
    char str2[] = "sunzh";
    cout<<sizeof(str1)<<endl;
    cout<<sizeof(str2)<<endl;
    if(str1[20] == '\0')
        cout<<"1"<<endl;
    if(str2[5] == '\0')
        cout<<"2"<<endl;
    return 0;
}
