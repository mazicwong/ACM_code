#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

//pow 8line
ll pow_mod(ll x,ll n)
{
    ll res=1;
    while(n>0)
    {
        if(n&1) res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int ans=0;
    if( (m%2!=0 && m%3!=0) || (n%2!=0 && n%3!=0))
    {
        cout<<"0"<<endl;
        return 0;
    }
    if(m==2)
    {
        int num = n/3;
        ans = num*2;
    }
    if(n%3!=0) ans=0;
    cout << ans;

    return 0;
}
