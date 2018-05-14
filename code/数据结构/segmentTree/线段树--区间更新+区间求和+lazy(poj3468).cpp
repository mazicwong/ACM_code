#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

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
const int maxn = 1e5 + 5;

struct node{
    int l,r;
    ll Sum;   //节点属性值,这里是区间和
    ll lazy;  //该节点对应所有子节点应该加上的值,才不用一直更新到叶子
}tr[maxn<<2];     //tr[1..2^n-1]
int arr[maxn];      //存放初始节点arr[1..n]


//"创建区间"和"更新区间"最后的递归回溯时向上更新value
//查询就不用了,
void PushUp(int rt)
{
    tr[rt].Sum = tr[rt<<1].Sum + tr[rt<<1+1].Sum;
}

//"查询"和"更新"时先PushDown一下处理子区间的lazy和value
void PushDown(int rt)
{
    if (tr[rt].lazy)
    {
        tr[rt<<1].lazy += tr[rt].lazy;
        tr[rt<<1|1].lazy += tr[rt].lazy;
        tr[rt<<1].Sum += (tr[rt<<1].r-tr[rt<<1].l+1)*tr[rt].lazy;
        tr[rt<<1|1].Sum += (tr[rt<<1|1].r-tr[rt<<1|1].l+1)*tr[rt].lazy;

        tr[rt].lazy = 0;
    }
}

void build(int rt,int l, int r)
{
    tr[rt].l=l; tr[rt].r=r;
    tr[rt].lazy=0;
    if (l==r) //找到叶子,赋值
    { 
        tr[rt].Sum = arr[l];
        return;
    }
    else
    {
        int mid = (l+r)>>1;
        build(rt<<1,l,mid);
        build(rt<<1|1,mid+1,r);
        PushUp(rt);
    }
}

//区间更新(每个点加一个值)
void update(int rt,int ql, int qr, int val)//更新范围[l,r],当前所在的根rt
{
    if(ql<=tr[rt].l && tr[rt].r<=qr)//单点更新的话,这里就用等于
    {
        tr[rt].lazy += val;
        tr[rt].Sum += (tr[rt].r-tr[rt].l+1)*val;
        return;
    }

    PushDown(rt);
    if(tr[rt].l == tr[rt].r) return;

    int mid = (tr[rt].l+tr[rt].r)>>1;
    if(mid<ql) update(rt<<1|1,ql,qr,val);      //在右子树中
    else if(mid>=qr) update(rt<<1,ql,qr,val);  //在左子树中
    else                                       //在左右子树中
    {
        update(rt<<1,ql,mid,val);
        update(rt<<1|1,mid+1,qr,val);
    }
    PushUp(rt);
}


//区间查询(和)
ll sum = 0;         //查询到的和
void query(int rt,int ql, int qr)//查找的范围[l,r],当前所在根rt
{
    if (ql<=tr[rt].l && tr[rt].r<=qr)
    {
        sum += tr[rt].Sum;
        return;
    }

    PushDown(rt);
    if (tr[rt].l == tr[rt].r) return;

    int mid = (tr[rt].l+tr[rt].r)>>1;
    if (mid<ql) query(rt<<1|1,ql,qr);
    else if (mid>=qr) query(rt<<1,ql,qr);
    else
    {
        query(rt<<1,ql,mid);
        query(rt<<1|1,mid+1,qr);
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
        build(1,1,n);//left,right,rt

        while (q--)
        {
            getchar();
            char qq = getchar();
            if ('C' == qq) //update
            {
                int idxl,idxr;
                ll val;
                scanf("%d%d%lld",&idxl,&idxr,&val);
                update(1,idxl,idxr,val);//left,right,value,rt
            }
            else //sum
            {
                int l, r;
                scanf("%d%d",&l,&r);
                sum = 0;
                query(1,l,r);//left,right,rt
                printf("%lld\n",sum);
            }
        }
    }
    return 0;
}
