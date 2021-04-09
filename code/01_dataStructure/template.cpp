1.并查集
2.RMQ
  2.1 后缀数组的RMQ
  2.2 LCA的RMQ
3.树状数组 (单点更新,区间求和)
4.线段树
  4.1 区间更新,区间求和
  4.2 单点更新,区间最值
5.Trie
  5.1 静态模板(更好)
  5.2 动态模板
6.kd tree
  6.1 k维空间最近m个点
  6.2 二维面最近点带价值约束
7.树链剖分 (树链剖分是解决在树上进行插点问线,插线问点等一系列树上的问题)
8.主席树   (查询区间有多少个不同的数 + 静态区间第ka大)
           (树上路径点权第k大,LCA+主席树)
           (动态第k大,树状数组套主席树)
  8.1 主席树裸题----求序列的区间第k大
  8.2 在线查询数列在第k个版本,区间[l,r]上的最大值
9.lca+rmq 在线算法dfs+ST(感觉归在图论好点)


题型:
查询区间连续和问题: 前缀和   (O(n)预处理,O(1)查询)
动态查询区间连续和问题: BIT  (O(nlogn)预处理,O(logn)查询)
        add(x,d):   a[x]增加d        //O(logn)
        query(l,r): sum[a[l]..a[r]]  //O(logn)
查询区间最小值问题: RMQ      (O(nlogn)预处理,O(1)查询)
        RMQ::init()
        RMQ::query(l,r):  min{a[l]..a[r]}
动态查询区间最小值问题: 线段树
        线段树1: 单点更新+区间查询(单点更新也可以转化为区间更新)
        线段树2: 区间更新+区间查询(主要是lazy标记)


///////////////////////////////////////////////////////////////////////////
1.并查集(注意起始点是0or1)
int fa[maxn];
void init(int n) {for (int i=1;i<=n;i++) fa[i]=i;}
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
void unite(int x, int y)
{
    x=find(x), y=find(y);
    if (x!=y) fa[x]=y; //x指向y
}
# upd: 不加rank可能会有错误，e.g. (1,2; 2,1; 3,4; 3,5;) is right, while (1,2; 2,1; 4,3; 5,3) will throw error
# the new template in python is

fa = [i for i in range(N + 1)]
rank = [0 for i in range(N + 1)]
def find(x):
    if x==fa[x]:
        return x
    else:
        fa[x] = find(fa[x])
        return fa[x]
def unite(x, y):
    x, y = find(x), find(y)
    if rank[x] > rank[y]:
        fa[y] = x
    else:
        fa[x] = y
        if rank[x] == rank[y]:
            rank[y] += 1

///////////////////////////////////////////////////////////////////////////
2.RMQ
//(1).后缀数组
/**************RMQ算法***************************/
int dp[MAXN][20];
namespace RMQ //蓝书P198
{
    void init(int n)
    {
        for (int i=1;i<=n;i++) dp[i][0] = height[i];
        for (int j=1;(1<<j)<=n;j++)
            for (int i=1;i+(1<<j)-1<=n;i++)
                dp[i][j] = min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
    }
    int rmq(int l, int r)
    {
        int k=0;
        while (1<<(k+1) <= r-l+1) k++;
        return min(dp[l][k], dp[r-(1<<k)+1][k]);
    }
    int lcp(int a, int b)//lcp的选取方法是当前区间的height[]最小值
    {
        a=Rank[a];b=Rank[b];
        if (a>b) swap(a,b);
        return rmq(a+1,b);//返回sa[a],sa[b]的最大公共前缀,规约到rmq问题
    }
}
int main()
{
    //法1
    RMQ::init(len+1);
    int ans=n;
    //这里错了很久!!记得用len+1才是符合开始写的那些个条件
    for (int i=1;i<n;i++)
        ans = (ans+RMQ::lcp(0,i))%256;
    printf("%d\n",ans);
}
/**************RMQ算法***************************/

//(2).最长公共祖先lca
/**************RMQ算法***************************/
int st[maxn<<1][20];//rmq用来存的,st[i][j]从i开始的2^j个数
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
int main()
{
    ST(2*n-1); //初始化
}
/**************RMQ算法***************************/



