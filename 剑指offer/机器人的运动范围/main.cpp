#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int countStep=0;

bool isOK(int threshold, int i, int j)
{
    int sum=0;
    while(i!=0)
    {
        sum += i%10;
        i = i/10;
    }
    while(j!=0)
    {
        sum += j%10;
        j = j/10;
    }

    if(sum>threshold)
        return false;
    else
        return true;
}

void onestep(int threshold, int rows, int cols, int i, int j, bool *flag)
{
    if(i>rows || i<0)
        return;
    if(j>cols || j<0)
        return;
    if(flag[i*(cols+1)+j] == true)
        return;
    if(!isOK(threshold, i, j))
        return;

    countStep++;
    flag[i*(cols+1)+j] = true;

    onestep(threshold, rows, cols, i+1, j, flag);
    onestep(threshold, rows, cols, i-1, j, flag);
    onestep(threshold, rows, cols, i, j+1, flag);
    onestep(threshold, rows, cols, i, j-1, flag);
}

int movingCount(int threshold, int rows, int cols)
{
    bool flag[rows*cols];

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
            flag[i*cols+j] = false;
    }

    onestep(threshold, rows-1, cols-1, 0, 0, flag);

    return countStep;
}

int main()
{
    cout<<movingCount(15, 20, 20);

    return 0;
}
