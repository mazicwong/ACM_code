#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100+5;
const int INF = 0x3f3f3f3f;
struct Edge{
    int to,cost;
    Edge(int _to=0,int _cost=0):to(_to),cost(_cost){}
};
vector<Edge> G[maxn];
int dist[maxn];

struct HeapNode{
    int to,cost;
    HeapNode(int _to=0,int _cost=0):to(_to),cost(_cost){}
    bool operator < (const HeapNode & rhs) const {
        return cost > rhs.cost;
    }
};

int n,m;
void dijkstra(int begin)
{
    priority_queue<HeapNode> pq;
    for(int i=0;i<=n;i++) dist[i]=INF; dist[begin]=0;
    pq.push(HeapNode(begin,0));

    while(!pq.empty())
    {
        HeapNode now = pq.top(); pq.pop();
        int u = now.to;
        int cost = now.cost;
        if(dist[u] < cost) continue;
        for(int i=0;i<G[u].size();i++)
        {
            Edge nxt = G[u][i];
            int v = nxt.to;
            int nxt_cost = nxt.cost;
            if(dist[u]+nxt_cost < dist[v])
            {
                dist[v] = dist[u]+nxt_cost;
                pq.push(HeapNode(v,dist[v]));
            }
        }
    }
}

void init(int n)
{
    for(int i=0;i<=n;i++) G[i].clear();
}

int main()
{
    while(cin>>n>>m && n)
    {
        init(n);
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            G[u].push_back(Edge(v,w));
            G[v].push_back(Edge(u,w));
        }
        dijkstra(1);
        cout << dist[n] << endl;
    }
    return 0;
}
