#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
//int a[maxn];
int n;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

struct node{
	int x,id;
}a[maxn];
int bel[maxn],root[maxn];
bool comp(const node &p,const node &q){return p.x<q.x;}
struct Tree{
    int ls,rs,sum;
}t[maxn*20];
int tot=0;
void insert(int &rt,int fa,int x,int l,int r)
{
    rt=++tot;
    t[rt].sum=t[fa].sum;
    t[rt].sum++;
    if(l==r)return ;
    int mid=(l+r)>>1;
    if(x<=mid)
    {
        insert(t[rt].ls,t[fa].ls,x,l,mid);
        t[rt].rs=t[fa].rs;
    }
    else
    {
        insert(t[rt].rs,t[fa].rs,x,mid+1,r);
        t[rt].ls=t[fa].ls;
    }
}
int query(int rt,int fa,int k,int l,int r)
{
    if(l==r)return a[l].x;
    int mid=(l+r)>>1,kt=t[t[rt].ls].sum-t[t[fa].ls].sum;
    if(k<=kt)return query(t[rt].ls,t[fa].ls,k,l,mid);
    else return query(t[rt].rs,t[fa].rs,k-kt,mid+1,r);
}

int num[maxn];
const int jiu=1e9;

int main()
{
    //freopen("in","r",stdin);
    n = read();
    for(int i=1;i<=n;i++)
    {
        num[i] = read();
        a[i].x = num[i];
        a[i].id = i;
    }
    sort(a+1,a+n+1,comp);
    for(int i=1;i<=n;i++)bel[a[i].id]=i;
    for(int i=1;i<=n;i++)insert(root[i],root[i-1],bel[i],1,n);
    long long ans = 0;
    for(int i=1;i<=n;i++)
    {
        //[x,y],z;
        //int tmp = query(root[y],root[x-1],z,1,n);
        int left=i;
        int right=min(num[i],n);
        int z = i; // [left,right] <= z
        if(num[i]<=i) continue; 
        int len = right-left+1;
        int ls=1; int rs=len;
        while(ls<rs)
        {
            int mid = (ls+rs)/2;
            if(query(root[right],root[left],mid,1,n)>z) rs=mid;
            else ls=mid+1;
        }
        //int qq = query(root[right],root[left],ls,1,n);
        ans += ls;
    }
    cout << ans;
    return 0;
}
