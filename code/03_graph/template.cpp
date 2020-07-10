1.MST
  1.1 kruskal  (稀疏图,好写)      ElogV
  1.2 prim     (稠密图,更优)      ElogV / V+ElogV 
  1.3 次小生成树                  O(n²+mlogm)
  1.4 生成树个数(Matrix-tree)
2.强连通分量
  2.1 kosaraju
  2.2 tarjan
3.最短路
  3.1 dijkstra单源最短路          O(n^2)
  3.2 (1)队列优化的dijkstra       O(ElogE)
      (2)边权有两属性约束的dijkstra
      (3)次短路
  3.3 spfa      O(kE) //k为所有点入队平均次数,一般k<2n
  3.4 floyd     O(n^3)
4.网络流
  4.1 dinic最大流
  4.2 最小费用最大流
5.2-SAT



//////////////////////////////////////////////////////////////////////
1.MST
1.1.kruskal
const int maxn = 50+5;//point
const int maxm = 1500+5;//edge
/*
 * kruskal: 在一个n个顶点的空图上一直加边,但不能构成环,适用稀疏图
 * poj1287: 传入点,边,求最小生成树边权和
 * 复杂度: E*logV
 * point: [1..n]
 * edge: [0..m-1]
 */
int n,m;//点,边

//建图(存边)
struct edge{
    int x,y;
    int d;
}E[maxm];
int cmp(edge a1,edge a2){return a1.d<a2.d;}

//并查集(判连通块)
int fa[maxn];
void init() {for (int i=1;i<=n;i++) fa[i]=i;}
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
void unite(int x,int y)
{
    int nx=find(x),ny=find(y);
    if (nx!=ny) fa[nx]=ny;
}

//kruskal(传入边数)
int kruskal(int num)
{
    init();
    sort(E,E+num,cmp);
    int ans=0,cnt=0;
    for (int i=0;i<num;i++)
    {
        if (find(E[i].x)!=find(E[i].y))
        {
            ans += E[i].d;
            unite(E[i].x,E[i].y);
            cnt++;
        }
        if (n-1==cnt)
            return ans;
    }
}

int main()
{
    while(scanf("%d",&n) && n)
    {
        scanf("%d",&m);
        for (int i=0;i<m;i++)
            scanf("%d%d%d",&E[i].x,&E[i].y,&E[i].d);
        printf("%d\n",kruskal(m));
    }
    return 0;
}

1.2.prim
/*
 * prim,堆优化版,适用稠密图,在一个空集合中不断加入外面的点
 * O(e*lgn)
 * hdu1102 给邻接矩阵,求最小生成树
 */
const int maxn = 105;
const int INF = 0x3f3f3f3f;
int dis[maxn];//dis初始化INF,为0说明这个点已经被收录进树了
int vis[maxn];

//版本1
struct node{
    int v,len;
    node(int v=0,int len=0):v(v),len(len){}
    bool operator < (const node &a) const{
        return len>a.len;
    }
};
vector<node> G[maxn];
void init()
{
    for (int i=0;i<maxn;i++)
    {
        G[i].clear();
        dis[i]=INF;
        vis[i]=false;
    }
}
int prim(int s)
{
    priority_queue<node> Q;
    int ans=0;
    Q.push(node(s,0));
    while(!Q.empty())
    {
        node now=Q.top(); Q.pop();
        int v=now.v;
        if (vis[v]) continue;
        vis[v]=true;
        ans+=now.len;
        for(int i=0;i<G[v].size();i++)
        {
            int v2 = G[v][i].v;
            int len = G[v][i].len;
            if(!vis[v2] && dis[v2]>len)
            {
                dis[v2]=len;
                Q.push(node(v2,dis[v2]));
            }
        }
    }
    return ans;
}

