#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>

using namespace std;

bool isHsaPath(char* matrix, int rows, int cols, char* str, int index, int i, int j, bool* flag)
{
    if(index == (int)strlen(str))
        return true;

    if(i>rows || i<0)
        return false;
    if(j>cols || j<0)
        return false;
    if(str[index] != matrix[i*cols + j])
        return false;
    if(flag[i*cols + j] == true)
        return false;

    flag[i*cols + j] = true;
    if(isHsaPath(matrix, rows, cols, str, index+1, i-1, j, flag) ||
            isHsaPath(matrix, rows, cols, str, index+1, i+1, j, flag) ||
            isHsaPath(matrix, rows, cols, str, index+1, i, j+1, flag) ||
            isHsaPath(matrix, rows, cols, str, index+1, i, j-1, flag))
        return true;

    flag[i*cols + j] = false;
    return false;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
    if(strlen(str)==0)
        return true;

    bool flag[rows*cols] = {false};

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(isHsaPath(matrix, rows, cols, str, 0, i, j, flag))
                return true;
        }
    }

    return false;
}

int main()
{
    char *test = "ABCESFCSADEE";

    if(hasPath(test, 3, 4, "ABCCED"))
        cout<<1<<endl;
    else
        cout<<2<<endl;

    return 0;
}
