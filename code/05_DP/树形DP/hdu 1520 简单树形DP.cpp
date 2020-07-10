/*************************************************************************
	> File Name: 1520.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月16日 星期三 23时03分31秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
/*
 * 状态:
 * dp[i,0]: 不取i点时的最大
 * dp[i,1]: 取i点时的最大
 *
 * 转移:
 * dp[i,0] += max{dp[j][0],dp[j][1]}
 * dp[i,1] += dp[j,0]
 * 其中j为i的所有儿子
 *
 * dfs结果,max{dp[root,0],dp[root,1]}
 * 
 */

const int maxn = 6000+5;

int dp[maxn][2];
int fa[maxn];
int in[maxn];
bool vis[maxn];
int n;

struct node{
    int v;
    int next;
}e[maxn<<1];

int cnt,head[maxn];

void addedge(int u,int v)
{
    e[cnt].v=v;
    e[cnt].next=head[u];
    head[u]=cnt++;
}

void dfs(int u)
{
    vis[u]=true;
    for(int i=head[u];i!=-1;i=e[i].next)
    {
       // if (!vis[i])
       // {
            int v=e[i].v;
            dfs(v);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
       // }
    }
}
int main()
{
    freopen("in","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        memset(in,0,sizeof(in));
        cnt=0;
        memset(head,-1,sizeof(head));

        for (int i=1;i<=n;i++)
            scanf("%d",&dp[i][1]);//边界
        
        int u,v;
        while(scanf("%d%d",&v,&u)!=EOF && v && u)
        {
            addedge(u,v);
            in[v]++;
        }
        for (int i=1;i<=n;i++)
        {
            if (in[i]==0)//root
            {
                dfs(i);
                printf("%d\n",max(dp[i][0],dp[i][1]));
                break;
            }
        }
    }
    return 0;
}