//版本2
//用到邻接矩阵,稠密图更好,E+VlogV
int map[maxn][maxn];
int prim(int n)
{
	for (int i = 1; i <= n; i++)
	{
		dis[i] = map[1][i];
		vis[i] = 0;
	}
	dis[1] = 0;
	vis[1] = 1;
	int k, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int tmp = INF;
		for (int j = 1; j <= n; j++)
		{
			if (!vis[j] && tmp>dis[j])
			{
				k = j;
				tmp = dis[j];
			}
		}
		if (tmp == INF)
			break;
		vis[k] = 1;
		ans += dis[k];
		for (int j = 1; j <= n; j++)
		{
			if (!vis[j] && dis[j] > map[k][j])
				dis[j] = map[k][j];
		}
	}
	return ans;
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &map[i][j]);
		int q;
		scanf("%d", &q);
		for (int i = 0; i < q; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			map[a][b] = map[b][a] = 0;//为0是已经被连通起来
		}
		printf("%d\n", prim(n));
	}
}


1.3 次小生成树  O(n²+mlogm)
//变型: 问最小生成树是否不止一条,也是这样解
//http://blog.csdn.net/sluqy671/article/details/41720785
//https://vijos.org/p/1070
#define N 500 + 10  
#define M 150000  
#define INF 1000000000  
using namespace std;  
struct line  
{  
    int l, r, w;  
}c[M];  
struct edge  
{  
    int fr, to, w, next;  
}e[2*N];  
int n, m, num, now, ans1, ans2 = INF;  
int fa[N], p[N], d[N][N], used[M];  
bool cmp(line a, line b)  
{  
    return a.w < b.w;  
}  
int find(int x)  
{  
    if (fa[x] == x) return x;  
    return fa[x] = find(fa[x]);  
}  
int read()  
{  
    char c = getchar();  
    while(c < '0' || c > '9') c = getchar();  
    int x = 0;  
    while(c >= '0' && c <= '9')  
    {  
        x = 10*x + c - '0';  
        c = getchar();  
    }  
    return x;  
}  
void add(int x, int y, int z)  
{  
    e[++num].fr = x;  
    e[num].to = y;  
    e[num].w = z;  
    e[num].next = p[x];  
    p[x] = num;  
}  
void init()  
{  
    n = read(), m = read();  
    for (int i = 1; i <= m; ++i)  
    {  
        c[i].l = read();  
        c[i].r = read();  
        c[i].w = read();  
    }  
}  
void kruskal()  
{  
    for (int i = 1; i <= n; ++i)  
    fa[i] = i;  
    sort(c+1, c+m+1, cmp);  
    for (int i = 1; i <= m; ++i)  
    {  
        int fl = find(c[i].l), fr = find(c[i].r);  
        if (fl != fr)  
        {  
            used[i] = 1;  
            fa[fl] = fr;  
            ans1 += c[i].w;  
            add(c[i].l, c[i].r, c[i].w);  
            add(c[i].r, c[i].l, c[i].w);  
            if (n - 1 == num / 2) return;  
        }  
    }  
}//克鲁斯卡尔  
void dfs_mini(int x, int fr, int maxs)  
{  
    d[now][x] = maxs;  
    for (int i = p[x]; i; i = e[i].next)  
    {  
        int k = e[i].to;  
        if (k != fr) dfs_mini(k, x, max(maxs, e[i].w));  
    }  
}//求最小瓶颈路上最大权值  
void deal()  
{  
    kruskal();  
    if (n - 1 == num / 2) printf("Cost: %d\n", ans1);  
    else  
    {  
        printf("Cost: -1\n");  
        printf("Cost: -1\n");  
        return;  
    }  
    for (now = 1; now <= n; ++now)  
    dfs_mini(now, 0, 0);  
    for (int i = 1; i <= m; ++i)  
    if (!used[i] && ans1 - d[c[i].l][c[i].r] + c[i].w < ans2)  
    ans2 = ans1 - d[c[i].l][c[i].r] + c[i].w;//枚举并更新  
    if (ans2 != INF) printf("Cost: %d\n", ans2);  
    else printf("Cost: -1\n");  
}  
int main()  
{  
    init();  
    deal();  
    return 0;  
}


