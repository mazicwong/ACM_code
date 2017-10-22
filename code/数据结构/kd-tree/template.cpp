
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

----------------------------------------------------------------
----------------------------------------------------------------
----------------------------------------------------------------

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
