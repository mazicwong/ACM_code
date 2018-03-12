#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
//1->n，求路径上最大边最小
//min{所有边权}

int n,m; 

struct edge{
    int to;
    int cost;
    edge(int _to=0,int _cost=0):to(_to),cost(_cost){}
};
vector<edge> G[maxn];

int ans=0x3f3f3f3f;
bool vis[maxn];
void dfs(int u,int fa,int maxx)
{
    if(u==n)
    {
        ans=min(maxx,ans);
        return;
    }
    
    for(int i=0;i<G[u].size();i++)
    {
        edge nxt = G[u][i];
        int v = nxt.to;
        int cost = nxt.cost;
        if(vis[v]) continue;
        vis[v]=1;
        dfs(v,u,max(maxx,cost));
        vis[v]=0;
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        G[u].push_back(edge{v,c});
        G[v].push_back(edge{u,c});
    }
    memset(vis,0,sizeof(vis));
    dfs(1,-1,0);
    cout << ans;
    return 0;
}
