#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

/*
参考题型: 
poj 3468 裸的线段树区间更新与查询问题
	区间更新: 加上一个数
	区间查询: 求和
hdu 1166
	单点更新: 加或者减一个数
	区间查询: 求和
hdu 1698 
	区间更新: 替换为别的数
	区间查询: 求和
*/



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

inline int L(int l) {return l<<1;}
inline int R(int r) {return (r<<1)+1;}
inline int MID(int l, int r) {return (l+r)>>1;}
struct {
    int l,r;
    ll val;   //节点属性值,这里是区间和
    ll lazy;  //该节点对应所有子节点应该加上的值,才不用一直更新到叶子
}tree[maxn<<2];     //tree[1..2^n-1]
int arr[maxn];      //存放初始节点arr[1..n]
ll sum = 0;         //查询到的和


//"创建区间"和"更新区间"最后的递归回溯时向上更新value
void PushUp(int rt)
{
    tree[rt].val = tree[L(rt)].val + tree[R(rt)].val;
}


//"查询"和"更新"时先PushDown一下处理子区间的lazy和value
void PushDown(int rt)
{
    if (tree[rt].lazy)
    {
        tree[L(rt)].lazy += tree[rt].lazy;
        tree[R(rt)].lazy += tree[rt].lazy;
        tree[L(rt)].val += (tree[L(rt)].r-tree[L(rt)].l+1)*tree[rt].lazy;
        tree[R(rt)].val += (tree[R(rt)].r-tree[R(rt)].l+1)*tree[rt].lazy;

        tree[rt].lazy = 0;
    }
}

void build(int l, int r, int rt)
{
    tree[rt].l=l; tree[rt].r=r;
    tree[rt].lazy = 0;
    if (l==r) //找到叶子,赋值
    { 
        tree[rt].val = arr[l];
        return;
    }

    //分治
    int mid = MID(l,r);
    build(l,mid,L(rt));
    build(mid+1,r,R(rt));

    //回溯维护value(区间和)
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
        tree[rt].val += (tree[rt].r-tree[rt].l+1)*val;
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

//查询区间(和)
void query(int l, int r, int rt)//查找的范围[l,r],当前所在根rt
{
    if (l<=tree[rt].l && tree[rt].r<=r)
    {
        sum += tree[rt].val;
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
    freopen("in","r",stdin);
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
