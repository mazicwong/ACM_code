/*************************************************************************
	> File Name: 1010.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月01日 星期二 12时08分21秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int maxn = 500000+50;
const int INF = 0x3f3f3f3f;
int arr[maxn];
int n,k;

struct edge{  //(u,v)边  
    int to;   //这条边指向的节点(v点)
    int next; //这条边的上一条边(邻接到u点的边)
}e[maxn<<1];  //e[0...2n-3] 树e=n-1

int head[maxn];//存每个点遍历到的最后一个儿子 
int tot=0;//存边
void add(int u,int v){  
    e[tot].to=v;
    e[tot].next=head[u];//next存上一次访问u点的时间,用来回溯时找到u的所有边   
    head[u]=tot++;//head[u]存每次访问的时间,最终是最后一次访问u的时间
}  
  
int que[maxn<<1];//dfs存遍历顺序 [1...2n-1]
int fir[maxn];//i在que中首次出现的下标
int dep[maxn<<1];//i点深度
int p[maxn];//每个点父节点
int st[maxn<<1][20];//st[i,j]:  i开始的2^j的最小
int vis[maxn<<1];
int cnt=0;
  
void dfs(int u,int d)//传入点跟深度
{//递归得到que[1..2n-1],fir[1..n],dep[1..n]
    vis[u]=1;
    que[++cnt]=u;fir[u]=cnt;dep[cnt]=d;//dep[cnt]=d是dep[1..2n-1];dep[u]=d是直接该点深度
    for(int k=head[u];k!=-1;k=e[k].next)//head[u].u点指向的最后一条边
    {
        int v=e[k].to;
        if(!vis[v])
        {
            p[v]=u;  
            dfs(v,d+1);  
            que[++cnt]=u;dep[cnt]=d;//访问完一个子树,自己要再次入队,但是fir[]不用更新,
        }  
    }
}
void ST(int n){  
    for(int i=1;i<=n;i++)  
        st[i][0]=i;  
    for(int j=1;(1<<j)<=n;j++){  
        for(int i=1;i+(1<<j)-1<=n;i++){  
            int a=st[i][j-1],b=st[i+(1<<(j-1))][j-1];  
            st[i][j]=dep[a]<dep[b]?a:b;  
        }  
    }  
}
int RMQ(int l,int r){  
    int k=0;  
    while((1<<(k+1))<=r-l+1){  
        k++;  
    }  
    int a=st[l][k],b=st[r-(1<<k)+1][k];  
    return dep[a]<dep[b]?a:b;  
}
int lca(int u,int v)
{//LCA(T,u,v) = RMQ(dep,fir[u],fir[v])
    int x=fir[u],y=fir[v];  
    if(x>y)  swap(x,y);
    int res=RMQ(x,y);//lca转换为rmq,由que[]中的lca,转换为fir[]中的rmq 
    return que[res];  
}


void init(){  
    tot=0;  
    cnt=0;  
    p[1]=0;  
    memset(head,-1,sizeof(head));  
    memset(vis,0,sizeof(vis));  
    memset(st,0,sizeof(st));
} 

inline int toInt(int k,int i)
{
    return k*(n+1)+i;
}

int depth(int u)
{
    return dep[fir[u]];
}

int dp[maxn<<1];
int main()
{
    freopen("in","r",stdin);
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        int g[maxn];
        init();
        for (int i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        int a,b;
        for (int i=0;i<n-1;i++)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
            add(b,a);
        }
        dfs(1,1);//1开始,深度为1
        ST(2*n-1);//st
        /*
         *
         * que[1..2n-1]  dfs结果 
         * first[]  i在que中首次出现的下标
         *
         * dep[]  该点深度
         */
        
/**/
        
       /*
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<=k;j++)
            {
                int tt=INF;
                if (j>i) break;
                if (i-1>=j)//第k块中没有贡献
                    tt=min(tt,dp[toInt(i-1,j)]);
                if (i-1>=j-1 && j-1>=0)//单独作为第k块
                    tt=min(tt,dp[toInt(i-1,j-1)]+depth(arr[i]));
                if (i-2>=j-1 && i-2>=0 && j-1>=0)//第k块中但有贡献
                    tt=min(tt,dp[toInt(i-2,j-1)]+lca(arr[i],arr[i-1]));
                dp[toInt(i,j)]=tt;
            }
        }
        printf("%d\n",dp[toInt(n,k)]);*/



        
/**/
        
        
        //太暴力了..TLE..
        memset(dp,0,sizeof(dp));
        dp[toInt(1,1)]=depth(arr[1]);
        for (int i=2;i<=n;i++)
            dp[toInt(i,1)]=lca(dp[toInt(i-1,1)], arr[i]);
        for (int j=2;j<=k;j++)
        {
            for (int i=1;i<=n;i++)
            {
                memset(g,0,sizeof(g));
                g[i]=depth(arr[i]);
                int ttt = INF;
                for (int len=2;i-len>=j-1;len++)
                {
                    g[i-len+1]=lca(g[i-len+1+1],arr[i-len+1]);//g[i]:i到当前位置的lca
                    ttt = min(ttt, dp[toInt(i-len,j-1)]+g[i-len+1]);
                }
                dp[toInt(i,j)]=min(ttt, dp[toInt(i-1,j-1)]+depth(arr[i]));
            }
        }
        printf("%d\n",dp[toInt(n,k)]);
        

        /*cout << "lca(4 6 )"  << lca(4,6) << endl;
        cout << "lca(2 5 )"  << lca(2,5) << endl;
        cout << "lca(5 6 )"  << lca(5,6) << endl;*/
    }
    return 0;
}
