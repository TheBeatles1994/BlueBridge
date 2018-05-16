#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> FindNumbersWithSum(vector<int> array,int sum)
{
    vector<int> rst;

    if(array.empty())
        return rst;

    vector<int>::iterator ia;
    vector<int>::reverse_iterator ib;
    for(ia=array.begin(), ib=array.rbegin();*ia!=*ib && ia!=array.end() && ib!=array.rend();)
    {
        if((*ia) + (*ib) > sum)
            ib++;
        else if(*ia + *ib == sum)
        {
            rst.push_back(*ia);
            rst.push_back(*ib);
            break;
        }
        else
            ia++;
    }

    return rst;
}

int main(int argc, char *argv[])
{
    vector<int> array={1,2,3,4,5,6,7,8,9};
    vector<int> rst = FindNumbersWithSum(array, 14);


    cout << rst[0]<<" "<<rst[1]<<endl;

    return 0;
}
