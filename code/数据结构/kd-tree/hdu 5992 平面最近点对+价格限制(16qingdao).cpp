#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<ctime>
#include <string.h>
#include<math.h>
using namespace std;
//hdu5992: n点,每个点有位置+价格
//给m个查询,找一个可以接受的价格且距离最短的点(Euclidean metric)
//直接建树,直接查找,加一个比较价格 (模板题)
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
