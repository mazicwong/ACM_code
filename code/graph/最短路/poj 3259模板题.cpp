/*************************************************************************
	> File Name: poj3259.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月21日 星期五 00时33分00秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 500+5; //点
const int maxm = 5000+5;//边
const int INF = 0x3f3f3f3f;
struct Edge{
    int v;
    int cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge> E[maxm];//数组实现邻接表存储
void addedge(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
}
bool vis[maxn];
int dist[maxn];
int cnt[maxn];

bool spfa(int start,int n)
{
    int a,next;
    for (int i=1;i<=n;i++)
    {
        vis[i]=false;
        dist[i]=INF;
        cnt[i]=0;
    }
    vis[start]=1;
    dist[start]=0;
    cnt[start]=1;
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
                dist[next] = dist[a]+E[a][i].cost;//松弛
                if(!vis[next])
                {
                    vis[next]=true;
                    que.push(next); //入队
                    if (++cnt[next]>n)
                        return true;//有负环
                }
            }
        }
    }
    return false;
}

int main()
{
    freopen("in","r",stdin);
    int t;
    int n,m,w;
    scanf("%d",&t);
    while(t--)
    {
        for (int i=1;i<=n+1;i++) E[i].clear();
        scanf("%d%d%d",&n,&m,&w);
        int u,v,val;
        for (int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&val);
            addedge(u,v,val);
            addedge(v,u,val);//正边双向,负边单向
        }
        for (int i=0;i<w;i++)
        {
            scanf("%d%d%d",&u,&v,&val);
            addedge(u,v,0-val);
            //addedge(v,u,val);
        }
        if (spfa(1,n)) //从1开始找负环
            puts("YES");
        else 
            puts("NO");
    }
    
    return 0;
}
