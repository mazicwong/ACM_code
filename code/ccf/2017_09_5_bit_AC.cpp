#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5+5;
ll c[maxn];  //存区间和(tr[maxn])
ll arr[maxn];//初始值
ll n;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//满足区间减法都可以用,然后更新操作在main中解决就行
//arr[i] = 1,2,3,4, 5,6, 7,8
//c[i]   = 1,3,3,10,5,11,7,36
ll lowbit(ll x){return x&-x;} //返回2^k
void add(ll i,ll val)
{
    while(i<=n)
    {
        c[i]+=val;
        i+=lowbit(i);
    }
}
ll sum(ll i)
{
    ll ans=0;
    while(i>0)
    {
        ans+=c[i];
        i-=lowbit(i);
    }
    return ans;
}
int main()
{
    ll m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        arr[i]=read();
        add(i,arr[i]);
    }
    //for(ll i=1;i<=n;i++) cout << c[i] << endl;
    while(m--)
    {
        ll flag=read();
        if(flag==2)
        {
            ll l,r;
            l=read(); r=read();
            cout<<sum(r)-sum(l-1)<<endl;
        }
        else
        {
            ll l,r,v;
            l=read();r=read();v=read();
            if(v==1)continue;
            for(ll i=l;i<=r;i++)
            {
                if(arr[i]>=v && arr[i]%v==0)
                {
                    add(i,arr[i]/v-arr[i]);
                    arr[i]/=v;
                }
            }
            //for(ll i=1;i<=n;i++) cout << c[i] << endl;
        }
    }
    return 0;
}
