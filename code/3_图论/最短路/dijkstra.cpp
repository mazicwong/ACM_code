#include <bits/stdc++.h>
using namespace std;
/*
 * 使用优先队列优化Dijkstra算法
 * 复杂度O(ElogE)
 * 注意对vector<node> G[maxn] 进行初始化后加边
 *
 * 点从1开始编号
 * dijkstra(1)是共n个点,1作为源点
 */
typedef pair<int,int> pii;//距离,点
const int maxn = 1e5+5;
const int INF = 0x3f3f3f3f;
int n,m;
//有权图用edge{to,cost}, 无权图/树用node{int}
struct node{
    int to;
    int cost;
    node(int _to=0,int _cost=0):to(_to),cost(_cost){}
};
vector<node> G[maxn];
int dist[maxn];

void dijkstra(int begin)
{
    priority_queue<pii,vector<pii>,greater<pii> > Q; //使得按距离dist[]排
    for(int i=0;i<=n;i++) dist[i]=INF; dist[begin]=0;
    Q.push(pii{dist[begin],begin});

    while(!Q.empty())
    {
        pii now=Q.top();Q.pop();
        int u = now.second;
        int cost = now.first;
        if(dist[u] < cost) continue; //已被更新过
        for(int i=0;i<G[u].size();i++)
        {
            node nxt = G[u][i];
            int v = nxt.to;
            int nxt_cost = nxt.cost;
            if(dist[v] > dist[u]+nxt_cost)
            {
                dist[v] = dist[u]+nxt_cost;
                Q.push({dist[v],v});
            }
        }
    }
}

void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        G[i].clear();
    }
}
int main()
{
    //hdu 2544 裸dijkstra
    while(cin>>n>>m && n && m)
    {
        init(n);
        for(int i=0;i<m;i++)
        {
            int u,v,cost;
            scanf("%d%d%d",&u,&v,&cost);
            G[u].push_back({v,cost});
            G[v].push_back({u,cost});
        }
        dijkstra(1);
        //for(int i=1;i<n;i++)cout<<dist[i]<<endl;
        cout << dist[n] << endl;       
    }
    return 0;
}