///////////////////////////////////////////////////////////////////////////
3.树状数组
/*
 * 树状数组/BIT/二分索引树(kuangbin)
 * 单点更新,区间求和
 *
 * 树状数组是树和数组的结合,其实就是用一棵树的结构来存储一个数组,方便各种区间操作
 * 如: 求一棵树上所有节点的子节点个数和? 可以先通过dfs遍历树,对每个节点的子节点进行st和en的标记, 把树映射到区间上, 然后用BIT解决
 *
   操作:
   A[i]: 为要表示的原始数组 (有时需要离散化得到)
   c[i]: 树状数组
   插入 add(i,1);    O(logn) 第i个元素自增1
   删除 add(i,-1);
   询问 sum(i);      O(logn) 统计1..i元素值的和
 */
int arr[maxn];
int c[maxn];
int lowbit(int x) {return x&-x;}  //返回2^k,其中k是末尾0的个数
void add(int i,int val)
{
    while(i<=n)
    {
        c[i] += val;
        i+=lowbit(i); // 5行加,7行减
    }
}
int sum(int i)
{
    int res=0;
    while(i>0)
    {
        res += c[i];
        i-=lowbit(i); // 5行加,7行减
    }
    return res;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) arr[i]=read(), add(i,arr[i]);
    while(m--)
    {
        ll flag=read();
        if(flag==2)
        {
            l=read(); r=read();  cout<<sum(r)-sum(l-1)<<endl;
        }
        else
        {
            l=read(); r=read(); v=read();
            for(int i=l;i<=r;i++)
            {
                if(arr[i]>=v && arr[i]%v==0)
                {
                    add(i,val-arr[i]); //arr[i]替换为val
                    arr[i]=v;
                }
            }
        }
    }
}




///////////////////////////////////////////////////////////////////////////
4.线段树 (区间更新,区间求和 + 单点更新,区间最值)
//注意:后面的单点更新是把区间更新的模板(l,r)写成(l,l)

4.1 区间更新+区间求和
/*
 * poj3468
 * 区间更新(加),区间查询(求和)
 *
 * 输入: arr[]存点  (1...n)
 *
 * build()     建树
 * update()    更新值
 * query()     查询区间和
 * PushUp()    (建树和更新时)回溯维护value
 * PushDown()  (查询或更新有交集时才会用到)向下更新lazy,value
 * 
 * 更新: 如果刚好覆盖一个节点,则增加lazy值,否则更新value,再继续下传
 *       这样就不用每次都更新到叶子节点
 * 查询: 如果不是正好覆盖一个节点,则将lazy往下传,把lazy加到value上然后lazy清零,
 *       接着继续往下查询
 *
 *
 * LAZY标记(延迟标记)
 * 被lazy标记的非叶子节点所包含的所有叶子节点具有相同的性质，
 * 当更新或查询到该区间时，不再向下递归，仅对当前节点的lazy标记进行修改。
 */

typedef long long ll;
const int maxn = 1e5 + 5;
inline int L(int l) {return l<<1;}
inline int R(int r) {return (r<<1)+1;}
inline int MID(int l, int r) {return (l+r)>>1;}
struct node{
    int l,r;
    ll Sum;   //节点属性值,这里是区间和
    ll lazy;  //该节点对应所有子节点应该加上的值,才不用一直更新到叶子
}tree[maxn<<2];     //tree[1..2^n-1]
int arr[maxn];      //存放初始节点arr[1..n]
ll sum = 0;         //查询到的和

//"创建区间"和"更新区间"最后的递归回溯时向上更新value
//查询就不用了,
void PushUp(int rt)
{
    tree[rt].Sum = tree[L(rt)].Sum + tree[R(rt)].Sum;
}

//"查询"和"更新"时先PushDown一下处理子区间的lazy和value
void PushDown(int rt)
{
    if (tree[rt].lazy)
    {
        tree[L(rt)].lazy += tree[rt].lazy;
        tree[R(rt)].lazy += tree[rt].lazy;
        tree[L(rt)].Sum += (tree[L(rt)].r-tree[L(rt)].l+1)*tree[rt].lazy;
        tree[R(rt)].Sum += (tree[R(rt)].r-tree[R(rt)].l+1)*tree[rt].lazy;

        tree[rt].lazy = 0;
    }
}

void build(int l, int r, int rt)
{
    tree[rt].l=l; tree[rt].r=r;
    tree[rt].lazy=0;
    if (l==r) //找到叶子,赋值
    { 
        tree[rt].Sum = arr[l];
        return;
    }

    //分治
    int mid = MID(l,r);
    build(l,mid,L(rt));
    build(mid+1,r,R(rt));

    //回溯维护value(区间和)
    //因为建立属性值顺序只能从下到上,但是建树是从上往下的,所以回溯
    PushUp(rt);
}