1.4 生成树个数
//给n点m边,问生成树个数
//生成树的计数Matrix-Tree定理
const int N=111;
const int M=1111;
typedef long long LL;

struct Edges{
    int a,b,c;
    bool operator<(const Edges & x)const
    {
        return c<x.c;
    }
} edge[M];

int n,m;
int mod;
LL f[N],U[N],vist[N];//f,U都是並查集，U是每組邊臨時使用
LL G[N][N],C[N][N];//G頂點之間的關係，C為生成樹計數用的Kirchhoff矩陣

vector<int>V[N];//記錄每個連通分量

int Find(int x,LL f[])
{
    if(x==f[x])
        return x;
    else
        return Find(f[x],f);
}

LL det(LL a[][N],int n)//生成樹計數:Matrix-Tree定理
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            a[i][j]%=mod;
    int ret=1;
    for(int i=1; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
            while(a[j][i])
            {
                int t=a[i][i]/a[j][i];
                for(int k=i; k<n; k++)
                    a[i][k]=(a[i][k]-a[j][k]*t)%mod;
                for(int k=i; k<n; k++)
                    swap(a[i][k],a[j][k]);
                ret=-ret;
            }
        if(a[i][i]==0)
            return 0;
        ret=ret*a[i][i]%mod;
    }
    return (ret+mod)%mod;
}

void Solve()
{
    sort(edge,edge+m);//按權值排序
    for(int i=1; i<=n; i++)//初始化並查集
    {
        f[i]=i;
        vist[i]=0;
    }

    LL Edge=-1;//記錄相同的權值的邊
    LL ans=1;
    for(int k=0; k<=m; k++)
    {
        if(edge[k].c!=Edge||k==m)//一組相等的邊,即權值都為Edge的邊加完
        {
            for(int i=1; i<=n; i++)
            {
                if(vist[i])
                {
                    LL u=Find(i,U);
                    V[u].push_back(i);
                    vist[i]=0;
                }
            }
            for(int i=1; i<=n; i++) //枚舉每個連通分量
            {
                if(V[i].size()>1)
                {
                    for(int a=1; a<=n; a++)
                        for(int b=1; b<=n; b++)
                            C[a][b]=0;
                    int len=V[i].size();
                    for(int a=0; a<len; a++) //構建Kirchhoff矩陣C
                        for(int b=a+1; b<len; b++)
                        {
                            int a1=V[i][a];
                            int b1=V[i][b];
                            C[a][b]=(C[b][a]-=G[a1][b1]);
                            C[a][a]+=G[a1][b1];//連通分量的度
                            C[b][b]+=G[a1][b1];
                        }
                    LL ret=(LL)det(C,len);
                    ans=(ans*ret)%mod;//對V中的每一個連通塊求生成樹個數再相乘
                    for(int a=0; a<len; a++)
                        f[V[i][a]]=i;
                }
            }
            for(int i=1; i<=n; i++)
            {
                U[i]=f[i]=Find(i,f);
                V[i].clear();
            }
            if(k==m)
                break;
            Edge=edge[k].c;
        }

        int a=edge[k].a;
        int b=edge[k].b;
        int a1=Find(a,f);
        int b1=Find(b,f);
        if(a1==b1)
            continue;
        vist[a1]=vist[b1]=1;
        U[Find(a1,U)]=Find(b1,U);//並查集操作
        G[a1][b1]++;
        G[b1][a1]++;
    }

    int flag=0;
    for(int i=2; i<=n&&!flag; i++)
        if(U[i]!=U[i-1])
            flag=1;
    if(m==0)
        flag=1;
    printf("%I64d\n",flag?0:ans%mod);

}
int main()
{
    while(scanf("%d%d%d",&n,&m,&mod),n+m+mod)
    {
        memset(G,0,sizeof(G));
        for(int i=1; i<=n; i++)
            V[i].clear();
        for(int i=0; i<m; i++)
            scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].c);
        Solve();
    }
    return 0;
}




