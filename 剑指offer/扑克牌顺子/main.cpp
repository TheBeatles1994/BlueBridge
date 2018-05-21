#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsContinuous( vector<int> numbers )
{
    if(numbers.empty())
        return false;

    int zeroNum=0;
    int difference=0;

    sort(numbers.begin(), numbers.end());

    for(auto i=numbers.begin(); i!=numbers.end()-1; i++)
    {
        if(*i == 0)
            zeroNum++;
        else
        {
            if(*(i+1) - *i - 1 < 0)
                return false;
            else
                difference += *(i+1) - *i - 1;
        }
    }

    if(zeroNum >= difference)
        return true;
    else
        return false;
}

int main(int argc, char *argv[])
{
    vector<int> numbers = {1,0,0,1,0};

    if(IsContinuous(numbers))
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;

    return 0;
}