//区间更新(每个点加一个值)
void update(int l, int r, int val, int rt)//更新范围[l,r],当前所在的根rt
{
    //if (l<=L(rt) && R(rt)<=r) ??? 因为(tree[rt].l,tree[rt].r)是表示该节点对应的区间范围;而L(rt),R(rt)是他的左右儿子节点
    //拿root=1举例子就很明显了,(1,n);(2,3);
    if (l<=tree[rt].l && tree[rt].r<=r)//单点更新的话,这里就用等于
    {
        //这个节点在更新的区间里面,直接算完lazy和value然后退出
        tree[rt].lazy += val;
        tree[rt].Sum += (tree[rt].r-tree[rt].l+1)*val;
        return;
    }

    PushDown(rt);
    if (tree[rt].l == tree[rt].r) return;

    //分治
    int mid = MID(tree[rt].l, tree[rt].r);
    if (mid<l) update(l,r,val,R(rt));        //在右子树中
    else if (mid>=r) update(l,r,val,L(rt));  //在左子树中
    else                                     //在左右子树中
    {
        update(l,mid,val,L(rt));
        update(mid+1,r,val,R(rt));
    }

    //回溯维护value
    PushUp(rt);
}

//区间查询(和)
void query(int l, int r, int rt)//查找的范围[l,r],当前所在根rt
{
    if (l<=tree[rt].l && tree[rt].r<=r)
    {
        sum += tree[rt].Sum;
        return;
    }

    PushDown(rt);
    if (tree[rt].l == tree[rt].r) return;

    //分治
    int mid = MID(tree[rt].l, tree[rt].r);
    if (mid<l) query(l,r,R(rt));
    else if (mid>=r) query(l,r,L(rt));
    else
    {
        query(l,mid,L(rt));
        query(mid+1,r,R(rt));
    }
}

int main()
{
    //freopen("in","r",stdin);
    int n, q;
    while (scanf("%d%d",&n,&q) != EOF)
    {
        for (int i=1; i<=n;i++)
            scanf("%d",&arr[i]);
        build(1,n,1);//left,right,rt

        while (q--)
        {
            getchar();
            char qq = getchar();
            if ('C' == qq) //update
            {
                int idxl,idxr;
                ll val;
                scanf("%d%d%lld",&idxl,&idxr,&val);
                update(idxl,idxr,val,1);//left,right,value,rt
            }
            else //sum
            {
                int l, r;
                scanf("%d%d",&l,&r);
                sum = 0;
                query(l, r, 1);//left,right,rt
                printf("%lld\n",sum);
            }
        }
    }
    return 0;
}

4.2 单点更新(加),区间查询(找最值)
/*
 * problem :hdu 1754
 * 单点更新(加),区间查询(找最值)
 *
 * 输入: arr[]存叶子节点  (1...n)
 * build()  建树
 * update() 更新值
 * query()  查询最值
 */
const int maxn = 2e5 + 5;
struct node{
    int l,r;
    int Max;//存区间最大值
}tree[maxn<<2];     //tree[1..2^n-1]
int arr[maxn];      //存放初始节点arr[1..n]
int ans = 0;        //查询到的最大值

void PushUp(int rt)
{
    //回溯时,对所有祖先节点PushUp赋属性值
    tree[rt].Max = max(tree[L(rt)].Max, tree[R(rt)].Max);
}

//初始化树节点,递归至叶子,回溯更新每个节点的值(l,r,val)
//有些属性自上而下就定完了,有些要先确定儿子的,所以要回溯才确定
void build(int l, int r, int rt)
{
    //l,r只改一次,后面不动了,只动属性值
	tree[rt].l=l;  tree[rt].r=r;
	if (l==r) //到叶子了,直接赋属性值
    {
        tree[rt].Max = arr[l];
        return;
    }

    //分治,二分区间
    int mid = MID(l,r);
    build(l, mid, L(rt));
    build(mid+1, r, R(rt));

    //回溯赋属性值
    PushUp(rt);
}

