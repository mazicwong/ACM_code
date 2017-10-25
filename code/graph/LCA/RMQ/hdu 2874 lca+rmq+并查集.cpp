/*************************************************************************
	> File Name: hdu2874.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月05日 星期六 00时19分24秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1e4+4;
//森林上每棵树lca
/****************union_find*********************/
int fa[maxn];//并查集所用,记录前驱节点
void init_fa(int n)
{
    for (int i=1;i<=n;i++)
        fa[i]=i;
}
int find(int x)
{
    if (x != fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}
void join(int i,int j)
{
    int x=find(i);
    int y=find(j);
    if (x!=y) fa[y]=x;
}
/****************union_find*********************/




struct edge{
    int to,next;
	int cost;
}e[maxn<<1];

int head[maxn];
int tot=0;//点数

void add(int u,int v,int val){
    e[tot].to=v;
    e[tot].cost=val;
    e[tot].next=head[u];
    head[u]=tot++;
}

//que[]:欧拉序列,即dfs遍历的顺序
int que[maxn<<1];//第i次dfs访问节点的编号[1..2n-1]  (vs[i])
int dep[maxn<<1];//第i次dfs访问节点的深度  
int fir[maxn];//在que数组中i节点首次出现的下标 (id[i])

int p[maxn<<1];
int st[maxn<<1][20];//rmq用来存的,st[i][j]从i开始的2^j个数
int vis[maxn<<1];
int cnt=0;


void dfs(int u,int d)
{
    vis[u]=1;
    que[++cnt]=u;fir[u]=cnt;dep[cnt]=d;
    for (int k=head[u];k!=-1;k=e[k].next)
    {
        int v=e[k].to;
        if (!vis[v])
        {
            p[v]=u;
            dfs(v,d+e[k].cost);
            que[++cnt]=u;dep[cnt]=d;
        }
    }
}
void ST(int n)
{//ST函数,预处理st[i,j],从i开始2^j个数的最小值
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
{//传入两个点在que[]中首次出现位置,然后返回最小值在que[]中位置
//RMQ函数,计算[l,r]中dep[]最小的
    int k=0;
    while((1<<(k+1))<=r-l+1)
        k++;
    int a=st[l][k],b=st[r-(1<<k)+1][k];
    return dep[a]<dep[b]?a:b;
}
int lca(int u,int v)
{//直接找两者中最近祖先
    int x=fir[u],y=fir[v];
    if(x>y) swap(x,y);
    int ans=RMQ(x,y);
    return que[ans];
}

/********************************/
/********************************************/
void init()
{
    tot=0;
    cnt=0;
    p[1]=0;
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
}

int depth(int u)
{//从叶子往上的深度(负数),方便计算
    return dep[fir[u]];
}

int main()
{
    //freopen("in","r",stdin);
    int n,m,q;
    while(scanf("%d%d%d",&n,&m,&q)!=EOF)
    {
        init();
        init_fa(n);
        int u,v,val;
        for (int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&val);
            add(u,v,val);
            add(v,u,val);
            join(u,v);
        }
        //并查集处理
        for (int i=1;i<=n;i++)
        {
            if (vis[i]) continue;
            else dfs(i,1);
        }
        ST(2*n-1);
        int a,b;
        while(q--)
        {
            scanf("%d%d",&a,&b);
            if (find(a)!=find(b))
            {
                puts("Not connected");
                continue;
            }
            int tmp=lca(a,b);
            printf("%d\n",depth(a)+depth(b)-2*depth(tmp));
        }
    }
}
