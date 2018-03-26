#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef long long ll;
const ll maxn = 1e5+5;
ll a[maxn];
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll sum[maxn];
ll xo[maxn];
int main()
{
    ll n,q; n=read(); q=read();
    for(ll i=1;i<=n;i++) a[i]=read();
    while(q--)
    {
        ll l,r,c;
        l=read();r=read();c=read();
        sum[l]+=c;
        sum[r+1]-=c;
        //flag_xo[l]=1; flag_xo[r]=-1;
        xo[l]^=c;
        xo[r+1]^=c;
    }
    ll over_xor=0;
    ll over_sum=0;
    ll ans1=0;ll ans2=0;
    for(ll i=1;i<=n;i++)
    {
        over_xor ^= xo[i];
        over_sum += sum[i];
        if(i%2==0)
            a[i]^=over_xor;
        else 
            a[i]+=over_sum;
        ans1+=a[i];
        ans2^=a[i];
    }
    cout<<ans1<<' '<<ans2;
    return 0;
}
