#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;
/*
 * 函数功能：
 * 对一串数或一串字符进行排列组合，其中考虑了重复的数据
 */
template<typename T>
void recurFunc(T &saveData, T &remainData, vector<T > &vT)
{
    if(remainData.size() == 0)
    {
        vT.push_back(saveData);
        return;
    }
    T saveDataTemp(saveData);
    T remainDataTemp(remainData);
    for(auto it=remainData.begin();it!=remainData.end();it++)
    {
        if(it!=remainData.begin())
        {
            auto itTemp = find(remainData.begin(),remainData.end(), *it);
            if(itTemp != it)
                continue;
        }
        saveDataTemp.push_back(*it);
        auto itTemp = find(remainDataTemp.begin(), remainDataTemp.end(), *it);
        remainDataTemp.erase(itTemp);
        recurFunc(saveDataTemp, remainDataTemp, vT);
        saveDataTemp = saveData;
        remainDataTemp = remainData;
    }
    return;
}
template<typename T>
vector<T > permutation(T vData)
{
    if(vData.size()==0)
        return vector<T >();
    sort(vData.begin(), vData.end());
    T saveDataTemp;
    T remainDataTemp(vData);
    vector<T > vT;
    recurFunc(saveDataTemp, remainDataTemp, vT);
    return vT;
}

int main(int argc, char *argv[])
{
    vector<int> data={};
    vector<vector<int> > vvData = permutation(data);
    for(int i=0;i<vvData.size();i++)
    {
        for(int j=0;j<vvData[0].size();j++)
        {
            cout << vvData[i][j]<<" ";
        }
        cout <<endl;
    }

    string str = "";
    vector<string> vvStr = permutation(str);
    for(int i=0;i<vvStr.size();i++)
    {
        cout<< vvStr[i]<<endl;
    }

    return 0;
}

