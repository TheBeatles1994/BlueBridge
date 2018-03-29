#include<iostream>
#include<algorithm>

using namespace std;

double Power(double base, int exponent) {
    if(exponent==0)
        return 1;
    else if(exponent>0)
    {
        int rst = base;
        while(exponent>1)
        {
            rst *= base;
            exponent--;
        }
        return rst;
    }
    else
    {
        double rst = 1/base;
        exponent = abs(exponent);
        while(exponent>1)
        {
            rst *= 1/base;
            exponent--;
        }
        return rst;
    }

}

int main(int argc, char *argv[])
{
    int n;
    double e;

    while(cin>>e>>n)
    {
        cout<<Power(e,n)<<endl;
    }

    return 0;
}