//////////////////////////////////////////////////////////////////////
2.强连通分量 tarjan/kosaraju
//其中tarjan要一次dfs
//kosaraju用两次dfs,可以得到缩点后的DAG图和拓扑序

//kosaraju模板
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

//////////////////////////////////////////////////////////////////////
3.最短路
3.1.dijkstra单源最短路          O(n^2)
3.2.(1)队列优化的dijkstra       O(ElogE)
    (2)边权有两属性约束的dijkstra
    (3)次短路
3.3.spfa      O(kE) //k为所有点入队平均次数,一般k<2n
3.4.floyd     O(n^3)

3.1.dijkstra 单源最短路(邻接矩阵) //O(n^2)
/*
 * 单源最短路径,Dijkstra算法,邻接矩阵形式,复杂度为O(n^2)
 * 求出源beg到所有点的最短路径,传入图的顶点数,和邻接矩阵cost[][]
 * 返回各点的最短路径dist[], 路径pre[].pre[i]记录beg到i路径上的父结点,pre[beg]=-1
 * 可更改路径权类型,但是权值必须为非负
 */
const int maxn=1010;
const int INF=0x3f3f3f3f;//防止后面溢出,这个不能太大
bool vis[maxn];
int pre[maxn];//存储路径
//每次找到一个距离源点的最短路,利用它对所有的点进行松弛
void Dijkstra(int cost[][maxn],int dist[],int n,int beg)
{
    for(int i=0;i<n;i++)
    {
        dist[i]=INF;
        vis[i]=false;
        pre[i]=-1;
    }
    dist[beg]=0;
    for(int j=0;j<n;j++)
    {
        int k=-1;
        int minn=INF;
        for(int i=0;i<n;i++)//找最小距离
        {
            if(!vis[i] && dist[i]<minn)
            {
                minn=dist[i];
                k=i;
            }
        }
        if(k==-1)break;
        vis[k]=true;
        for(int i=0;i<n;i++)//松弛
        {
            if(!vis[i] && dist[k]+cost[k][i]<dist[i])
            {
                dist[i] = dist[k]+cost[k][i];
                pre[i] = k;
            }
        }
    }
}

3.2.dijkstra+堆优化(邻接表)--挑战书(P102)
//(1).最短路(dijkstra+堆优化)  O(E logE)
/*
 * 使用优先队列优化Dijkstra算法,复杂度O(ElogE)
 * 注意对vector<Edge>E[maxn] 进行初始化后加边
 *
 * 点从1开始编号
 * dijkstra(n,1)是共n个点,1作为源点
 */
const int INF = 0x3f3f3f3f;
const int maxn = 2e3+5;

typedef pair<int, int> PII;//first是最短距离,second是顶点的编号
struct edge{
    int to,cost;
    edge(int _to=0,int _cost=0):
        to(_to),cost(_cost){}
};
vector<edge> E[maxn];//邻接表
int dist[maxn];//源点到其他点距离

void dijkstra(int n,int beg)//点的编号从1开始
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    for (int i=0;i<=n;i++) dist[i]=INF;
    dist[beg]=0;
    Q.push(PII(0,beg));
    
    while(!Q.empty())  //每次找最短路改成堆实现
    {
        PII a = Q.top(); Q.pop();
        int u = a.second;//点
        int d = a.first;//距离
        if (dist[u]<d)
            continue;//访问过且之前的更优,回溯
        for(int i=0;i<E[u].size();i++)
        {
            edge &e = E[u][i];
            if (dist[e.to] > dist[u]+e.cost)
            {
                dist[e.to] = dist[u]+e.cost;
                Q.push(PII(dist[e.to], e.to));
            }
        }
    }
}
void addedge(int u,int v,int w)
{
    E[u].push_back(edge(v,w));
    //E[u].push_back({v,w});
}
void init(int n)
{
    for (int i=0;i<=n;i++)
        E[i].clear();
}
int main()
{   //poj2378 从n点走到1点,给出权重,求最短路
    //freopen("in","r",stdin);
    int m,n;
    cin >> m >> n;
    init(n);
    int u,v,cost;
    for (int i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&cost);
        addedge(u,v,cost);
        addedge(v,u,cost);
    }
    //如果源点为1,则用dijkstra(n,1)
    dijkstra(n,n);//MAX_V,begin (n点走到1点)
    cout << dist[1];
    return 0;
}


