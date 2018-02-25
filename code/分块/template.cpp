#include <bits/stdc++.h>
using namespace std;
//单点更新，找最大
const int maxn = 2e5+5;
int belong[maxn],l[maxn],r[maxn],a[maxn],n,q,Max[maxn];

int block,num;

void build()
{
    block=sqrt(n);
    num=n/block; if(n%block)num++;
    for(int i=1;i<=num;i++)
        l[i]=(i-1)*block+1, r[i]=i*block;
    r[num]=n;
    for(int i=1;i<=n;i++)
        belong[i]=(i-1)/block+1;

    for (int i=1;i<=num;i++)
        for (int j=l[i];j<=r[i];j++)
            Max[i]=max(Max[i],a[j]);
}
void update(int x,int y)
{
    a[x]=y;
    Max[belong[x]]=max(Max[belong[x]],a[x]);
}
int query(int x,int y)
{
    int ans = 0;
    if(belong[x]==belong[y]) //sqrt(n)
    {
        for (int i=x;i<=y;i++)
            ans = max(a[i],ans);
        return ans;
    }
    for(int i=x;i<=r[belong[x]];i++)
        ans = max(ans,a[i]);
    for (int i=belong[x]+1;i<belong[y];i++)
        ans = max(ans,Max[i]);
    for (int i=l[belong[y]];i<=y;i++)
        ans = max(ans,a[i]);
    return ans;
}
int main()
{
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build();
    for (int i=1;i<=q;i++)
    {
        char op;int x,y;
        scanf(" %c%d%d",&op,&x,&y);
        if(op=='U')
            update(x,y);
        else 
            printf("%d\n",query(x,y));
    }
    return 0;
}
