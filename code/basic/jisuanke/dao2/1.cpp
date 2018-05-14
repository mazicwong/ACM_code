#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+5;
int a[maxn];
struct node{
    int l,r;
    int val;
}tr[maxn*4];
void pushup(int rt)
{
    tr[rt].val = max(tr[rt<<1].val, tr[rt<<1|1].val);
}
void build(int rt,int l,int r)
{
    tr[rt].l=l; tr[rt].r=r;
    if(l==r)
    {
        tr[rt].val=0;
    }
    else
    {
        int mid = (l+r)>>1;
        build(rt<<1,l,mid);
        build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
}
int ans = 0;
void update(int rt,int ql,int qr,int val)
{
    if(ql<=tr[rt].l && tr[rt].r<=qr)
    {
        tr[rt].val++;
        ans = max(ans,tr[rt].val);
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

void query(int rt,int ql,int qr)
{
    if(ql==tr[rt].l && tr[rt].r==qr)
    {
        ans = max(ans, tr[rt].val);
        return;
    }
    int mid = (tr[rt].l+tr[rt].r)/2;
    if(qr<=mid) query(rt<<1,ql,qr);
    else if(mid<ql) query(rt<<1|1,ql,qr);
    else
    {
        query(rt<<1,ql,mid);
        query(rt<<1|1,mid+1,qr);
    }
}

int main()
{
    int t;cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int maxx = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            maxx = max(maxx,a[i]);
        }
        ans = 0;
        build(1,1,maxx+d);
        for(int i=0;i<n;i++){
            //cout << "maxx: " << max(1,a[i]-d) << "  minn: " << min(maxx+d,a[i]+d) << endl;
            update(1,max(1,a[i]-d),min(maxx,a[i]+d),a[i]);
        }
        cout << ans << endl;
        /*
        for(int i=0;i<n;i++){
            ans = 0;
            query(1,a[i],a[i]);
            cout << i << "  " << ans  <<"  " << tr[i].val << endl;
        }
        */
    }
    return 0;
}