//更新区间(即更新区间对应节点以及他的所有祖先);祖先在回溯时候更新
void update(int l, int r, int val, int rt)
{
    if (l==tree[rt].l && tree[rt].r==r)//找到
    {
        tree[rt].Max = val;
        return;
    }

    int mid = MID(tree[rt].l, tree[rt].r);
    if (mid<l) update(l,r,val,R(rt));        //在右子树
    else if (mid>=r) update(l,r,val,L(rt));  //在左子树
    else                                     //同时在左右子树
    {
        update(l,mid,val,L(rt));
        update(mid+1,r,val,R(rt));
    }

    PushUp(rt);
}

//区间查询(最值--节点的属性值Max最大)
void query(int l, int r, int rt)//查找的范围[l,r],当前所在的根rt
{
    if (l==tree[rt].l && tree[rt].r==r)//找到区间(<=)
    {
        ans = max(ans,tree[rt].Max);
        return;
    }
    //if (tree[rt].l==tree[rt].r) return;

    int mid = MID(tree[rt].l, tree[rt].r);
    if (mid<l) query(l,r,R(rt));             //在右子树
    else if (mid>=r) query(l,r,L(rt));       //在左子树
    else                                     //同时在左右子树
    {
        query(l,mid,L(rt));
        query(mid+1,r,R(rt));
    }
}

