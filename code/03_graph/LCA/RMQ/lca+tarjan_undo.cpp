const int maxn = 1e3+5;//点数最大
const int maxq = 1e5+5;//查询数最大

/**************union_find************************/
int fa[maxn];
void init_fa(int n)
{
    for (int i=1;i<=n;i++)
        fa[i]=i;
}
int find(int x)
{
    if (x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}
void union(int u,int v)
{
    int x=find(u);
    int y=find(v);
    if (x!=y)
        fa[u]=fa[v];
}
/**************union_find************************/



struct edge{//邻接表常用to点,next边(儿子兄弟表示法)
    int to;
    int next;
    /*有权树 int cost;*/
}e[maxn<<1];
int head[maxn]; //存每个点遍历到的最后一个儿子
int tot=0;      //存边
void add(int u,int v){
    e[tot].to=v;
    /*有权树 e[tot].cost=val;*/
    e[tot].next=head[u];
    head[u]=tot++;
}

//que[]:欧拉序列,即dfs遍历的顺序
int que[maxn<<1];//第i次dfs访问节点的编号[1..2n-1]  (vs[i])
int dep[maxn<<1];//按dfs为下标的深度(按节点是dep[[fir[u]]])
int fir[maxn];//在que数组中i节点首次出现的下标 (id[i])
int vis[maxn<<1];//dfs中是否访问过节点

int p[maxn<<1];//每个点的父节点
int st[maxn<<1][20];//rmq用来存的,st[i][j]从i开始的2^j个数
int cnt=0;

void dfs(int u,int d)//传入点跟深度
{
    vis[u]=1;
    que[++cnt]=u;fir[u]=cnt;dep[cnt]=d;
    for (int k=head[u];k!=-1;k=e[k].next)
    {
        int v=e[k].to;
        if (!vis[v])
        {
            p[v]=u;
            dfs(v,d+1);/*有权树 dfs(v,d+e[k].cost);*/
            que[++cnt]=u;dep[cnt]=d;
        }
    }
}
void ST(int n)
{//ST函数,预处理st[i,j],从i开始2^j个数的最小值
    for(int i=1;i<=n;i++)
        st[i][0]=i;
    for(int j=1;(1<<j)<=n;j++)
	{
        for(int i=1;i+(1<<j)-1<=n;i++)
		{
            int a=st[i][j-1],b=st[i+(1<<(j-1))][j-1];
            st[i][j]=dep[a]<dep[b]?a:b;
        }
    }
}
int RMQ(int l,int r)
{//传入两个点在que[]中首次出现位置,然后返回最小值在que[]中位置
//RMQ函数,计算[l,r]中dep[]最小的
    int k=0;
    while((1<<(k+1))<=r-l+1)
        k++;
    int a=st[l][k],b=st[r-(1<<k)+1][k];
    return dep[a]<dep[b]?a:b;
}
int lca(int u,int v)
{//LCA(T,u,v) = RMQ(dep,fir[u],fir[v]) (lca转化为rmq)
    int x=fir[u],y=fir[v];
    if(x>y) swap(x,y);
    int ans=RMQ(x,y);
    return que[ans];
}

/********************************************/
/*struct path{
	int u,v;
	int lca;
}pa[maxn];

int cmp(path x,path y)
{
    return dep[fir[x.lca]]>dep[fir[y.lca]];
}
int used[maxn];*/
/********************************************/
void init()
{
    tot=0;
    cnt=0;
    p[1]=0;
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    //memset(used,0,sizeof(used));
}

int depth(int u)
{//从叶子往上的深度
    return dep[fir[u]];
}
int main()
{
    int n,q; cin>>n>>q;
    init();
    for(int i=2;i<=n;i++)
    {
        int u,v; cin>>u>>v;
        add(u,v);/*有权图 add(u,v,val);*/
        add(u,v);
    }
    dfs(1,1);/*森林for(i 1..n) if(!vis[i]) dfs(i,1);*/
    ST(2*n-1);
}


