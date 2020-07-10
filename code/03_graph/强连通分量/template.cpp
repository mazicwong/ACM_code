
求强连通分量可以用tarjan或者kosaraju算法
其中tarjan要一次dfs
kosaraju用两次dfs,可以得到缩点后的DAG图和拓扑序

//kosaraju模板  O(N+M)
const int maxn = 100+5;

int V;                  //顶点数
vector<int> G[maxn];    //图的邻接表表示
vector<int> rG[maxn];   //把边反向后的图
vector<int> vs;         //后续遍历顺序的顶点列表
bool used[maxn];        //访问标记
int cmp[maxn];          //所属强连通分量的拓扑分支
int in[maxn],out[maxn]; //出入度
vector<int> g[maxn];    //缩点后的DAG图

void addedge(int u,int v)
{
    G[u].push_back(v);
    rG[v].push_back(u);
}

void dfs(int v)
{
    used[v] = true;
    for (int i=0;i<G[v].size();i++)
    {
        if (!used[G[v][i]])
            dfs(G[v][i]);
    }
    vs.push_back(v);
}

void rdfs(int v,int k)
{
    used[v] = true;
    cmp[v] = k;
    for (int i=0;i<rG[v].size();i++)
    {
        if (!used[rG[v][i]])
            rdfs(rG[v][i],k);
    }
}

int scc()
{
    //一遍dfs
    memset(used,0,sizeof(used));
    vs.clear();
    for (int v=0;v<V;v++)
    {
        if (!used[v])
            dfs(v);
    }

    //反向dfs
    memset(used,0,sizeof(used));
    int k = 0;
    for (int i=vs.size()-1;i>=0;i--)
    {
        if (!used[vs[i]])
            rdfs(vs[i],k++);
    }

    //出入度+建DAG图
    memset(in,0,sizeof(in));
    for (int u=0;u<V;u++)
    {
        for (int i=0;i<G[u].size();i++)
        {
            int v = G[u][i];
            if(cmp[u]!=cmp[v])
            {
                out[cmp[u]]++,in[cmp[v]]++;
                g[cmp[u]].push_back(cmp[v]);//建图,DAG图
            }
        }
    }
    return k;
}

void init()
{
    for (int u=0;u<V;u++)
    {
        G[u].clear();
        rG[u].clear();
        g[u].clear();
    }
}

int main()
{
    int m;
    scanf("%d%d",&V,&m);
    init();//...
    for (int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
            addedge(u-1,v-1);
    }
    
    int n = scc();//强连通分量个数
    
    /*
     * scc: Strongly Connected Component 强连通分量
     * cmp[0..V-1]: scc的拓扑序(cmp[u]=i: u点属于拓扑序中第i个)
     * g[0..n-1]: DAG图
     */

    
    return 0;
}








//tarjan


