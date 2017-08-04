/*************************************************************************
	> File Name: hdu2586.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月04日 星期五 20时33分45秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
/*
 * 给一颗无根树,q个询问,每次问两个节点间的距离
 * 因为是树,所以是单向的,不用最短路算法(图)
 */
const int maxn = 40000+5;

struct edge{
    int to;
    int next;
    int cost;
}e[maxn<<1];
int head[maxn];
int tot=0;
void add(int u,int v,int w)
{
    e[tot].to=v;
    e[tot].cost=w;
    e[tot].next=head[u];
    head[u]=tot++;
}

int que[maxn<<1];//第i次dfs访问节点的编号[1..2n-1]  (vs[i])
int dep[maxn<<1];//第i次dfs访问节点的深度  
int fir[maxn];//在que数组中i节点首次出现的下标 (id[i])
int vis[maxn<<1];//dfs中是否访问过节点

int p[maxn<<1];//每个点的父节点
int st[maxn<<1][20];//rmq用来存的,st[i][j]从i开始的2^j个数
int cnt=0;
int height[maxn];

void dfs(int u,int d)//传入点跟深度
{
    vis[u]=1;
    que[++cnt]=u;fir[u]=cnt;dep[cnt]=d;
    for (int k=head[u];k!=-1;k=e[k].next)
    {
        int v=e[k].to;
        if (!vis[v])
        {
            p[v]=u;
            dfs(v,d+e[k].cost);//小改
            que[++cnt]=u;dep[cnt]=d;
        }
    }
}
void ST(int n)
{
    for(int i=1;i<=n;i++)
        st[i][0]=i;
    for(int j=1;(1<<j)<=n;j++)
	{
        for(int i=1;i+(1<<j)-1<=n;i++)
		{
            int a=st[i][j-1],b=st[i+(1<<(j-1))][j-1];
            st[i][j]=dep[a]<dep[b]?a:b;
        }
    }
}
int RMQ(int l,int r)
{
    int k=0;
    while((1<<(k+1))<=r-l+1)
        k++;
    int a=st[l][k],b=st[r-(1<<k)+1][k];
    return dep[a]<dep[b]?a:b;
}
int lca(int u,int v)
{
    int x=fir[u],y=fir[v];
    if(x>y) swap(x,y);
    int ans=RMQ(x,y);
    return que[ans];
}
void init()
{
    tot=0;
    cnt=0;
    p[1]=0;
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
}

int depth(int u)
{//从叶子往上的深度,方便计算
    return dep[fir[u]];
}


int main()
{
    freopen("in","r",stdin);
    int t;
    cin >> t;
    while(t--)
    {
        init();
        int n,q;
        scanf("%d%d",&n,&q);
        int a,b,val;
        for (int i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&a,&b,&val);
            add(a,b,val);
            add(b,a,val);
        }
        dfs(1,1);
        ST(2*n-1);
        int u,v;
        while(q--)
        {
            scanf("%d%d",&u,&v);
            int tmp=lca(u,v);
            printf("%d\n",depth(u)+depth(v)-2*depth(tmp));
        }
    }
    return 0;
}
