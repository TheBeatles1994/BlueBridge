#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

void reOrderArray(vector<int> &array) {
#if 0
    int left=0;
    int right=0;

    while(right<array.size())
    {
        if(array[right] & 1 == 1)   //奇数
        {
            left++;
            right++;
            continue;
        }
        else                        //偶数
        {

        }
    }
#else
    vector<int> oddV;
    queue<int> evenQ;
    for(auto it=array.begin();it!=array.end();it++)
    {
        if(*it & 1 == 1)
            oddV.push_back(*it);
        else
            evenQ.push(*it);
    }
    int len = evenQ.size();
    for(int i=0;i<len;i++)
    {
        oddV.push_back(evenQ.front());
        evenQ.pop();
    }
    array.swap(oddV);
#endif
}

int main(int argc, char *argv[])
{
    vector<int> array;
    int n;

    cin>>n;
    while(n--)
    {
        int temp;
        cin>>temp;
        array.push_back(temp);
    }

    reOrderArray(array);

    for(auto it = array.begin();it!=array.end();it++)
        cout<<*it<<" ";


//    while(cin>>e>>n)
//    {
//        cout<<Power(e,n)<<endl;
//    }

    return 0;
}

