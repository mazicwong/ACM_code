#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
//一个带限制的最短路
//初步思路,首都到所有城市的最短路先选,然后求最小生成树
struct Edge{
    int to;
    int cost;
    Edge(int _to=0,int _cost=0):to(_to),cost(_cost){}
}edge;
struct Node{
    int to;
    int cost;
    Node(int _to=0,int _cost=0)
    {
        to=_to;
        cost=_cost;
    }
};
vector<Edge> G[maxn];
int n,m;
void dijkstra(int begin)
{
    for(int i=1;i<=n;i++)
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back({v,w});
    }

    return 0;
}
