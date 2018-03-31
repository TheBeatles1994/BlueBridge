#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

vector<int> globalVec;
vector<vector<int> > globalFlag;

void func(vector<vector<int> > matrix, int dir, int x, int y)
{
    if(x>= globalFlag.size() || y>= globalFlag[0].size() || x<0 || y<0)       //递归终止条件
        return;
    if(globalFlag[x][y] == 1)       //递归终止条件
        return;
    int i, j;

    switch (dir%4) {
    case 0:
        for(j=y;j<globalFlag[x].size();j++)
        {
            if(globalFlag[x][j] == 1)
            {
                break;
            }
            globalVec.push_back(matrix[x][j]);
            globalFlag[x][j] = 1;
        }
        func(matrix, (dir+1), x+1, j-1);
        break;
    case 1:
        for(i = x;i<globalFlag.size();i++)
        {
            if(globalFlag[i][y] == 1)
            {
                break;
            }
            globalVec.push_back(matrix[i][y]);
            globalFlag[i][y] = 1;
        }
        func(matrix, (dir+1), i-1, y-1);
        break;
    case 2:
        for(j = y;j>=0;j--)
        {
            if(globalFlag[x][j] == 1)
            {
                break;
            }
            globalVec.push_back(matrix[x][j]);
            globalFlag[x][j] = 1;
        }
        func(matrix, (dir+1), x-1, j+1);
        break;
    case 3:
        for(i = x;i>=0;i--)
        {
            if(globalFlag[i][y] == 1)
            {
                break;
            }
            globalVec.push_back(matrix[i][y]);
            globalFlag[i][y] = 1;
        }
        func(matrix, (dir+1), i+1, y+1);
        break;
    default:
        break;
    }
}

vector<int> printMatrix(vector<vector<int> > matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> tempVec(m, 0);
    vector<vector<int> > tempVV(n, tempVec);
    globalFlag.swap(tempVV);

    func(matrix, 0, 0, 0);

    return globalVec;
}

int main(int argc, char *argv[])
{
    int n, m;
    cin >>n>>m;

    vector<vector<int> > vecVecValue;
    vector<int> vecValue;
    int temp;

    for(int i=0;i<n;i++)
    {
        vector<int>().swap(vecValue);
        for (int j=0;j<m;j++)
        {
            cin>>temp;
            vecValue.push_back(temp);
        }
        vecVecValue.push_back(vecValue);
    }
    vecValue = printMatrix(vecVecValue);
    for(auto it : vecValue)
    {
        cout<< it <<" ";
    }

    return 0;
}

