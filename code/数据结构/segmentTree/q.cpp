#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
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

inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }
typedef struct {
    int left, right;
    int value;//存区间和
}node;
node tree[maxn<<2];//tree[1..2^n-1]
int arr[maxn];//存放初始节点arr[1..n]
ll ans = 0;//查询到的最大值

void build(int l, int r, int rt)
{
	tree[rt].left = l;
	tree[rt].right = r;
	if (l==r) //找到叶子,赋值
    {
        tree[rt].value = arr[l];
        return;
    }
    int mid = MID(l,r);
    build(l, mid, L(rt));
    build(mid+1, r, R(rt));
    tree[rt].value = max(tree[L(rt)].value, tree[R(rt)].value);
}


//更新区间(和)
void update(int l, int r, int val, int rt)
{
    if (l==tree[rt].left && tree[rt].right==r)//找到
    {
        tree[rt].value = val;
        return;
	}

    int mid = MID(tree[rt].left, tree[rt].right);
    if (mid<l) update(l,r,val,R(rt));        //在右子树
    else if (mid>=r) update(l,r,val,L(rt));  //在左子树
    else                                     //同时在左右子树
    {
        update(l,mid,val,L(rt));
        update(mid+1,r,val,R(rt));
    }
    tree[rt].value = max(tree[L(rt)].value, tree[R(rt)].value);
}

//查询最值(节点的value最大)
void query(int l, int r, int rt)//查找的范围[l,r],当前所在的根rt
{
    if (l==tree[rt].left && tree[rt].right==r)//找到区间
    {
        ans = max(ans,tree[rt].value);
        return;
    }

    int mid = MID(tree[rt].left, tree[rt].right);
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
    freopen("in","r",stdin);
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
            if ('C' == qq)//add
            {
                int idxl,idxr,val;
                scanf("%d%d%d",&idxl,&idxr,&val);
                update(idxl,idxr,val,1);//left,right,value,root
            }
            else //query
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
