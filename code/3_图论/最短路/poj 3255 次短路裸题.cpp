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
typedef long long ll;
typedef pair<int, int> pii;//first是最短距离,second是顶点编号
const int INF = 0x3f3f3f3f;
const int maxn = 5e3+5;

struct edge{
    int to;
    int cost;
    edge(int _to=0,int _cost=0):
        to(_to),cost(_cost){}
};
vector<edge> G[maxn];
int n,m;
int dist[maxn],dist2[maxn];
void addedge(int u,int v,int w)
{
    G[u].push_back(edge(v,w));
}

void dijkstra(int n,int beg)
{
    for (int i=0;i<=n;i++) dist[i]=dist2[i]=INF;
    dist[beg]=0;
    
    //堆按照first从小到大取出
    priority_queue<pii, vector<pii>, greater<pii> > pque;
    pque.push(pii(0,beg));
    while(!pque.empty())
    {
        pii p = pque.top(); pque.pop();
        int u=p.second;
        int d=p.first;
        if (dist2[u]<d) continue;
        for (int i=0;i<G[u].size();i++)
        {
            edge &e = G[u][i];
            int d2 = d+e.cost;
            
            if (dist[e.to]>d2)
            {
                swap(dist[e.to], d2);
                pque.push(pii(dist[e.to],e.to));
            }
            if (dist2[e.to]>d2 && dist[e.to]<d2)
            {
                dist2[e.to] = d2;
                pque.push(pii(dist2[e.to],e.to));
            }
        }
    }
    cout << dist2[n-1] << endl;
}

void init()
{
    for (int i=0;i<=n;i++)
        G[i].clear();
}
int main()
{
    freopen("in","r",stdin);
        init();
        scanf("%d%d",&n,&m);
        int a,b,w;
        for (int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            a--;b--;
            addedge(a,b,w);
            addedge(b,a,w);
        }
        dijkstra(n,0);
    return 0;
}
