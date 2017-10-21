
//各个单源最短路径算法的区别在于：对每条边松弛操作的次数，以及松弛的次序
//松弛操作：就是更新两点间的最短路径。


//最短路
1.dijkstra 单源最短路(邻接矩阵) //O(V^2)
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

2.dijkstra+堆优化(邻接表)

//最短路(dijkstra+堆优化)--挑战书(P102)
//O(E logE)

```cpp
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
/*
 * 使用优先队列优化Dijkstra算法
 * 复杂度O(ElogE)
 * 注意对vector<Edge>E[maxn] 进行初始化后加边
 *
 * 点从1开始编号
 * dijkstra(n,1)是共n个点,1作为源点
 */
const int INF = 0x3f3f3f3f;
const int maxn = 2e3+5;

typedef pair<int, int> PII;//first是最短距离,second是顶点的编号
struct edge
{
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
    
    while(!Q.empty())
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



//次短路(dijkstra+堆优化)--挑战书(P108)
```cpp
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
```



3.spfa
单源最短路 spfa(邻接表存图,队列实现)
/*
 * 单源最短路SPFA
 * 时间复杂度 0(kE)
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
    queue<int> que;//4
    while(!que.empty())que.pop();
    que.push(start);//5 入队(经典五步)
    while(!que.empty())
    {
        a=que.front();//取队首,a是取出来那个点，习惯用a跟next了../用u跟v也可以
        que.pop();
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
    //记得清空栈
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





