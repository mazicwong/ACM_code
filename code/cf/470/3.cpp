#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
typedef long long ll;
ll a[maxn],b[maxn];
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
    int n;cin>>n;
    priority_queue<ll,vector<ll>, greater<ll> > Q;
    ll ans = 0;
    ll tmp_num=0;
    for(int i=0;i<n;i++)a[i]=read();
        //scanf("%lld",&a[i]);
    for(int i=0;i<n;i++)b[i]=read();
        //scanf("%lld",&b[i]);
    for(int i=0;i<n;i++)
    {
        ans = 0;
        Q.push(a[i]+tmp_num);
        while(!Q.empty())
        {
            ll tmp = Q.top();
            if(tmp-tmp_num>b[i]) break;
            Q.pop();
            ans += (tmp-tmp_num);
        }
        ans += 1LL*(Q.size())*b[i];
        tmp_num += b[i];
        if(i==n-1)printf("%lld",ans);
        else printf("%lld ",ans);
    }

    return 0;
}
