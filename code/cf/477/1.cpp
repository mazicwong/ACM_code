#include <bits/stdc++.h>
using namespace std;
int nowh,nowm;
int preh,prem;
int calc()
{
    int delh=nowh-preh;
    int delm=nowm-prem;
    if(delm<0){
        delm+=60;
        delh-=1;
    }
    return delh*60+delm;
}

int main()
{
    int n,s; cin>>n>>s;
    cin>>preh>>prem;
    if(preh*60+prem>=s+1)
    {
        for(int i=1;i<n;i++)
        {
            cin>>nowh>>nowm;
        }
        cout << "0 0";
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        cin>>nowh>>nowm;
        int tmp = calc();
        if(tmp>=2*(s+1))
        {
            nowm=prem+s+1;
            if(nowm>=60){
                preh+=(nowm/60);
                nowm%=60;
            }
            cout<<preh << ' ' << nowm;
            return 0;
        }
        else
        {
            preh=nowh;
            prem=nowm;
        }
    }
            nowm=nowm+s+1;
            if(nowm>=60){
                nowh+=(nowm/60);
                nowm%=60;
            }
            cout<<nowh << ' ' << nowm;   

    return 0;
}