int main()
{
    //freopen("in","r",stdin);
    int n,q;
    while (scanf("%d%d",&n,&q)!=EOF)
    {
        for (int i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        build(1,n,1);//left,right,root
        while (q--)
        {
            getchar();
            char qq = getchar();
            if ('U' == qq)
            {
                int idx,val;
                scanf("%d%d",&idx,&val);//这样操作单点更新就跟区间更新一样了
                update(idx,idx,val,1);//left,right,value,root
            }
            else
            {
                int l,r;
                scanf("%d%d",&l,&r);
                ans = 0;
                query(l,r,1);//left,right,root
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}


///////////////////////////////////////////////////////////////////////////
5.Trie 
模板: 找一个字符串是多少个字符串的前缀(hdu1251)
(静态效率更好,动态的指针很容易MLE)
//用多个字符串构造出来一颗树,相同前缀的串共用一些节点,在查询前缀后缀的时候很好用

5.1 静态模板
/*
 * hdu1251 Trie模板题(静态)
 * 给一堆串组成的字典,
 * 然后给一些查询,问一个子串是多少个串的前缀
 * 注意字典和查询中间用空行分开(这里用gets判断第一个是不是'\0'就行了)
 * gets: 可以读取一个空行,每一行最后的'\n'会转换成'\0'
 */
#pragma comment(linker, "/STACK:102400000,102400000")
const int maxn = 1e6+5;//??总节点数,怎么搞
int Trie[maxn][26];
int num[maxn]={0}; //节点属性值,根据题意来定,这里是以该串为前缀单词数
int tot = 1;//节点个数

void insert(char *str)
{
    int len = strlen(str);
    int p = 0;
    for (int i=0;i<len;i++)
    {
        int id = str[i]-'a';
        if (Trie[p][id]==0)
            Trie[p][id]=tot++;
        p=Trie[p][id];
        num[p]++;//节点属性值
    }
}

int query(char *str)
{
    int len = strlen(str);
    int p = 0;
    for (int i=0;i<len;i++)
    {
        int id = str[i]-'a';
        if (Trie[p][id]==0)
            return 0;
        p=Trie[p][id];
    }
    return num[p];
}

char str[11];
int main()
{
    freopen("in","r",stdin);
    tot=1;
    while(gets(str) && str[0]!='\0')
    {
        insert(str);
    }
    while(scanf("%s",str)!=EOF)
    {
        printf("%d\n",query(str));
    }
    return 0;
}

5.2 动态模板
/*
 * hdu1251 Trie模板题(动态)
 * 给一堆串组成的字典,
 * 然后给一些查询,问一个子串是多少个串的前缀
 *
 * 注意输入字典和查询串中间用空行分开(这里用gets判断第一个是不是'\0'就行了)
 * gets: 可以读取一个空行,每一行最后的'\n'会转换成'\0'
 */

#pragma comment(linker, "/STACK:102400000,102400000")
struct Trie{
    int v;//节点属性,随题目改动,这里是有多少个串路过(即到该节点的串是多少个串的前缀)
    Trie *next[26];//儿子数,26个字母
    Trie()
    {
        v = 0;
        memset(next,0,sizeof(next));
    }
};
Trie *root;//根节点指针

void insert(char *str)
{
    int len = strlen(str);
    Trie *p = root;
    for (int i=0;i<len;i++)
    {
        int id = str[i]-'a';
        if (p->next[id]==NULL)
            p->next[id] = new Trie;
        p = p->next[id];
        p->v++;
    }
}

int query(char *str)
{
    int len = strlen(str);
    Trie *p = root;
    for (int i=0;i<len;i++)
    {
        int id = str[i]-'a';
        if (p->next[id]==NULL)
            return 0;
        p = p->next[id];
    }
    return p->v;
}

//多组数据的Trie要delete_,不然MLE
void delete_(Trie *p)
{
    if (p==0)
        return;
    for (int i=0;i<26;i++)
        delete_(p->next[i]);
    delete p;
}

const int maxn = 11;
char str[maxn];
int main()
{
    freopen("in","r",stdin);
    root = new Trie;
    while(gets(str) && str[0]!='\0')
    {
        insert(str);
    }
    while(scanf("%s",str)!=EOF)
    {
        printf("%d\n",query(str));
    }
    delete_(root);
    return 0;
}



///////////////////////////////////////////////////////////////////////////
6.kd tree (范围搜索,最邻近搜索)
//一种支持查询平面最近点(k维)的数据结构,单次理论时间复杂度O(sqrt(n))
//分割k维数据空间的数据结构

6.1 k维空间最近m个点
//hdu4347 求一个k维空间的点的最近m个点(欧几里得距离)
//M近邻和最邻近是一样的;M近邻只需要多个优先队列就行了;
//先一路递归到叶子节点,然后维护优先队列M个节点
/* 
3 2   //n,k(n点,k维)
1 1
1 3
3 4
2     //t(询问数)
2 3   //询问的坐标
2     //询问的最近m个点
2 3
1
----------------------------
the closest 2 points are:
1 3
3 4
the closest 1 points are:
1 3
*/
typedef long long LL;
const int maxn = 50080;
#define K 5  
int num,nownum,m;  
LL ans;  
struct kdNode  
{  
    LL x[K];   
    int div;  
    bool lef;  
}Ans[12];  
struct Node  
{  
    kdNode a;  
    LL dis;//表示和目标点的距离  
    bool operator < (const Node & a) const  
    {  
        return dis < a.dis;  
    }  
    Node(){}  
    Node(kdNode & tmp,LL d)  
    {  
        a = tmp;  
        dis = d;  
    }  
};  
  
int cmpNo;  
bool cmp(kdNode a,kdNode b)  
{  
    return a.x[cmpNo] < b.x[cmpNo];  
}  
  
inline LL max(LL a,LL b)  
{  
    return a>b?a:b;  
}  
kdNode p[maxn],q;  
  
LL dis(kdNode a,kdNode b,int k)  
{  
    LL res = 0;  
    for(int i = 0;i < k;i++)  
        res += (a.x[i] - b.x[i])*(a.x[i] - b.x[i]);  
    return res;  
}  
  
priority_queue <Node> qq;  
void buildKD(int l,int r,kdNode * p,int d,int k)  
{  
    if(l > r)    return;  
    int m = (l+r) >> 1;  
    cmpNo = d;  
    nth_element(p+l,p+m,p+r+1,cmp);  
    p[m].div = d;  
    if(l == r)      
    {  
        p[m].lef = 1;  
        return;  
    }  
    buildKD(l,m-1,p,(d+1)%k,k);  
    buildKD(m+1,r,p,(d+1)%k,k);  
}  
  
void findKD(int l,int r,kdNode & tar,kdNode * p,int k)  
{  
    if(l>r)    return;  
    int m = (l+r) >> 1;  
    LL d = dis(p[m],tar,k);  
    if(p[m].lef)//如果是叶子  
    {  
        if(nownum < num)      
        {  
            nownum++;  
            ans = max(ans,d);  
            qq.push(Node(p[m],d));  
        }  
        else if(ans > d)  
        {  
            qq.pop();  
            qq.push(Node(p[m],d));  
            ans = qq.top().dis;  
        }  
        return;  
    }  
    LL t = tar.x[p[m].div] - p[m].x[p[m].div];  
    if(t > 0)  
    {  
        findKD(m+1,r,tar,p,k);  
        if(nownum < num)  
        {  
            qq.push(Node(p[m],d));  
            nownum++;  
            ans = qq.top().dis;  
            findKD(l,m-1,tar,p,k);  
        }  
        else   
        {      
            if(ans > d)  
            {  
                qq.pop();  
                qq.push(Node(p[m],d));  
                ans = qq.top().dis;  
            }  
            if(ans > t*t)  
                findKD(l,m-1,tar,p,k);  
        }  
    }  
    else   
    {      
        findKD(l,m-1,tar,p,k);  
        if(nownum < num)  
        {  
            qq.push(Node(p[m],d));  
            nownum++;  
            ans = qq.top().dis;  
            findKD(m+1,r,tar,p,k);  
        }  
        else  
        {  
            if(ans > d)  
            {  
                qq.pop();  
                qq.push(Node(p[m],d));  
                ans = qq.top().dis;  
            }  
            if (ans > t*t)  
                findKD(m+1,r,tar,p,k);  
        }  
  
    }  
}  
int main()  
{  
    int n,k;  
    while(scanf("%d%d",&n,&k)==2)  
    {  
        for(int i = 0;i < n;i++)  
        {  
            for(int j = 0;j < k;j++)  
            {  
                scanf("%I64d",&p[i].x[j]);  
            }  
            p[i].lef = 0;  
        }  
        int t;  
        scanf("%d",&t);  
        buildKD(0,n-1,p,k-1,k);  
        for(int i = 1;i <= t;i++)  
        {  
            ans = -1;  
            nownum = 0;  
            for(int j = 0;j < k;j++)  
                scanf("%I64d",&q.x[j]);  
            while(!qq.empty())        qq.pop();  
            scanf("%d",&num);  
            findKD(0,n-1,q,p,k);  
            for(int j = 1;j <= num;j++)  
            {  
                Ans[j] = qq.top().a;  
                qq.pop();  
            }  
            printf("the closest %d points are:\n",num);  
            for(int j = num;j >= 1;j--)  
            {  
                for(int kk = 0;kk < k;kk++)  
                {  
                    if(kk == 0)  
                        printf("%I64d",Ans[j].x[kk]);  
                    else printf(" %I64d",Ans[j].x[kk]);  
                }  
                puts("");  
            }  
        }  
    }  
    return 0;  
}  

6.2 二维面最近点带价值约束
//hdu5992: n点,每个点有位置+价格
//给m个查询,找一个可以接受的价格且距离最短的点(Euclidean metric)
//直接建树,直接查找,加一个比较价格 (模板题)
/*
1       //T
3 3     //n点,m询问
1 1 1   //每个点包含x,y,c
3 2 3
2 3 2
2 2 1
2 2 2
2 2 3
----------
1 1 1
2 3 2
3 2 3
*/
typedef long long ll;
typedef pair<int,int> pii;
const ll inf=1e17;
const int N = 200000 + 5;
const int M = 20000 + 5;

const int demension=2;//二维
struct P{
    int pos[demension],c,id;
}hotel[N];
P kdtree[N];
double var[demension];//方差
int split[N];//i为根的子树 分裂方式为第split[i]维
int cmpDem;//以第cmpDem维作比较
bool cmp(const P&a,const P&b){
    return a.pos[cmpDem]<b.pos[cmpDem];
}

void build(int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        //计算每一维方差
        for(int i=0;i<demension;++i){
            double ave=0;//均值
            for(int j=l;j<=r;++j){
                ave+=hotel[j].pos[i];
            }
            ave/=(r-l+1);
            var[i]=0;//方差
            for(int j=l;j<=r;++j){
                var[i]+=(hotel[j].pos[i]-ave)*(hotel[j].pos[i]-ave);
            }
            var[i]/=(r-l+1);
        }
        //更新mid为树根时 分裂方法为第几维
        split[mid]=-1;
        double maxVar=-1;
        for(int i=0;i<demension;++i){//找方差最大的维
            if(var[i]>maxVar){
                maxVar=var[i];
                split[mid]=i;
            }
        }
        //以第mid个元素为中心 排序
        cmpDem=split[mid];
        nth_element(hotel+l,hotel+mid,hotel+r+1,cmp);
        //左右子树
        build(l,mid-1);
        build(mid+1,r);
    }
}

int ansIndex;
ll ansDis;//ansDis=欧几里得距离^2
void query(int l,int r,P op){
    if(l>r){
        return;
    }
    int mid=(l+r)/2;
    //op到根节点距离
    ll dis=0;
    for(int i=0;i<demension;++i){
        dis+=(ll)(op.pos[i]-hotel[mid].pos[i])*(op.pos[i]-hotel[mid].pos[i]);
    }
    //更新ans
    if(hotel[mid].c<=op.c){ //这里要用到价格才用的
        if(dis==ansDis&&hotel[mid].id<hotel[ansIndex].id){
            ansIndex=mid;
        }
        if(dis<ansDis){
            ansDis=dis;
            ansIndex=mid;
        }
    }
    int d=split[mid];
    ll radius=(ll)(op.pos[d]-hotel[mid].pos[d])*(op.pos[d]-hotel[mid].pos[d]);//到分裂平面距离
    if(op.pos[d]<hotel[mid].pos[d]){
        query(l,mid-1,op);
        if(ansDis>=radius){
            query(mid+1,r,op);
        }
    }
    else{
        query(mid+1,r,op);
        if(ansDis>=radius){
            query(l,mid-1,op);
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i){
            scanf("%d%d%d",&hotel[i].pos[0],&hotel[i].pos[1],&hotel[i].c);
            hotel[i].id=i;
        }
        build(0,n-1);
        P p;
        for(int i=0;i<m;++i){
            scanf("%d%d%d",&p.pos[0],&p.pos[1],&p.c);
            ansDis=inf;
            ansIndex=-1;
            query(0,n-1,p);
            printf("%d %d %d\n",hotel[ansIndex].pos[0],hotel[ansIndex].pos[1],hotel[ansIndex].c);
        }
    }
    return 0;
}




///////////////////////////////////////////////////////////////////////////
7.树链剖分 (树链剖分是解决在树上进行插点问线,插线问点等一系列树上的问题)
其实树链剖分就是把边哈希到线段树上的数据结构。



///////////////////////////////////////////////////////////////////////////
8.主席树
8.1 主席树裸题----求序列的区间第k大
/*
 * 主席树裸题----求序列的区间第k大
 * http://www.cnblogs.com/Yuzao/p/7109577.html
 *
 * 给a[1..n]和m个询问
 * Q(l,r,k): 找[l,r]中排序后第k大的数
 *
 *
 * 开n个线段树,用主席树维护,n个分别表示[i,j]区间中[L,R]区间内数字个数,相当于前缀和
 * 区间询问[x,y]: 求root[y]-root[x-1]两颗主席树的sum之差
 *
 *
 * 具体怎么求K大:
 * 建立n棵线段树，第i棵线段树储存的是前i个值出现的次数。
 * 然后求[l,r]区间的数，就用第r棵线段树减去第l-1棵线段树就好了。
 * 然后进行二分操作，求出k大。
 *
 *
 * 原话:想法是对原序列的每一个前缀[1..i]建立出一颗线段树维护值域上
 * 每个数的出现次数，然后发现这样的树是可以减的，然后就没有然后了
 *
 */

/*
7 3
1 5 2 6 3 7 4
2 5 3    //[2,5]第3大:5
4 4 1    //[4,4]第1大:6
1 7 3    //[1,7]第3大:3
*/
const int N=100005,M=5005;
int gi()
{
    int str=0,f=1;char ch=getchar();
    while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9')str=(str<<1)+(str<<3)+ch-48,ch=getchar();
    return str*f;
}
struct node{
    int x,id;
}a[N];
int bel[N],root[N];
bool comp(const node &p,const node &q){return p.x<q.x;}
struct Tree{
    int ls,rs,sum;
}t[N*20];
int tot=0;
void insert(int &rt,int fa,int x,int l,int r)
{
    rt=++tot;
    t[rt].sum=t[fa].sum;
    t[rt].sum++;
    if(l==r)return ;
    int mid=(l+r)>>1;
    if(x<=mid)
    {
        insert(t[rt].ls,t[fa].ls,x,l,mid);
        t[rt].rs=t[fa].rs;
    }
    else
    {
        insert(t[rt].rs,t[fa].rs,x,mid+1,r);
        t[rt].ls=t[fa].ls;
    }
}
int query(int rt,int fa,int k,int l,int r)
{
    if(l==r)return a[l].x;
    int mid=(l+r)>>1,kt=t[t[rt].ls].sum-t[t[fa].ls].sum;
    if(k<=kt)return query(t[rt].ls,t[fa].ls,k,l,mid);
    else return query(t[rt].rs,t[fa].rs,k-kt,mid+1,r);
}
int main()
{
    freopen("in","r",stdin);
    int n=gi(),m=gi();
    for(int i=1;i<=n;i++)a[i].x=gi(),a[i].id=i;
    sort(a+1,a+n+1,comp);
    for(int i=1;i<=n;i++)bel[a[i].id]=i;
    for(int i=1;i<=n;i++)
        insert(root[i],root[i-1],bel[i],1,n);
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
        x=gi();y=gi();z=gi();
        printf("%d\n",query(root[y],root[x-1],z,1,n));
    }
}

8.2 查询数列在第k个版本,区间[l,r]上的最大值
/*
 * 主席树模板
 *
 * Q k l r : 查询数列在第k个版本,区间[l,r]上的最大值
 * M k p v : 数列在第k个版本的第p个数修改为v,产生下一个版本
 * 最开始的数列作为第一个版本,每次修改一个点,只用修改一条链上的logn个节点,
 * 则m次修改操作,有root[1..m]个根节点,查询第k次则从第k个版本的树根开始,像查询普通线段树一样就好了
 */

/*
4 5 
1 2 3 4   //版本1
0 1 1 4   //查询版本1的[1,4]最大值4
1 1 3 5   //修改产生版本2: 1 2 5 4
0 2 1 3   //查询版本2的[1,3]最大值5
0 2 4 4   //查询版本2的[4,4]最大值4
0 1 2 4   //查询版本1的[2,4]最大值4
*/

//http://www.cnblogs.com/Yuzao/p/7107439.html

inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }
const int maxn = 1e4+5;//点数
const int maxm = 1e5+5;//修改版本数
const int INF = 0x3f3f3f3f;

struct node{
    int ls,rs;
    int val;//区间最值
}t[maxm*10];

int gi()
{
    int str=0,f=1;char ch=getchar();
    while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9')str=(str<<1)+(str<<3)+ch-48,ch=getchar();
        return str*f;
}
int arr[maxn];  //maxn个点
int root[maxm]; //maxm个版本的树根
int tot=0;      //总节点数
int num=1;      //版本数

//建立第一个树根root[1],最开始的版本
void build(int &rt,int l,int r)
{
    rt=++tot;
    if(l==r)//叶子
    {
        t[rt].val=arr[l];
        return;
    }

    //递归
    int mid = MID(l,r);
    build(t[rt].ls,l,mid);
    build(t[rt].rs,mid+1,r);
    t[rt].val = max(t[t[rt].ls].val, t[t[rt].rs].val);
}

//update
//new_root,now_root,left,right,idx,val
void update(int &rt,int fa,int l,int r,int p,int to)
{
    rt=++tot;
    if(l==r)
    {
        t[rt].val=to;
        return;
    }

    int mid=MID(l,r);
    if(p<=mid) //在左子树
    {
        update(t[rt].ls,t[fa].ls,l,mid,p,to);
        t[rt].rs=t[fa].rs;
    }
    else       //在右子树
    {
        update(t[rt].rs,t[fa].rs,mid+1,r,p,to);
        t[rt].ls=t[fa].ls;
    }
    t[rt].val=max(t[t[rt].ls].val,t[t[rt].rs].val);
}


//查询最值(节点的value最大)
//root,left,right,cha_left,cha_right
int query(int rt,int l,int r,int sa,int se)
{
    if(l>se || r<sa)return -INF;
    if(sa<=l && r<=se)return t[rt].val;
    int mid = MID(l,r);
    return max(query(t[rt].ls,l,mid,sa,se),query(t[rt].rs,mid+1,r,sa,se));
}

int main()
{
    freopen("in","r",stdin);
    int n=gi(),m=gi();
    for (int i=1;i<=n;i++) arr[i]=gi();
    build(root[1],1,n);//root,left,right
    int flag,k,l,r;
    for (int i=0;i<m;i++)
    {
        flag=gi();k=gi();l=gi();r=gi();
        if (flag==0) //query 第k个版本的[l,r]的最值
            printf("%d\n",query(root[k],1,n,l,r));//root,left,right,cha_left,cha_right
        else //update 第k个版本的第l个数改为r,变成第num+1个版本
            update(root[++num],root[k],1,n,l,r);//root,father,left,right,idx,val
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////////
9.lca+rmq
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