//(2).带两个属性的最短路(dijkstra)
#define ff first
#define ss second
using namespace std;
//https://nanti.jisuanke.com/t/18018 (jisuanke,jingchi1024)
//最短路变型:
//边权有两个属性wz表示淋雨量和路程量,问1~n的最短路
//m1条双向边是w=0,z=1; m2条双向边是w=z=val;
//要求:在淋雨和w<=L的情况下,求路程和z的最短
typedef long long LL;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int N=105;

struct Node{
    int v,w,z;	//w是淋雨,z是路程
};
vector<Node> G[N];  //邻接表存点,带上边的属性,用Node
//优先第一个属性,然后再第二个属性
struct HeapNode{
    int u,d,z;
    bool operator<(const HeapNode &rhs)const{
        if(d==rhs.d)return z>rhs.z;
        return d>rhs.d;
    }
};

bool f[N];
pii d[N];
int main() 
{
    int T;cin>>T;
    while(T--)
	{
        int n,m1,m2,r;
        scanf("%d%d%d%d",&n,&m1,&m2,&r);
        for(int i=1;i<=n;i++)G[i].clear();
        while(m1--)
        {
            int u,v; scanf("%d%d",&u,&v);
            G[u].push_back({v,0,1});
            G[v].push_back({u,0,1});
        }
        while(m2--)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            G[u].push_back({v,w,w});
            G[v].push_back({u,w,w});
        }
        priority_queue<HeapNode> Q;  //雨小优先,雨相等时路程小优先
        for(int i=1;i<=n;i++){
            d[i].ff=INF;   //ff是第一个属性雨
            d[i].ss=0;     //ss是第二个属性路程
        }
        d[1].ff=0;
        memset(f,0,sizeof f);
        Q.push({1,d[1].ff,d[1].ss});
        //dijkstra是每次取一个路程最小的出来对其他节点松弛
        //这里是每次取一个雨最少的出来对其他节点松弛(每个节点只能取一次)
        while(!Q.empty()){
            HeapNode x=Q.top();
            Q.pop();
            int u=x.u;
            if(f[u])continue;
            f[u]=true;
            for(auto tmp:G[u]){
                int v=tmp.v;
                int w=tmp.w;
                int z=tmp.z;
                if(x.z+z>r)continue;
                if(x.d+w<d[v].ff||x.d+w==d[v].ff&&x.z+z<d[v].ss){
                	d[v].ff=x.d+w;
                	d[v].ss=x.z+z;
                	Q.push({v,d[v].ff,d[v].ss});
                }
            }
        } 
        if(d[n].ff==INF) puts("-1");
        else printf("%d\n",d[n].ff);
    }
    return 0;
}


//(3).次短路(dijkstra+堆优化)--挑战书(P108)
/*
 * 次短路模板,点从1开始
 */
