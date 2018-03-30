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
#include <time.h>
using namespace std;
int n,m;
const int maxn = 1e5+5;
int arr[maxn];
struct node{
    int l,r;
    int maxx;
    int st;
}tr[maxn<<2];
void pushup(int rt)
{
    tr[rt].maxx = max(tr[rt<<1].maxx, tr[rt<<1|1].maxx);
    tr[rt].st = tr[rt<<1].st | tr[rt<<1|1].st;
}
void build(int rt,int l,int r)
{
    tr[rt].l=l; tr[rt].r=r;
    if(l==r)
    {
        tr[rt].maxx=arr[l];
        tr[rt].st=(1<<arr[l]);
        return;
    }
    else
    {
        int mid=(l+r)>>1;
        build(rt<<1,l,mid);
        build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
}
/*
void update(int rt,int ql,int qr)
{
    if(tr[rt].l<=ql && qr<=tr[rt].r)
    {
        tr[rt].l=1;
    }
    int mid=(tr[rt].l+tr[rt].r)/2;
    if(ql>mid) update(tr[rt].)
}
*/
int ans=-0x3f3f3f3f;
int st=0;
void query(int rt,int ql,int qr)
{
    if(ql<=tr[rt].l && tr[rt].r<=qr)
    {
        ans=max(ans,tr[rt].maxx);
        st=st | tr[rt].st;
        return;
    }
    int mid=(tr[rt].l+tr[rt].r)/2;
    if(qr<=mid) query(rt<<1,ql,qr);
    else if(ql>mid) query(rt<<1|1,ql,qr);
    else
    {
        query(rt<<1, ql, mid);
        query(rt<<1|1,mid+1,qr);
    }
}
long long get_st(int st)
{
    int res=0;
    while(st>0)
    {
        res += (st&1);
        st>>=1;
    }
    return res;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    int q; cin>>q;
    while(q--)
    {
        int l,r; cin>>l>>r;
        if(l>r) swap(l,r);
        ans=-0x3f3f3f3f;
        st=0;
        query(1,l,r);
        long long num=get_st(st);
        cout<<1LL*ans*num<<endl;
    }
    return 0;
}
