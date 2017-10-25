#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 2e5 + 5;

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
inline int R(int r) { return (r<<1)+1;}
inline int MID(int l, int r) { return (l+r)>>1;}
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
