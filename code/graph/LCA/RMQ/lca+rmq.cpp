//lca: 最近公共祖先
//dfs+ST: 在线算法
//tarjan: 离线算法

//模板:仿hdu2586: n点q询问,问树中两点的距离(路径唯一)
const int maxn = 1e5+5;

struct edge{  //(u,v)边
    int to;   //这条边指向的节点(v点)
    int next; //这条边的上一条边(同样邻接到u点的边)
    /*有权树 int cost;*/
}e[maxn<<1];  //e[0..2n-3] 树e=n-1

int head[maxn]; //存每个点遍历到的最后一个儿子
int tot=0;      //存边

void add(int u,int v){
    e[tot].to=v;
    /*有权树 e[tot].cost=val; (传入val)*/
    e[tot].next=head[u];//next存上一次访问u点的边,用来回溯时找到u点所有边
    head[u]=tot++;//head[u]存每次访问的边,最终是指向一个点的最后一条边
}

//que[]:欧拉序列,即dfs遍历的顺序
int que[maxn<<1];//第i次dfs访问节点的编号[1..2n-1]  (vs[i])
int dep[maxn<<1];//按dfs为下标的深度(按节点是dep[[fir[u]]])
int fir[maxn];//在que数组中i节点首次出现的下标 (id[i])
int vis[maxn<<1];//dfs中是否访问过节点

int p[maxn<<1];//每个点的父节点
int st[maxn<<1][20];//只在rmq中用到,st[i][j]从i开始的2^j个数
int cnt=0;

void dfs(int u,int d)//传入点跟深度
{//递归得到que[1..2n-1],fir[1..n],dep[1..2n-1]
    vis[u]=1;
    que[++cnt]=u;fir[u]=cnt;dep[cnt]=d;//dep[cnt]=d是que[]对应深度;dep[u]=d是直接u点深度,用depth()代替(4小时的血与泪..)
    for (int k=head[u];k!=-1;k=e[k].next)//head[u],u指向的最后一条边
    {
        int v=e[k].to;
        if (!vis[v])
        {
            p[v]=u;
            dfs(v,d+1);/*有权树 dfs(v,d+e[k].cost);*/
            que[++cnt]=u;dep[cnt]=d;//访问完一个子树,自己要再次入队,但是fir[]不用更新
        }
    }
}

/**************RMQ算法***************************/
//点从1~n,先ST(2*n-1)预处理RMQ (O(nlogn))
//然后每次询问LCA(T,u,v)都转化到RMQ上解决 (O(1))
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
/**************RMQ算法--END**********************/


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
    //n个点(1~n),q个询问
    int n,q; cin>>n>>q;
    init();
    for(int i=1;i<=n-1;i++)
    {
        int u,v; cin>>u>>v;
        add(u,v);/*有权图就 add(u,v,val);*/
        add(u,v);
    }
    /*如果不是连通图,只用这里改成
      for(i=1..n) if(!vis[i]) dfs(i,1);
      然后再套下并查集模板*/
    dfs(1,1);
    ST(2*n-1);
    while(q--)
    {
        int u,v; cin>>u>>v;
        int tmp = lca(u,v);//给出最近祖先
        cout << (depth(u)+depth(v)-2*depth(tmp));//求u,v的深度
    }
}

