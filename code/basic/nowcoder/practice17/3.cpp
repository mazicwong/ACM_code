#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int maxn = 2000+5;
ll a[maxn];
ll ans[maxn];
ll qmod(ll x,ll n)
{
    ll res=1;
    while(x>0)
    {
        if(n&1) res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}

int main()
{
    ll n,k;
    cin>>n>>k;
    cin>>a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        //a[i]=(1LL*a[i]*(k)+a[i-1])%mod;
    }
    if(k==0)
    {
        for(int i=0;i<n;i++)
            cout << a[i] << ' ';
    }
    ans[0]=a[0];
    for(int i=1;i<n;i++)
    {
        ans[i] = ans[i-1]+a[i] % mod;
    }
    for(int i=0;i<n;i++){
        //ans[i] = a[i];
        for(int j=0;j<i;j++)
        {
            ans[i] = ans[i]+(k-1)*(i-j)*a[i-j-1] % mod;
        }
        cout << ans[i] << ' ';
    }
    return 0;
}

