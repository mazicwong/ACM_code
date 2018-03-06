#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e3+5;
const ll INF = 0x3f3f3f3f;
const ll mod = 1000000007;
ll mod_pow(ll x,ll n)
{
    ll res=1;
    while(n>0)
    {
        if(n&1)res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}
ll fac[maxn];
void getFactor(ll p)
{
    fac[0]=1;
    for(ll i=1;i<=p;i++)
        fac[i]=(fac[i-1]*i)%p;
}
ll lucas(ll n,ll m,ll p)
{
    ll res=1;
    while(n&&m)
    {
        ll a=n%p,b=m%p;
        if(a<b) return 0;
        res=(res*fac[a]*mod_pow(fac[b]*fac[a-b]%p,p-2))%p;
        n/=p;
        m/=p;
    }
    return res;
}
int main()
{
    int n;cin>>n;
    getFactor(mod);
    ll ans=0;
    for(int num2=1;num2<=n-3;num2++)
    {
        for(int num3=1;num3<=n-num2-2;num3++)
        {
            for(int num0=1;num0<=n-num2-num3-1;num0++)
            {
                int num1=n-num2-num3-num0;
                if(num0+num1<0) continue;
                ans+=lucas(n-1,num0+num1,mod)%mod;
            }
        }
    }
    cout << ans;
    return 0;
}


