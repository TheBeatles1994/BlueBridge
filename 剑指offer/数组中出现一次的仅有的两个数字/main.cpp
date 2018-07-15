#include <iostream>
#include <vector>

using namespace std;

pair<int, int> testFunc(vector<int> data)
{
    int rst1=0, rst2=0;

    for(int i=0;i<data.size();i++)
    {
        rst1 = rst1^data[i];
    }

    rst2 = 1;//rst2临时用作下一过程的结果值
    //找出rst1倒数第一个为1的bit位置
    for(int i=1;i<32;i++)
    {
        //int temp = rst1 & rst2;
        if((rst1 & rst2) == rst2)
            break;
        rst2 <<= 1;
    }

    vector<int> temp1, temp2;
    for(int i=0;i<data.size();i++)
    {
        if((data[i] & rst2) == rst2)
            temp1.push_back(data[i]);
        else
            temp2.push_back(data[i]);
    }
    rst1 = (rst2 = 0);
    for(int i=0;i<temp1.size();i++)
    {
        rst1 = rst1^temp1[i];
    }
    for(int i=0;i<temp2.size();i++)
    {
        rst2 = rst2^temp2[i];
    }

    return pair<int, int>(rst1, rst2);
}

int main()
{
    vector<int> data = {1,2,5,3,2,5,4,3,6,9,9,6,1,10,11,11};

    pair<int, int> rst = testFunc(data);

    cout<<rst.first<<" "<<rst.second<<endl;

    return 0;
}
