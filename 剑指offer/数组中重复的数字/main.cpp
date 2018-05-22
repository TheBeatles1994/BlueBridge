#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>

using namespace std;

bool duplicate(int numbers[], int length, int* duplication)
{
    set<int> myset;
    for(int i=0;i<length;i++)
    {
        pair<set<int>::const_iterator, bool> mypair = myset.insert(numbers[i]);
        if(mypair.second == false)
        {
            *duplication = numbers[i];
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    int numbers[] = {2,3,1,0,2,5,3};
    int *dup = new int(0);

    if(duplicate(numbers, 7, dup))
        cout << *dup <<endl;

    return 0;
}
