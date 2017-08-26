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

inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }
typedef struct {
    int left, right;
    ll value; //节点对应区间和
    ll lazy;  //该节点对应所有子节点应该加上的值,才不用一直更新到叶子
}node;
node tree[maxn<<2]; //tree[1..2^n-1]
int arr[maxn];      //存放初始节点arr[1..n]
int sum = 0;         //查询到的和


//"创建区间"和"更新区间"最后的递归回溯时向上更新value
void PushUp(int rt)
{
    tree[rt].value = tree[L(rt)].value + tree[R(rt)].value;
}


//"查询"和"更新"时先PushDown一下处理子区间的lazy和value
void PushDown(int rt)
{
    if (tree[rt].lazy)
    {
        tree[L(rt)].lazy = tree[rt].lazy;
        tree[R(rt)].lazy = tree[rt].lazy;
        tree[L(rt)].value = (tree[L(rt)].right-tree[L(rt)].left+1)*tree[rt].lazy;
        tree[R(rt)].value = (tree[R(rt)].right-tree[R(rt)].left+1)*tree[rt].lazy;
        tree[rt].lazy = 0;
    }
}

void build(int l, int r, int rt)
{
    tree[rt].left = l;
    tree[rt].right = r;
    tree[rt].lazy = 0;
    if (l==r) //找到叶子,赋值
    { 
        tree[rt].value = 1;
        return;
    }


    //分治
    int mid = MID(l,r);
    build(l,mid,L(rt));
    build(mid+1,r,R(rt));

    //回溯维护value(区间和)
    PushUp(rt);
}

//更新区间(每个点加一个值)
void update(int l, int r, int val, int rt)//更新范围[l,r],当前所在的根rt
{
    //if (l<=L(rt) && R(rt)<=r) ???
    if (l<=tree[rt].left && tree[rt].right<=r)//单点更新的话,这里就用等于
    {
        //这个节点在更新的区间里面,直接算完lazy和value然后退出
        tree[rt].lazy = val;
        tree[rt].value = (tree[rt].right-tree[rt].left+1)*val;
        return;
    }

    PushDown(rt);
    if (tree[rt].left == tree[rt].right) return;


    //分治
    int mid = MID(tree[rt].left, tree[rt].right);
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
    if (l<=tree[rt].left && tree[rt].right<=r)
    {
        sum += tree[rt].value;
        return;
    }

    PushDown(rt);
    if (tree[rt].left == tree[rt].right) return;


    //分治
    int mid = MID(tree[rt].left, tree[rt].right);
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
    int t;cin>>t;
    for (int cas=1;cas<=t;cas++)
    {
        int n, q;
        scanf("%d%d",&n,&q);
        build(1,n,1);//left,right,rt
        while (q--)
        {
            int idxl,idxr;
            int val;
            scanf("%d%d%d",&idxl,&idxr,&val);
            update(idxl,idxr,val,1);//left,right,value,rt
        }
        sum = 0;
        query(1,n,1);//left,right,rt
		printf("Case %d: The total value of the hook is %d.\n",cas,sum);
    }

    return 0;
}
