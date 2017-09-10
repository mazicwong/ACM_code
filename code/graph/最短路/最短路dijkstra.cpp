#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;
/*
 * 使用优先队列优化Dijkstra算法
 * 复杂度O(ElogE)
 * 注意对vector<Edge>E[maxn] 进行初始化后加边
 *
 * 点从1开始编号
 * dijkstra(n,1)是共n个点,1作为源点
 */
const int INF = 0x3f3f3f3f;
const int maxn = 2e3+5;

typedef pair<int, int> PII;//first是最短距离,second是顶点的编号
struct edge
{
    int to,cost;
    edge(int _to=0,int _cost=0):
        to(_to),cost(_cost){}
};
vector<edge> E[maxn];//邻接表
int dist[maxn];//源点到其他点距离

void dijkstra(int n,int beg)//点的编号从1开始
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    for (int i=0;i<=n;i++) dist[i]=INF;
    dist[beg]=0;
    Q.push(PII(0,beg));
    
    while(!Q.empty())
    {
        PII a = Q.top(); Q.pop();
        int u = a.second;//点
        int d = a.first;//距离
        if (dist[u]<d)
            continue;//访问过且之前的更优,回溯
        for(int i=0;i<E[u].size();i++)
        {
            edge &e = E[u][i];
            if (dist[e.to] > dist[u]+e.cost)
            {
                dist[e.to] = dist[u]+e.cost;
                Q.push(PII(dist[e.to], e.to));
            }
        }
    }
}
void addedge(int u,int v,int w)
{
    E[u].push_back(edge(v,w));
}
void init(int n)
{
    for (int i=0;i<=n;i++)
        E[i].clear();
}
int main()
{   //poj2378 从n点走到1点,给出权重,求最短路
    //freopen("in","r",stdin);
    int m,n;
    cin >> m >> n;
    init(n);
    int u,v,cost;
    for (int i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&cost);
        addedge(u,v,cost);
        addedge(v,u,cost);
    }
    //如果源点为1,则用dijkstra(n,1)
    dijkstra(n,n);//MAX_V,begin (n点走到1点)
    cout << dist[1];
    return 0;
}
