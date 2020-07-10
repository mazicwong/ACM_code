/*************************************************************************
	> File Name: poj3268.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月20日 星期四 18时34分47秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1000+5;
const int INF = 0x3f3f3f3f;
bool vis[maxn];
int dist1[maxn];
int dist2[maxn];
int cost[maxn][maxn];

void dijkstra(int cost[][maxn],int dist[],int n,int beg)
{
    for (int i=1;i<=n;i++)
    {
        dist[i]=INF;
        vis[i]=false;
    }
    dist[beg]=0;
    for (int j=0;j<n;j++)
    {
        int cnt = -1;
        int minn = INF;
        for (int i=1;i<=n;i++)
        {
            if (!vis[i] && dist[i]<minn)
            {
                minn = dist[i];
                cnt = i;
            }
        }
        if (cnt == -1) break;
        vis[cnt] = 1;
        for (int i=1;i<=n;i++)
            if (!vis[i] && dist[cnt]+cost[cnt][i]<dist[i])
                dist[i] = dist[cnt]+cost[cnt][i];
    }
}

int main()
{
    freopen("in","r",stdin);
    int n,m,x;
    while(scanf("%d%d%d",&n,&m,&x)!=EOF)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if(i==j) cost[i][j]=0;
                else cost[i][j]=INF;
            }
        }
        int u,v,w;
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            cost[u][v] = min(cost[u][v],w);
        }
        dijkstra(cost,dist1,n,x);
        for (int i=1;i<=n;i++)
            for (int j=1;j<i;j++)
                swap(cost[i][j],cost[j][i]);
        dijkstra(cost,dist2,n,x);
        int ans = 0;
        for (int i=1;i<=n;i++)
            ans = max(ans,dist1[i]+dist2[i]);
        printf("%d\n",ans);
    }
    return 0;
}
