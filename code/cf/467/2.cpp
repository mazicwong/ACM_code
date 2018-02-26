#include <bits/stdc++.h>
using namespace std;
const int maxn = 52400+5;
bool isprime[maxn];
int yz[maxn];
int cnt = 0;

void getprime(int p)
{
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for (int i=2;i<p;i++)
    {
        if (isprime[i])
        {
            yz[++cnt]=i;
            for (int j=i+i;j<p;j+=i)
                isprime[j]=false;
        }
    }
}

int main()
{
    int p,y; cin>>p>>y; //p<=y
    getprime(min(min(p+1, y/2+1), 52352));
    //for (int i=2;i<=min(p,y/2);i++) if (isprime[i]) yz[++cnt]=i;

    bool flagg=true;
    int ans=-1;
    for (int i=y;i>=p+1;i--)
    {
        flagg=true;
        for (int j=1;j<=cnt;j++)
        {
            if (i%yz[j]==0)
            {
                flagg=false;
                break;
            }
        }
        if (flagg==true) 
        {
            ans = i;
            break;
        }
    }
    cout << ans;


    /*
getprime(10000);
set<int> ss;
for (int kk=1000000000;kk>=999999000;kk--)
{
    int y=kk;
    bool flagg=true;
    int ans=-1;
    for (int i=y;i>=10000+1;i--)
    {
        flagg=true;
        for (int j=1;j<=cnt;j++)
        {
            if (i%yz[j]==0)
            {
                flagg=false;
                break;
            }
        }
        if (flagg==true)
        {
            ans = i;
            break;
        }
    }
    ss.insert(ans);
}
for (set<int>::iterator it=ss.begin();it!=ss.end();it++)
    cout << *it<<endl;
    */
    return 0;
}
