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


///////////////////////////////////////


/*
 * prim,堆优化版,适用稠密图,在一个空集合中不断加入外面的点
 * O(e*lgn)
 * hdu1102 给邻接矩阵,求最小生成树
 */

#include <iostream>
using namespace std;
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

