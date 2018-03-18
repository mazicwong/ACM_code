#include <bits/stdc++.h>
using namespace std;

const int maxn = 505;

struct edge{
    int to;
    int cost;
    int flag;
};
vector<edge> G[maxn];

int n,m;
int ans=0x3f3f3f3f;
bool vis[maxn];
void dfs(int u,int fa,int sum,int lian)
{
    if(u==n)
    {
        ans=min(ans,sum);
    }
    for(int i=0;i<G[u].size();i++)
    {
        edge tmp=G[u][i];
        int v=tmp.to;
        int cost=tmp.cost;
        int flag=tmp.flag;
        if(vis[v]==1) continue;
        vis[v]=1;
        if(flag==1)
        {
            dfs(v,u,sum-lian*lian+(lian+cost)*(lian+cost),lian+cost);
        }
        else
        {
            dfs(v,u,sum+cost,0);
        }
        vis[v]=0;
    }
}

void dfs1(int u,int sum)
{
    if(u==n)
    {
        ans=min(ans,sum);
        return;
    }
    for(int i=0;i<G[u].size();i++)
    {
        edge tmp = G[u][i];
        int v=tmp.to;
        int cost=tmp.cost;
        if(vis[v])continue;
        vis[v]=1;
        dfs1(v,sum+cost);
        vis[v]=0;
    }
}

int dist[maxn];
typedef pair<int,int> pii;
void dijkstra(int begin)
{
    pii a;
    priority_queue<pii,vector<pii>,greater<pii> >Q;
    dist[begin]=0;
    int u=begin;
    Q.push({dist[begin],begin});

    while(!Q.empty())
    {
        pii now=Q.top();Q.pop();
        int d=now.first;
        int v=now.second;
        if(dist[v] < d)continue;

        if(dist[u]+d < dist[v])
        {
            
        }
    }

    
}

int main()
{
    cin>>n>>m;
    int flag1=0;
    for(int i=0;i<m;i++)
    {
        int flag; int u,v; int c;
        scanf("%d%d%d%d",&flag,&u,&v,&c);
        G[u].push_back(edge{v,c,flag});
        G[v].push_back(edge{u,c,flag});
        if(flag==1)flag1=1;
    }
    memset(vis,0,sizeof(vis));
    if(flag1==0)
    {
        dfs1(1,0);
        cout << ans;
        return 0;
    }
    dfs(1,-1,0,0);
    cout << ans;

    return 0;
}
