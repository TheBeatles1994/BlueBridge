#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

long long count=0;    //记录逆序对个数
/*
 * 函数功能：
 * 数组中的逆序对
 */
vector<int> func(vector<int> vecL, vector<int> vecR)
{
    /* 更新vecL的值 */
    if(vecL.size()>1)
    {
        /* 将vecL分成两部分 */
        vector<int> tempLL,tempLR;
        for(long long i=0;i<vecL.size();i++)
        {
            if(i<vecL.size()/2)
                tempLL.push_back(vecL[i]);
            else
                tempLR.push_back(vecL[i]);
        }
        /* 递归 */
        vecL = func(tempLL,tempLR);
    }
    /* 更新vecR的值 */
    if(vecR.size()>1)
    {
        /* 将vecL分成两部分 */
        vector<int> tempRL,tempRR;
        for(long long i=0;i<vecR.size();i++)
        {
            if(i<vecR.size()/2)
                tempRL.push_back(vecR[i]);
            else
                tempRR.push_back(vecR[i]);
        }
        /* 递归 */
        vecR = func(tempRL,tempRR);
    }

    long long pL,pR,pCopy;
    pL = vecL.size()-1;
    pR = vecR.size()-1;
    pCopy = vecL.size()+vecR.size()-1;
    vector<int> copy(pCopy+1, 0);

    while((pL>=0)&&(pR>=0))
    {
        if(vecL[pL]>vecR[pR])
        {
            count += pR+1;
            count = count % 1000000007;
            copy[pCopy] = vecL[pL];
            pL--;
        }
        else
        {
            copy[pCopy] = vecR[pR];
            pR--;
        }
        pCopy--;
    }
    if(pL>=0)
    {
        for(int i=pL;i>=0;i--)
        {
            copy[pCopy--] = vecL[i];
        }
    }
    if(pR>=0)
    {
        for(int i=pR;i>=0;i--)
        {
            copy[pCopy--] = vecR[i];
        }
    }
    return copy;
}

long long InversePairs(vector<int> data)
{
    vector<int> tempL,tempR;
    for(long long i=0;i<data.size();i++)
    {
        if(i<data.size()/2)
            tempL.push_back(data[i]);
        else
            tempR.push_back(data[i]);
    }
    data = func(tempL,tempR);
    for(auto i:data)
    {
        cout << i<<" ";
    }
    cout<<endl;
    return count;
}

int main()
{
    vector<int> data={4,3,1,2, 5,9,7,6,8};

    cout<<InversePairs(data)<<endl;

    return 0;
}
