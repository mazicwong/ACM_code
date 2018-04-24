#include <bits/stdc++.h>
using namespace std;
const int maxn =  1e4+5;
const int INF = 0x3f3f3f3f;
struct edge{
int to; //终点
int cap; //容量
int rev; //反向边
};
vector<edge> G[maxn];
bool vis[maxn];
void addedge(int from,int to,int cap) //重边情况不影响
{
G[from].push_back((edge){to,cap,G[to].size()});
G[to].push_back((edge){from,0,G[from].size()-1});
}
int dfs(int s,int t,int f)
{
if(s==t)
return f;
vis[s]=true;
for(int i=0;i<G[s].size();i++)
{
edge &tmp = G[s][i]; //注意
if(vis[tmp.to]==false && tmp.cap>0)
{
int d=dfs(tmp.to,t,min(f,tmp.cap));
if(d>0)
{
tmp.cap-=d;
G[tmp.to][tmp.rev].cap+=d;
return d;
}
}
}
return 0;
}
int max_flow(int s,int t)
{
int flow=0;
while(1)
{
memset(vis,false,sizeof(vis));
int f=dfs(s,t,INF);
if(f==0)
return flow;
flow+=f;
}
}

int main()
{
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,t;
        cin>>u>>v>>t;
        addedge(u,v,t);
    }
    int ans = 0x3f3f3f3f;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
                ans = min(ans, max_flow(i,j));
    cout<<ans<<endl;
    cout<<max_flow(1,n);
    return 0;
}

