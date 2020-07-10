#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;
typedef long long ll;

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
const int maxn =8000+5;

inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }

int tree[maxn<<2]; //颜色
int li[maxn<<2],ri[maxn<<2];
int ans[maxn];

//"查询"和"更新"时先PushDown一下处理子区间的lazy和value
void PushDown(int rt)
{
    tree[L(rt)] = tree[R(rt)] = tree[rt];
    tree[rt] = -1;
}


void build(int l,int r,int rt)
{
    li[rt]=l;
    ri[rt]=r;
    tree[rt]=-1;

    if (l==r) return;
    
    int mid = MID(l,r);
    build(l,mid,L(rt));
    build(mid+1,r,R(rt));
}

//更新区间(每个点加一个值)
void update(int l, int r, int val, int rt)//更新范围[l,r],当前所在的根rt
{//更新范围[l,r],颜色val,当前根rt,当前范围[x,y]
    if (l<=li[rt] && ri[rt]<=r)//单点更新的话,这里就用等于
    {
        tree[rt] = val;
        return;
    }

    if (tree[rt] != -1)
        PushDown(rt);

    //分治
    int mid = MID(li[rt],ri[rt]);
    if (l<=mid) update(l,r,val,L(rt));  //在左子树中
    if (mid<r) update(l,r,val,R(rt));        //在右子树中
}

//查询区间(和)
int query(int rt,int x)//查找的范围[x,x],当前所在根rt
{
    if (li[rt]==x && x==ri[rt])
        return tree[rt];
    
    if (tree[rt]!=-1) PushDown(rt);

    //分治
    int mid = MID(li[rt],ri[rt]);
    if (x<=mid)
        return query(L(rt),x);
    else
        query(R(rt),x);
}

int main()
{
    freopen("in","r",stdin);
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        build(0,8000,1);
        for (int i=0;i<n;i++)
        {
            int l,r,val;
            scanf("%d%d%d",&l,&r,&val);
            update(l,r-1,val,1);
        }

        int pre = -1;
        memset(ans,0,sizeof(ans));
        for (int i=0;i<=8000;i++)
        {
            int tt = query(1,i);//root,查找
            if (tt!=pre && tt!=-1)
                ans[tt]++;
            pre = tt;
        }
    
        for (int i=0;i<=8000;i++)
        {
            if (ans[i])
                printf("%d %d\n",i,ans[i]);
        }
        puts("");
    }
    return 0;
}
