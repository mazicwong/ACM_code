#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
/*
 * 主席树模板
 *
 * Q k l r : 查询数列在第k个版本,区间[l,r]上的最大值
 * M k p v : 数列在第k个版本的第p个数修改为v,产生下一个版本
 * 最开始的数列作为第一个版本,每次修改一个点,只用修改一条链上的logn个节点,
 * 则m次修改操作,有root[1..m]个根节点,查询第k次则从第k个版本的树根开始,像查询普通线段树一样就好了
 */

/*
4 5 
1 2 3 4   //版本1
0 1 1 4   //查询版本1的[1,4]最大值4
1 1 3 5   //修改产生版本2: 1 2 5 4
0 2 1 3   //查询版本2的[1,3]最大值5
0 2 4 4   //查询版本2的[4,4]最大值4
0 1 2 4   //查询版本1的[2,4]最大值4
*/

//http://www.cnblogs.com/Yuzao/p/7107439.html

inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }
const int maxn = 1e4+5;//点数
const int maxm = 1e5+5;//修改版本数
const int INF = 0x3f3f3f3f;

struct node{
    int ls,rs;
    int val;//区间最值
}t[maxm*10];

int gi()
{
    int str=0,f=1;char ch=getchar();
    while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9')str=(str<<1)+(str<<3)+ch-48,ch=getchar();
        return str*f;
}
int arr[maxn];  //maxn个点
int root[maxm]; //maxm个版本的树根
int tot=0;      //总节点数
int num=1;      //版本数

//建立第一个树根root[1],最开始的版本
void build(int &rt,int l,int r)
{
    rt=++tot;
    if(l==r)//叶子
    {
        t[rt].val=arr[l];
        return;
    }

    //递归
    int mid = MID(l,r);
    build(t[rt].ls,l,mid);
    build(t[rt].rs,mid+1,r);
    t[rt].val = max(t[t[rt].ls].val, t[t[rt].rs].val);
}

//update
//new_root,now_root,left,right,idx,val
void update(int &rt,int fa,int l,int r,int p,int to)
{
    rt=++tot;
    if(l==r)
    {
        t[rt].val=to;
        return;
    }

    int mid=MID(l,r);
    if(p<=mid) //在左子树
    {
        update(t[rt].ls,t[fa].ls,l,mid,p,to);
        t[rt].rs=t[fa].rs;
    }
    else       //在右子树
    {
        update(t[rt].rs,t[fa].rs,mid+1,r,p,to);
        t[rt].ls=t[fa].ls;
    }
    t[rt].val=max(t[t[rt].ls].val,t[t[rt].rs].val);
}


//查询最值(节点的value最大)
//root,left,right,cha_left,cha_right
int query(int rt,int l,int r,int sa,int se)
{
    if(l>se || r<sa)return -INF;
    if(sa<=l && r<=se)return t[rt].val;
    int mid = MID(l,r);
    return max(query(t[rt].ls,l,mid,sa,se),query(t[rt].rs,mid+1,r,sa,se));
}

int main()
{
    freopen("in","r",stdin);
    int n=gi(),m=gi();
    for (int i=1;i<=n;i++) arr[i]=gi();
    build(root[1],1,n);//root,left,right
    int flag,k,l,r;
    for (int i=0;i<m;i++)
    {
        flag=gi();k=gi();l=gi();r=gi();
        if (flag==0) //query 第k个版本的[l,r]的最值
            printf("%d\n",query(root[k],1,n,l,r));//root,left,right,cha_left,cha_right
        else //update 第k个版本的第l个数改为r,变成第num+1个版本
            update(root[++num],root[k],1,n,l,r);//root,father,left,right,idx,val
    }
    return 0;
}
