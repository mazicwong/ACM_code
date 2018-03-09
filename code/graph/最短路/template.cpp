

//最短路
1.dijkstra单源最短路          O(n^2)
2.(1)队列优化的dijkstra       O(ElogE)
  (2)边权有两属性约束的dijkstra
  (3)次短路
3.spfa      O(kE) //k为所有点入队平均次数,一般k<2n
4.floyd     O(n^3)
//各个单源最短路径算法的区别在于：对每条边松弛操作的次数，以及松弛的次序
//松弛操作：就是更新两点间的最短路径。



1.dijkstra 单源最短路(邻接矩阵) //O(n^2)
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

2.dijkstra+堆优化(邻接表)--挑战书(P102)
//(1).最短路(dijkstra+堆优化)  O(E logE)
/*
 * 使用优先队列优化Dijkstra算法
 * 复杂度O(ElogE)
 * 注意对vector<node> G[maxn] 进行初始化后加边
 *
 * 点从1开始编号
 * dijkstra(1)是共n个点,1作为源点
 */
typedef pair<int,int> pii;//距离,点
const int maxn = 1e5+5;
const int INF = 0x3f3f3f3f;
int n,m;
//有权图用edge{to,cost}, 无权图/树用node{int}
struct node{
    int to;
    int cost;
    node(int _to=0,int _cost=0):to(_to),cost(_cost){}
};
vector<node> G[maxn];
int dist[maxn];

void dijkstra(int begin)
{
    priority_queue<pii,vector<pii>,greater<pii> > Q; //使得按距离dist[]排
    for(int i=0;i<=n;i++) dist[i]=INF; dist[begin]=0;
    Q.push(pii{dist[begin],begin});

    while(!Q.empty())
    {
        pii now=Q.top();Q.pop();
        int u = now.second;
        int cost = now.first;
        if(dist[u] < cost) continue; //已被更新过
        for(int i=0;i<G[u].size();i++)
        {
            node nxt = G[u][i];
            int v = nxt.to;
            int nxt_cost = nxt.cost;
            if(dist[v] > dist[u]+nxt_cost)
            {
                dist[v] = dist[u]+nxt_cost;
                Q.push({dist[v],v});
            }
        }
    }
}
void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        G[i].clear();
    }
}
int main()
{
    //hdu 2544 裸dijkstra
    while(cin>>n>>m && n && m)
    {
        init(n);
        for(int i=0;i<m;i++)
        {
            int u,v,cost;
            scanf("%d%d%d",&u,&v,&cost);
            G[u].push_back({v,cost});
            G[v].push_back({u,cost});
        }
        dijkstra(1);
        cout << dist[n] << endl;       
    }
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


3.spfa
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



4.floyd (任意两点间最短路)
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


