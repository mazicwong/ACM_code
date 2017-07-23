/*************************************************************************
	> File Name: poj1511.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月22日 星期六 20时27分48秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1e6+5;
const int INF = 0x3f3f3f3f;
struct Edge{
    int v;
    int cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge> E[maxn];
vector<Edge> ee[maxn];
void addedge(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
}
void ADDEDGE(int u,int v,int w)
{
    ee[u].push_back(Edge(v,w));
}
int n,m;

bool vis[maxn];


void SPFA(int dist[],int start,int n)
{
    int a,next;
    for (int i=0;i<=n;i++)
    {
        vis[i]=false;
        dist[i]=INF;
    }
    vis[start]=true;
    dist[start]=0;
    queue<int> que;
    que.push(start);
    while(!que.empty())
    {
        a = que.front();
        que.pop();
        vis[a]=false;
        for (int i=0;i<ee[a].size();i++)
        {
            next = ee[a][i].v;
            if (dist[next] > dist[a]+ee[a][i].cost)
            {
                dist[next] = dist[a]+ee[a][i].cost;
                if(!vis[next])
                {
                    vis[next]=true;
                    que.push(next);
                }
            }
        }
    }
}

void spfa(int dist[],int start,int n)
{
    int a,next;
    for (int i=0;i<=n;i++)
    {
        vis[i]=false;
        dist[i]=INF;
    }
    vis[start]=true;
    dist[start]=0;
    queue<int> que;
    que.push(start);
    while(!que.empty())
    {
        a = que.front();
        que.pop();
        vis[a]=false;
        for (int i=0;i<E[a].size();i++)
        {
            next = E[a][i].v;
            if (dist[next] > dist[a]+E[a][i].cost)
            {
                dist[next] = dist[a]+E[a][i].cost;
                if(!vis[next])
                {
                    vis[next]=true;
                    que.push(next);
                }
            }
        }
    }
}


int main()
{
    freopen("in","r",stdin);
    int dist1[maxn];
    int dist2[maxn];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(dist1,0,sizeof(dist1));
        memset(dist2,0,sizeof(dist2));
        for (int i=0;i<=n+1;i++) E[i].clear();
        for (int i=0;i<=n+1;i++) ee[i].clear();
        
        int a,b,w;
        for (int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            addedge(a,b,w);
            ADDEDGE(b,a,w);
        }
        spfa(dist1,1,n);
        SPFA(dist2,1,n);
        long long ans=0;
        for (int i=1;i<=n;i++)
        {
            ans = ans + dist1[i] + dist2[i];
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
