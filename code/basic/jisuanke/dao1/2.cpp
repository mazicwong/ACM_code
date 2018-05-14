#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
const ll maxn = 222;
ll idx[maxn];
ll m;
const ll INF = 0x3f3f3f3f;
ll wu[maxn];
ll tot=0;

ll V;//顶点数
vector<ll> G[maxn];//图的邻接表表示
vector<ll> rG[maxn];//把边反向后的图
vector<ll> vs;//后续遍历顺序的顶点列表
bool used[maxn];//访问标记
ll cmp[maxn];//所属强连通分量的拓扑分支
ll in[maxn],out[maxn]; //出入度
vector<ll> g[maxn];//缩点后的 DAG 图

void addedge(ll u,ll v)
{
	G[u].push_back(v);
	rG[v].push_back(u);
}

void dfs(ll v)
{
	used[v] = true;
	for (ll i=0;i<G[v].size();i++)
	{
		if (!used[G[v][i]])
		dfs(G[v][i]);
	}
	vs.push_back(v);
}

void rdfs(ll v,ll k)
{
	used[v] = true;
	cmp[v] = k;
	for (ll i=0;i<rG[v].size();i++)
	{
		if (!used[rG[v][i]])
		rdfs(rG[v][i],k);
	}
}

ll scc()
{
    //一遍 dfs
	memset(used,0,sizeof(used));
	vs.clear();
	for (ll v=0;v<V;v++)
	{
		if (!used[v])
		dfs(v);
	}
	//反向 dfs
	memset(used,0,sizeof(used));
	ll k = 0;
	for (ll i=vs.size()-1;i>=0;i--)
	{
		if (!used[vs[i]])
		rdfs(vs[i],k++);
	}
	//出入度+建 DAG 图
	memset(in,0,sizeof(in));
	for (ll u=0;u<V;u++)
	{
		for (ll i=0;i<G[u].size();i++)
		{
			ll v = G[u][i];
			if(cmp[u]!=cmp[v])
			{
				out[cmp[u]]++,in[cmp[v]]++;
				g[cmp[u]].push_back(cmp[v]);//建图,DAG 图
			}
		}
	}
	return k;
}

ll wuwu[maxn];

ll nnn = 0;
ll dp[maxn];
ll dfs3(int u)
{
    if(dp[u]!=0) return dp[u];
    if(g[u].size()==1) return wuwu[u];
    for(int i=0;i<g[u].size();i++)
    {
        dp[u] += dfs3(g[u][i]);
    }
    return dp[u];
}

void init()
{
    for(int u=0;u<V;u++)
    {
        G[u].clear();
        rG[u].clear();
        g[u].clear();
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>wu[i],idx[i]=i;
    tot=n;
    cin>>m;
    V = 230;
    init();
    int flag; int x,y; int l,r;
    while(m--)
    {
        scanf("%d",&flag);
        if(flag==0)
        {
            scanf("%d%d",&x,&y);
            wu[++tot] = y;
            idx[x] = tot;
        }
        else if(flag==1)
        {
            scanf("%d%d%d",&x,&l,&r);
            for(int i=l;i<=r;i++){
                addedge(idx[x]-1, idx[i]-1);
            }
        }
    }

    nnn = scc(); 
    ll ans = INF;

    memset(wuwu,0,sizeof(wuwu));
    for(ll i=1;i<=tot;i++) wuwu[cmp[i-1]] += wu[i];

    memset(dp,0,sizeof(dp));
    for(int i=1;i<=tot;i++)
    {
        ll fa = cmp[i-1];
        ll tmp = dfs3(fa) + wu[i];
        ans = min(ans,tmp);
    }
    cout << ans;
    return 0;
}
