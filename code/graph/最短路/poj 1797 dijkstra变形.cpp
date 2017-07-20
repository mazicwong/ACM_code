/*************************************************************************
	> File Name: poj1797.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月20日 星期四 15时33分56秒
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
int n,m;
bool vis[maxn];
int cost[maxn][maxn];//邻接矩阵
int dist[maxn];//源点到所有点的最短路

//求出所有路径上边的最小值 中的最大值
void dijkstra(int n,int beg)
{
    for (int i=1;i<=n;i++)
    {
        dist[i]=0;
        vis[i]=false;
    }
    dist[beg]=INF;
    for (int k=0;k<n;k++)
    {
        int cnt = -1;
        int maxx = 0;
        for (int i=1;i<=n;i++)//从所有未访问过的点找出dist[v]最大的点
        {
            if (!vis[i] && dist[i]>maxx)
            {
                maxx = dist[i];
                cnt=i;
            }
        }
        if (cnt==-1) break;//找不到(都访问完了),退出
        vis[cnt]=1;
        for (int i=1;i<=n;i++)//更新其他点dist[]值
            if (!vis[i] && min(dist[cnt],cost[cnt][i])>dist[i] )
                dist[i] = min(dist[cnt],cost[cnt][i]);
    }
}


int main()
{
    freopen("in","r",stdin);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int cas=1;cas<=t;cas++)
    {
        cin >> n >> m;
        //scanf("%d%d",&n,&m);
        int u,v,w;
        memset(cost,0,sizeof(cost));
        for (int i=0;i<m;i++)
        {
            cin >> u >> v >> w;
            //scanf("%d%d%d",&u,&v,&w);
            cost[u][v]=cost[v][u]=max(cost[u][v],w);
        }
        dijkstra(n,1);

        printf("Scenario #%d:\n",cas);
        printf("%d\n",dist[n]);
        if(cas!=t) puts("");
    }
    return 0;
}
