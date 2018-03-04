#include <bits/stdc++.h>
using namespace std;
//单点更新,区间异或和
const int maxn = 2e5+5;
struct node{
    int l,r;
    int sum;
}tr[maxn*4];
int arr[maxn];
void pushup(int rt)
{
    tr[rt].sum = (tr[rt<<1].sum)^(tr[rt<<1|1].sum);
}
void build(int rt,int l,int r)
{
    //tr[rt].l=l;tr[rt].r=r;
    if(l==r)
    {
        tr[rt].sum = arr[l];
    }
    else
    {
        int mid = (l+r)>>1;
        build(l,mid,rt<<1);
        build(mid+1,r,rt<<1|1);
        pushup(rt);
    }
}
void update(int rt,int l,int r,int val)
{
    if(l==tr[rt].l && tr[rt].r==r)
    {
        tr[rt].sum = val;
    }
    else 
    {
        int mid = (tr[rt].l+tr[rt].r)>>1;
        if(mid<l) update(rt<<1|1,l,r,val);
        else if(mid>=r) update(rt<<1,l,r,val);
        else
        {
            update(rt<<1,l,mid,val);
            update(rt<<1|1,mid+1,r,val);
        }
        pushup(rt);
    }
}
int ans = 0;
int query(int rt,int ql,int qr)
{
    if(ql<tr[rt].l &&tr[rt].r<qr)
    {
        ans ^= tr[rt].sum;
    }
    else
    {
        int mid = (tr[rt].l+tr[rt].r)>>1;
        if(ql>mid) query(rt<<1|1,ql,qr);
        else if(mid>=qr) query(rt<<1,ql,qr);
        else
        {
            query(rt<<1,ql,mid);
            query(rt<<1|1,mid+1,qr);
        }
    }
}

int main()
{
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
    build(1,1,n);
    while(q--)
    {
        char ch;int l,r;
        scanf(" %c%d%d",&ch,&l,&r);
        if(ch=='U')
        {
            update(1,l,l,r);
        }
        else if (ch=='Q')
        {
            ans = 0;
            query(1,l,r);
            cout << ans << endl;
        }
    }
    return 0;
}
