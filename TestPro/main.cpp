#include<iostream>
#include<algorithm>
#include<vector>
#include<ratio>

using namespace std;
int n,m;
int a1,a2,p,q;
bool zheng;

int MaxFactor(int n1,int n2)//用来寻找最大公因子，欧几里德算法
{
    if(n1<0)
        n1=-n1;

    int th=n1,tl=n2;
    if(n1<n2)
    {
        th=n2;
        tl=n1;
    }
    if(th%tl==0)
        return tl;
    else
        return MaxFactor(tl,th%tl);
}

int main(int argc, char *argv[])
{
    while(cin>>n>>m)
    {
        int fm,fz;
        fm=0;
        fz=0;
        for(int i=0;i<n;i++)
        {
            zheng=true;
            cin>>a1>>a2>>p>>q;
            int ffz,ffm;
            ffz=-a1*p+a2*(q-p);
            if(ffz<0)
            {
                ffz = -ffz;
                zheng=false;
            }
            ffm=q;
            if(ffm!=fm)
            {
                if(ffz!=0)
                {
                    if(fm==0)
                    {
                        fz=(zheng?ffz:-ffz);
                        fm=ffm;
                    }
                    else
                    {
                        fz = (zheng? fz*ffm+fm*ffz:-ffz*fm+fz*ffm);
                        fm = fm*ffm;
                    }
                    if(fz != 0)
                    {
                        int temp = MaxFactor(fz,fm);
                        fz /= temp;
                        fm/=temp;
                    }
                }
            }
        }
        if(fz>=0)
        {
            if(fz>fm)
            {
                m += fz/fm;
                fz -= (fz/fm) * fm;

            }
            if(fz!=0)
                cout<<m<<"+"<<fz<<"/"<<fm<<endl;
            else
                cout<<m<<endl;
        }
        else
        {
            if(-fz>fm)
            {
                m -= (-fz)/fm;
                fz += (-fz/fm) * fm;
                if(fz==0)
                {
                    cout<<m<<endl;
                }
                else
                {
                    m -= 1;
                    fz = fm+fz;
                    cout<<m<<"+"<<fz<<"/"<<fm<<endl;
                }
            }
            else if(-fz == fm)
            {
                m -= 1;
                fz = 0;
                cout<<m<<endl;
            }
            else
            {
                m -= 1;
                fz = fm+fz;
                cout<<m<<"+"<<fz<<"/"<<fm<<endl;
            }
        }

    }

    return 0;
}

