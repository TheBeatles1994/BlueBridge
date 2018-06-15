#include <iostream>
#include <string>
#include <array>

using namespace std;

bool KMPalgo(string str, string substr)
{
    int *next = (int *)malloc(substr.length() * sizeof(int));
    next[0] = 0;

    for (int i=1,j=0;i<substr.length();)
    {
        if(substr[i] == substr[j])
        {
            next[i] = j+1;
            j++;
            i++;
        }
        else
        {
            if(j == 0)
            {
                next[i] = 0;
                i++;
            }
            else
            {
                j = next[j-1];
                continue;
            }
        }
    }

    int index=0;
    for(int i=0;i<str.length();)
    {
        if(str[i] == substr[index])
        {
            index++;
            i++;
            if(index == substr.length())
                return true;
        }
        else
        {
            if(index != 0)
            {
                index = next[index-1];
            }
            else
            {
                i++;
            }

        }
    }

    delete next;

    return false;
}

int main()
{
    string str, substr;

    while(cin >> str >> substr)
    {
        if(KMPalgo(str, substr))
            cout << "yes"<<endl;
        else
            cout << "no"<<endl;
    }



    return 0;
}
