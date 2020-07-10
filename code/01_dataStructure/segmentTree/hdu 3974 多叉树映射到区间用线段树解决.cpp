/*************************************************************************
	> File Name: hdu3974.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月03日 星期二 18时55分53秒
 ************************************************************************/

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
 * n个人组成一棵树
 * 操作1: 给x分配任务y,则x和他所有下级都要停下工作去做y
 * 操作2: 查询x当前在做什么任务
 *
 * 显然,用线段树表示的话,节点属性用task,则该区间所表示的点全都在做这个任务,恰好可以支持区间查询和区间更新
 * 但是,每个节点的儿子怎么能表示成一段区间呢?
 *
 * 这是一个多叉树,所以我们先将树映射为区间,
 * 具体操作是,dfs,把每个人的所有下属排列到区间上,(神奇的脑回路)
 *
 */

inline int MID(int l,int r){return (l+r)>>1;}
inline int L(int l){return l<<1;}
inline int R(int r){return (r<<1)+1;}
const int maxn = 5e4+5;
struct node{
    int l,r;
    int task;
}tr[maxn<<2];

vector<int> boss[maxn<<2];
vector<int> employee[maxn<<2];
int S[maxn<<2],E[maxn<<2];


//这里的更新是从上到下的,所有不用PushUp来回溯
//void PushUp(int rt)


int cnt=0;
void dfs(int u) //树映射到区间,S,E记录每个人区间的左右顶点
{
    cnt++;
    S[u]=cnt;
    for (int i=0;i<boss[u].size();i++)
    {
        int v = boss[u][i];
        dfs(v);
    }
    E[u]=cnt;
}

void PushDown(int rt)
{
    if (tr[rt].task!=-1)
    {
        tr[L(rt)].task=tr[rt].task;
        tr[R(rt)].task=tr[rt].task;
        tr[rt].task=-1; //?
    }
}

void build(int rt,int l,int r)
{
    tr[rt].l=l; tr[rt].r=r;
    tr[rt].task=-1;
    if (l==r)
        return;
    int mid = MID(l,r);
    build(L(rt),l,mid);
    build(R(rt),mid+1,r);
}

//区间更新,找到某个人,然后更新他和儿子
void update(int rt,int l,int r,int y)
{
    if (tr[rt].l==l && tr[rt].r==r)
    {
        tr[rt].task = y;
        return;
    }
    if (tr[rt].l==tr[rt].r)
        return;
    PushDown(rt);

    int mid = MID(tr[rt].l,tr[rt].r);
    if (mid>=r)
        update(L(rt),l,r,y);
    else if (mid<l)
        update(R(rt),l,r,y);
    else
    {
        update(L(rt),l,mid,y);
        update(R(rt),mid+1,r,y);
    }
}

//单点查询
int query(int rt,int x)
{
    if (tr[rt].l==x && tr[rt].r==x)
        return tr[rt].task;
    PushDown(rt);

    int mid = MID(tr[rt].l,tr[rt].r);
    if (x<=mid)
        return query(L(rt),x);
    else return query(R(rt),x);
}

int n;
void init()
{
    for (int i=0;i<=n;i++)
    {
        boss[i].clear();
        employee[i].clear();
    }
    cnt=0;
}
int main()
{
    freopen("in","r",stdin);
    int t;cin>>t;
    for (int cas=1;cas<=t;cas++)
    {
        printf("Case #%d:\n",cas);
        cin>>n;
        init();
        for (int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v); //v是u上级
            boss[v].push_back(u);
            employee[u].push_back(v);
        }
        for (int i=1;i<=n;i++)
        {
            if (employee[i].size()==0) //找根
            {
                dfs(i);
                break;
            }
        }
        build(1,1,cnt);

        //cout << endl << "cnt: " << cnt << endl;

        int q;
        scanf("%d",&q);
        char ch[5];
        for (int i=0;i<q;i++)
        {
            scanf("%s",ch);
            int x,y;
            if (ch[0]=='C')
            {
                scanf("%d",&x); //query for the task of x
                cout << query(1,S[x]) << endl;//查找单点S[x]
            }
            else 
            {
                scanf("%d%d",&x,&y); //assign task y to x
                update(1,S[x],E[x],y); //将(S[x],E[x])区间更新为y
            }
        }
    }
    return 0;
}
