/*************************************************************************
	> File Name: 11.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月24日 星期四 12时16分24秒
 ************************************************************************/

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
typedef pair<ll, ll> pii;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5+5;
struct edge{
    int to;
    int cost;
    edge(int _to=0,int _cost=0):
        to(_to),cost(_cost){}
};
vector<edge> G[maxn];
int n,m;
ll dist[maxn],dist2[maxn];
void addedge(int u,int v,int w)
{
    G[u].push_back(edge(v,w));
}

void dijkstra(int n,int beg)
{
    for (int i=0;i<=n;i++) dist[i]=dist2[i]=INF;
    dist[beg]=0;
    
    priority_queue<pii, vector<pii>, greater<pii> > pque;
    pque.push(pii(0,beg));
    while(!pque.empty())
    {
        pii p = pque.top(); pque.pop();
        int u=p.second;
        ll d=p.first;
        if (dist2[u]<d) continue;
        for (int i=0;i<G[u].size();i++)
        {
            edge &e = G[u][i];
            ll d2 = d+e.cost;
            
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
}

void init()
{
    for (int i=0;i<=n;i++)
        G[i].clear();
}
int main()
{
    freopen("in","r",stdin);
    int t;cin>>t;
    while(t--)
    {
        init();
        scanf("%d%d",&n,&m);
        int a,b,w;
        for (int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            addedge(a,b,w);
            addedge(b,a,w);
        }
        dijkstra(n,1);
        cout << dist2[n] << endl;
    }
    return 0;
}