typedef long long ll;
typedef pair<int, int> PII;//first是最短距离,second是顶点编号
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;

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
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    Q.push(PII(0,beg));
    while(!Q.empty())
    {
        PII p = Q.top(); Q.pop();
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
                Q.push(PII(dist[e.to],e.to));
            }
            if (dist2[e.to]>d2 && dist[e.to]<d2)
            {
                dist2[e.to] = d2;
                Q.push(PII(dist2[e.to],e.to));
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
    //freopen("in","r",stdin);
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


3.3.spfa
单源最短路 spfa(邻接表存图,队列实现)
/*
 * 单源最短路SPFA
 * 时间复杂度 0(kE) //k为所有点入队平均次数,一般k<2n
 * 这个是队列实现,有时候改成栈实现会更加快,很容易修改
 * 这个复杂度是不定的
 * 只有v和cost的边是为了配合vector,采用数组实现邻接表存图
 */
const int maxn=1010;
const int INF=0x3f3f3f3f;
struct Edge
{
    int v;
    int cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge> E[maxn];//数组实现邻接表存储
void addedge(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
}
bool vis[maxn];//在队列标志
int dist[maxn];//源点到每个点的最短距离
int cnt[maxn];//每个点的入队列次数
bool SPFA(int start,int n)
{
    int a,next;//1 对int队列处理的暂存值
    for(int i=0;i<=n;i++)
    {
        vis[i]=false;
        dist[i]=INF;
        cnt[i]=0;
    }
    vis[start]=true;//3 更新3个
    dist[start]=0;
    cnt[start]=1;
    queue<int> Q;//4
    while(!Q.empty()) Q.pop();
    Q.push(start);//5 入队(经典五步)
    while(!Q.empty())
    {
        a=Q.front(); Q.pop();
        vis[a]=false;
        for(int i=0;i<E[a].size();i++) //对该点的所有边"松弛+入队"
        {
            next=E[a][i].v;
            if(dist[next]>dist[a]+E[a][i].cost)
            {
                dist[next]=dist[a]+E[a][i].cost; //下一个点不够松，则松弛下一个点
                if(!vis[next]) //下一个点未入队，则入队下一个点
                {
                    vis[next]=true;
                    que.push(next);
                    if(++cnt[next]>n)return false;
                    //判断负环:某个点入队超n次，则存在负环，cnt[i]为入队列次数
                }
            }
        }
    }
    return true;
}
int main()
{
    //别忘了清空vector
    for (int i=1;i<=n+1;i++) E[i].clear();
}



3.4.floyd (任意两点间最短路)
/* 
 * 传递闭包的时候有个优化
 * 先判断win[i][k]存在,否则就不进行循环
 */
void floyd()
{
    for (int k=0;k<n;k++)
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                /* 1.最短路
                 * dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                 */

                /* 2.传递闭包
                 * if (win[i][k]&&win[k][j]) //直接按定义
                 *     win[i][j] = 1;
                 */
}



//////////////////////////////////////////////////////////////////////
4. 网络流
4.1 dinic最大流
/*
 * 最大流最小割定理:
 * 一个流是最大流，当且仅当它的残留网络不包含增广路径
 */

/* hdu1532 最大流裸题
 * 最大流 ford-fulkerson方法,dinic算法
 *
 * 输入m边,n点
 * m行: 起点,终点,最大流量
 * 求以1为源点,n为汇点的最大流
5 4
1 2 40
1 4 20
2 4 20
2 3 30
3 4 10
------
50
*/
const int maxn = 1100;  
const int INF = 0x3f3f3f3f;  

//存边
struct edge{
    int to;  //终点  
    int cap; //容量  
    int rev; //反向边  
};
 
//邻接表边权写法; 点权用node
vector<edge> G[maxn];
bool vis[maxn];

//向残余网络中增加一条from到to容量为cap的边
void addedge(int from,int to,int cap)  //重边情况不影响  
{  
    G[from].push_back((edge){to,cap,G[to].size()});  
    G[to].push_back((edge){from,0,G[from].size()-1});  
}  

//dfs寻找增广路
int dfs(int s,int t,int f)
{  
    if(s==t)
        return f;
    vis[s]=true;
    for(int i=0;i<G[s].size();i++)
    {
        edge &tmp = G[s][i];  //注意  
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

//求解从s到t的最大流
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
    //freopen("in","r",stdin);
    int m,n;//m是边,n是点[1..n]
    while(~scanf("%d%d",&m,&n))
    {
        for (int i=1;i<=n;i++) G[i].clear();
        int u,v,c;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            addedge(u,v,c);
        }
        printf("%d\n",max_flow(1,n));
    }
}

4.2 最小费用最大流
#define INF 0x3f3f3f  
//青岛题目
const int maxn=1000;
int vis[maxn];
struct edge{
    int from,to,cap,flow;
    float cost;
};
struct MCMF{
    int n,m;
    vector<edge>E;
    vector<int>G[maxn];
    vector<int>V;
    int inq[maxn];//是否在队列中
    float dis[maxn];
    int p[maxn];
    int a[maxn];
    void init(int n)
    {
  	    this->n=n;
      	for(int i=0;i<=n;i++)
	    G[i].clear();
      	E.clear();
  	    V.clear();
    } 
    void AddEdge(int from,int to,int cap,float cost)
    {
  	    E.push_back((edge){from,to,cap,0,cost});
      	E.push_back((edge){to,from,0,0,-cost});
  	    m=E.size();
  	    G[from].push_back(m-2);
  	    G[to].push_back(m-1);
    } 
    bool BellmanFord(int s,int t,int &flow,float &cost,float &sum)
    {  
  	    for(int i=0;i<=t;i++)dis[i]=INF;
  	    memset(inq,0,sizeof(inq));
      	dis[s]=0;inq[s]=1;p[s]=0;a[s]=INF;
  	    queue<int>Q;
      	Q.push(s);
  	    while(!Q.empty())
      	{
  	        int u=Q.front();Q.pop();
	        inq[u]=0;
	        for(int i=0;i<G[u].size();i++)
	        {
	  	        edge &e=E[G[u][i]];
        	  	//if(e.cap>e.flow&&dis[e.to]>dis[u]+e.cost) //double 会出现精度问题
	  	        if(e.cap>e.flow&&dis[e.to]-dis[u]-e.cost>1e-8)
	  	        {
                    dis[e.to]=dis[u]+e.cost;
	  	            p[e.to]=G[u][i];
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!inq[e.to]&&vis[e.to]<m/2){
                        Q.push(e.to);inq[e.to]=1; 
                        vis[e.to]++;
                    }
                }
            } 
        }
        if(dis[t]==INF)return false;
  	    flow+=a[t];
  	    cost+=dis[t]*a[t];
      	int u=t;
  	    while(u!=s){
  	        E[p[u]].flow+=a[t];
      	    E[p[u]^1].flow-=a[t];
  	        if(E[p[u]].cost>0)
  	        sum=sum*pow((1.0-E[p[u]].cost),a[t]);
          	u=E[p[u]].from;
  	    }
  	    return true;
    }
    float Mincost(int s,int t)
    {
  	    int flow=0;
    	float cost=0;
	    float sum=1.0;
      	while(BellmanFord(s,t,flow,cost,sum));
  	    return 1.00-sum;
    }
    float P()
    {
  	    float sum=1.0;
      	for(int i=0;i<V.size();i++)
        {
            int x=V[i];
            for(int j=0;j<G[x].size();j++)
            {
      	        edge &e=E[G[x][j]];
              	if(e.cost>0&&e.flow>0)
      	        {
      	            sum=sum*pow((1.0-e.cost),e.flow);
		        }
	        }
	    }
	    return 1.0-sum;
    }
}T;
int main()
{
    int T;cin>>T;
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        int n,m;
        int from,to,cap;
        float cost;
        int a,b;int s=0;
        cin>>n>>m;
        int t=n+1;
        T.init(t);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            if(a>b)
            {
                T.AddEdge(0,i,a-b,0);
            }
            else if(a<b)
            {
                T.AddEdge(i,t,b-a,0);
            }
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&from,&to,&cap);
            scanf("%f",&cost);
            if(cap>1)
                T.AddEdge(from,to,cap-1,cost);
            if(cap>0)
                T.AddEdge(from,to,1,0);
        }
        printf("%.2f\n",T.Mincost(s,t));
    }
    return 0;
} 


//////////////////////////////////////////////////////////////////////
5. 2-SAT
见白书
结婚问题,牧师在婚礼前或者婚礼后出席,
问能否满足所有新人





