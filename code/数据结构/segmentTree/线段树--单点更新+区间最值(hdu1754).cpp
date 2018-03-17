#include <bits/stdc++.h>
using namespace std;
/*
 * problem :hdu 1754
 * 单点更新(加),区间查询(找最值)
 *
 * 输入: arr[]存叶子节点  (1...n)
 * build()  建树
 * update() 更新值
 * query()  查询最值
 */
//1.不要忘了建树
//2.左移优先级小于加号,右儿子写成了tr[rt].r<<1+1调试半天
const int maxn = 1e5+5;
struct node{
    int l,r;
    int val;
}tr[maxn*4];
int a[maxn];

void pushup(int rt)
{
    tr[rt].val = max(tr[rt<<1].val, tr[rt<<1|1].val);
}

void build(int rt,int l,int r)
{
    tr[rt].l=l; tr[rt].r=r;
    if(l==r)
    {
        tr[rt].val=a[l];
    }
    else
    {
        int mid = (l+r)>>1;
        build(rt<<1,l,mid);
        build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
}

void update(int rt,int ql,int qr,int val)
{
    if(ql==tr[rt].l && tr[rt].r==qr) //单点更新
    {
        tr[rt].val = val;
        return ;
    }
    
    int mid = (tr[rt].l+tr[rt].r)/2;
    if(qr<=mid) update(rt<<1,ql,qr,val);
    else if(mid<ql) update(rt<<1|1,ql,qr,val);
    else
    {
        update(rt<<1,ql,mid,val);
        update(rt<<1|1,mid+1,qr,val);
    }
    pushup(rt);
}
int ans = 0x3f3f3f3f;
void query(int rt,int ql,int qr)
{
    if(ql<=tr[rt].l && tr[rt].r<=qr)
    {
        ans = max(ans, tr[rt].val);
        return;
    }
    int mid = (tr[rt].l+tr[rt].r)/2;
    if(qr<=mid) query(rt<<1,ql,qr);
    else if(mid<ql) query(rt<<1|1,ql,qr); //<=
    else
    {
        query(rt<<1,ql,mid);
        query(rt<<1|1,mid+1,qr);
    }
}

int main()
{
    int n,q;cin>>n>>q;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    build(1,1,n);
    char str[5];
    while(q--)
    {
        scanf("%s",str);
        if(str[0]=='U')
        {

        }
        else if (str[0]=='Q')
        {
            
        }
    }
    return 0;
}
