#include <bits/stdc++.h>
using namespace std;

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int maxn = 1e5+5;
int arr[maxn];
struct Node{
    int l,r;
    int Sum;
}tr[maxn<<2];
void pushup(int rt)
{
    tr[rt].Sum = tr[rt<<1].Sum+tr[rt<<1|1].Sum;
}
void build(int rt,int l,int r)
{
    tr[rt].l=l; tr[rt].r=r;
    if(l==r)
    {
        tr[rt].Sum=arr[l];
    }
    else
    {
        int mid = (l+r)/2;
        build(rt<<1,l,mid);
        build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
}
void update(int rt,int ql,int qr,int val)
{
    if(ql==tr[rt].l && tr[rt].r==qr)
    {
        if(tr[rt].Sum%val==0)
            tr[rt].Sum/=val;
        return ;
    }
    int mid=(tr[rt].l+tr[rt].r)/2;
    if(qr<=mid)update(rt<<1,ql,qr,val);
    else if(mid<ql)update(rt<<1|1,ql,qr,val);
    else
    {
        update(rt<<1,ql,mid,val);
        update(rt<<1|1,mid+1,qr,val);
    }
    pushup(rt);
}
long long ans=0;
void query(int rt,int ql,int qr)
{
    if(ql==tr[rt].l && tr[rt].r==qr)
    {
        ans += tr[rt].Sum;
        return;
    }
    int mid=(tr[rt].l+tr[rt].r)/2;
    if(qr<=mid)query(rt<<1,ql,qr);
    else if (mid<ql)query(rt<<1|1,ql,qr);
    else
    {
        query(rt<<1,ql,mid);
        query(rt<<1|1,mid+1,qr);
    }
}
int main()
{
    int n,m; 
    n=read(); m=read();
    for(int i=1;i<=n;i++) arr[i]=read();
    build(1,1,n);
    for(int i=0;i<m;i++)
    {
        int flag=read();
        if(flag==2)
        {
            ans=0;
            int l,r; l=read(); r=read();
            query(1,l,r);
            cout<<ans<<endl;
        }
        else
        {
            int l,r,v; l=read(); r=read(); v=read();
            for(int idx=l;idx<=r;idx++)
            {
                update(1,idx,idx,v);
            }
        }
    }
    return 0;
}
