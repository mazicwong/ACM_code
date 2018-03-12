#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f;
ll n,m;
ll a,b,mod,x0;
const ll maxn = 25000005;
ll x[maxn];
struct edge{
    int to;
    int cap;
    int rev;
};
vector<edge> G[maxn];
bool vis[maxn];

ll dfs(int st,int en,int f)
{
    if(st==en) return f;
    vis[st]=1;
    for(int i=0;i<G[st].size();i++)
    {
        edge nxt=G[st][i];
        if(vis[nxt.to]==false && nxt.cap>0)
        {
            int d = dfs(nxt.to,en,min(f,nxt.cap));
            if(d>0)
            {
                nxt.cap-=d;
                G[nxt.to][nxt.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

ll max_flow(int st,int en)
{
    int flow=0;
    while(1)
    {
        memset(vis,0,sizeof(vis));
        int f=dfs(st,en,INF);
        if(f==0) return flow;
        flow+=f;
    }
}
void add(int from,int to,int cap)
{
    G[from].push_back(edge{to,cap,G[to].size()});
    G[to].push_back(edge{from,0,G[from].size()-1});
}
int main()
{
    cin>>n>>m;
    cin>>a>>b>>mod>>x[0];

    //向下，任意； 向上，有限制
    //向左，向右，有限制；
    
    for(int i=1;i<=(n-1)*m;i++)
    {
        x[i]=(a*x[i-1]+b)%mod;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int cap = x[(i-1)*m+j];
            add(i,j,x[]);

        }
    }
    ll ans = 0;


    return 0;
}
