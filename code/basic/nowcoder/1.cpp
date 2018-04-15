#include <bits/stdc++.h>
using namespace std;
const int maxn = 600+5;
struct edge{
    int to,cost;
};
vector<edge> G[maxn];
int flag[maxn];
int n,m;
bool vis[maxn];
int ans = 0;
void dfs(int u,int cost)
{
    if(cost >= ans) return;
    if(u==2){ans=min(ans,cost);return;}
    for(int i=0;i<G[u].size();i++)
    {
        edge tmp = G[u][i];
        int v = tmp.to;
        int cc = tmp.cost;
        if(vis[v] == 1) continue;
        if(flag[u]==2 && flag[v]==1) continue;
        vis[v] = true;
        dfs(v,cost+cc);
        vis[v] = false;
    }
}
inline int read()
{
    int x=0,f=1; char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{
    //freopen("in","r",stdin);
    while(cin>>n && n)
    {
        cin>>m;
        for(int i=1;i<=n;i++) G[i].clear();
        int u,v,w;
        for(int i=0;i<m;i++)
        {
            u=read(); v=read(); w=read();
            G[u].push_back(edge{v,w});
            G[v].push_back(edge{u,w});
        }
        for(int i=1;i<=n;i++)
        {
            flag[i]=read();
        }
        memset(vis,0,sizeof(vis));
        vis[1]=1;
        ans=0x3f3f3f3f;
        dfs(1,0);
        if(ans == 0x3f3f3f3f)
            cout << "-1\n";
        else cout << ans << endl;
    }
    return 0;
}
