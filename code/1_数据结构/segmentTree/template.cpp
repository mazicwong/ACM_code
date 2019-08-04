#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
const int maxn = 1e5 + 5;
/*
 * problem :hdu 1754
 * 单点更新(加),区间查询(找最值)
 *
 * 输入: arr[]存叶子节点  (1...n)
 * build()  建树
 * update() 更新值
 * query()  查询最值
 */

inline int L(int l) { return l<<1;}
inline int R(int r) { return r<<1|1;}
inline int MID(int l, int r) { return (l+r)>>1;}
struct node{
    int l,r;
    int Max;//存区间最大值
    ll Sum; ll lazy;
}tree[maxn<<2];     //tree[1..2^n-1]
int arr[maxn];      //存放初始节点arr[1..n]
int ans = 0;        //查询到的最大值
ll sum = 0;         //查询到的和



void PushUp(int rt)
{
    tree[rt].Max = max(tree[L(rt)].Max, tree[R(rt)].Max); //最值
    tree[rt].Sum = tree[L(rt)].Sum + tree[R(rt)].Sum;     //和
}

void PushDown(int rt) //和
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
	tree[rt].l=l;  tree[rt].r=r;
    tree[rt].lazy=0; //和
	if (l==r)
    {
        tree[rt].Max = arr[l];//最值
        tree[rt].Sum = arr[l];//和
        return;
    }

    int mid = MID(l,r);
    build(l, mid, L(rt));
    build(mid+1, r, R(rt));

    PushUp(rt);
}

void update(int l, int r, int val, int rt)
{
    if (l==tree[rt].l && tree[rt].r==r)
    {
        tree[rt].Max = val; //最值
        tree[rt].lazy += val; //和
        tree[rt].Sum += (tree[rt].r-tree[rt].l+1)*val; //和
        return;
	}

    PushDown(rt); //和
    if (tree[rt].l == tree[rt].r) return;

    int mid = MID(tree[rt].l, tree[rt].r);
    if (mid<l) update(l,r,val,R(rt));
    else if (mid>=r) update(l,r,val,L(rt));
    else
    {
        update(l,mid,val,L(rt));
        update(mid+1,r,val,R(rt));
    }
    PushUp(rt);
}

//区间查询(和,最值)
void query(int l, int r, int rt)
{
    if (l<=tree[rt].l && tree[rt].r<=r)
    {
        sum += tree[rt].Sum; //和
        ans = max(ans,tree[rt].Max); //最值
        return;
    }

    PushDown(rt);  //和
    if (tree[rt].l == tree[rt].r) return;

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
            if ('U' == qq)  //单点更新
            {
                int idx,val;
                scanf("%d%d",&idx,&val);
                update(idx,idx,val,1);//left,right,value,root
            }
            else if ('Q' == qq) //区间更新
            {
                int idxl,idxr;
                ll val;
                scanf("%d%d%lld",&idxl,&idxr,&val);
                update(idxl,idxr,val,1);//left,right,value,rt
            }
            else if ('C'==qq)   //区间查询最值
            {
                int l,r;
                scanf("%d%d",&l,&r);
                ans = 0;
                query(l,r,1);//left,right,root
                printf("%d\n",ans);
            }
            else                //区间查询和
            {
                int l,r;
                scanf("%d%d",&l,&r);
                sum = 0;
                query(l, r, 1);//left,right,rt
                printf("%lld\n",sum);
            }
        }
    }
    return 0;
}
