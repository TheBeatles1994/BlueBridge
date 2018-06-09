#include <iostream>
#include <vector>

using namespace std;
/* 直接插入排序 */
void ShellSort(vector<int> &data)
{
    int increment = data.size();
    int temp;
    do
    {
        increment = increment/3+1;

        for(int i=increment;i<data.size();i++)
        {
            if(data[i]<data[i-increment])
            {

            }
        }

    }while(increment>1);
}

int main()
{
    vector<int> data = {7,8,5,6,1,3,4,9,6,5};

    ShellSort(data);

    for(auto i:data)
        cout << i<<" ";
    return 0;
}
