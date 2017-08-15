/*************************************************************************
	> File Name: 832D.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月30日 星期日 22时19分46秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;

struct edge{
    int to,next;
}e[maxn<<1];

int head[maxn];
int tot=0;//点数

void add(int u,int v){
    e[tot].to=v;
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
            dfs(v,d+1);
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
	{
        k++;
    }
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
/*struct path{
	int u,v;
	int lca;
}pa[maxn];

int cmp(path x,path y)
{
    return dep[fir[x.lca]]>dep[fir[y.lca]];
}
int used[maxn];*/
/********************************************/
void init()
{
    tot=0;
    cnt=0;
    p[1]=0;
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    //memset(used,0,sizeof(used));
}

int depth(int u)
{//从叶子往上的深度(负数),方便计算
    return -dep[fir[u]];
}

int L[3];

int main()
{
    freopen("in","r",stdin);
    int n,q;
    scanf("%d%d",&n,&q);
    init();
    int u;
    for (int i=2;i<=n;i++)
    {
        scanf("%d",&u);
        add(i,u);
        add(u,i);
    }
    dfs(1,1);
    ST(2*n-1);

    int a,b,c;
    while(q--)
    {
        int ans=0;
        scanf("%d%d%d",&a,&b,&c);
        L[0]=lca(a,b);
        L[1]=lca(a,c);
        L[2]=lca(b,c);
        if (L[0]==L[1] && L[0]==L[2])
        {//三个lca都一样
            ans=max(ans,depth(L[0])-depth(a));
            ans=max(ans,depth(L[0])-depth(b));
            ans=max(ans,depth(L[0])-depth(c));
        }
        else
        {
            //把L[2]换成非最上面的lca,L[0]变成最上面的lca
            if (L[1]==L[2])//ac,bc
            {
                swap(a,c);
                swap(L[0],L[2]);
            }
            else if (L[0]==L[2])//ab,bc
            {
                swap(a,b);
                swap(L[1],L[2]);
            }
            ans = max(ans,2*depth(L[0]) - depth(a) - depth(L[2]));

            if(L[2]==b)
            {
                ans=max(ans,depth(b)-depth(c));  
            }
            else if(L[2]==c)
            {
                ans=max(ans,depth(c)-depth(b));  
            }
            else  
                ans=max(ans,max(depth(L[2])-depth(b),depth(L[2])-depth(c)));  
        }
        printf("%d\n",ans+1);
    }
    return 0;
}
