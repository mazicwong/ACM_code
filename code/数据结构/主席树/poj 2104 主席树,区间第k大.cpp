/*************************************************************************
	> File Name: poj2104.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月29日 星期二 03时26分24秒
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
 * 主席树裸题----求序列的区间第k大
 * http://www.cnblogs.com/Yuzao/p/7109577.html
 *
 * 给a[1..n]和m个询问
 * Q(l,r,k): 找[l,r]中排序后第k大的数
 *
 *
 * 开n个线段树,用主席树维护,n个分别表示[i,j]区间中[L,R]区间内数字个数,相当于前缀和
 * 区间询问[x,y]: 求root[y]-root[x-1]两颗主席树的sum之差
 *
 *
 * 具体怎么求K大:
 * 建立n棵线段树，第i棵线段树储存的是前i个值出现的次数。
 * 然后求[l,r]区间的数，就用第r棵线段树减去第l-1棵线段树就好了。
 * 然后进行二分操作，求出k大。
 *
 *
 * 原话:想法是对原序列的每一个前缀[1..i]建立出一颗线段树维护值域上
 * 每个数的出现次数，然后发现这样的树是可以减的，然后就没有然后了
 *
 */

/*
7 3
1 5 2 6 3 7 4
2 5 3    //[2,5]第3大:5
4 4 1    //[4,4]第1大:6
1 7 3    //[1,7]第3大:3
*/

const int N=100005,M=5005;
int gi()
{
    int str=0,f=1;char ch=getchar();
    while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9')str=(str<<1)+(str<<3)+ch-48,ch=getchar();
    return str*f;
}
struct node{
    int x,id;
}a[N];
int bel[N],root[N];
bool comp(const node &p,const node &q){return p.x<q.x;}
struct Tree{
    int ls,rs,sum;
}t[N*20];
int tot=0;
void insert(int &rt,int fa,int x,int l,int r)
{
    rt=++tot;
    t[rt].sum=t[fa].sum;
    t[rt].sum++;
    if(l==r)return ;
    int mid=(l+r)>>1;
    if(x<=mid)
    {
        insert(t[rt].ls,t[fa].ls,x,l,mid);
        t[rt].rs=t[fa].rs;
    }
    else
    {
        insert(t[rt].rs,t[fa].rs,x,mid+1,r);
        t[rt].ls=t[fa].ls;
    }
}
int query(int rt,int fa,int k,int l,int r)
{
    if(l==r)return a[l].x;
    int mid=(l+r)>>1,kt=t[t[rt].ls].sum-t[t[fa].ls].sum;
    if(k<=kt)return query(t[rt].ls,t[fa].ls,k,l,mid);
    else return query(t[rt].rs,t[fa].rs,k-kt,mid+1,r);
}
int main()
{
    freopen("in","r",stdin);
    int n=gi(),m=gi();
    for(int i=1;i<=n;i++)a[i].x=gi(),a[i].id=i;
    sort(a+1,a+n+1,comp);
    for(int i=1;i<=n;i++)bel[a[i].id]=i;
    for(int i=1;i<=n;i++)
        insert(root[i],root[i-1],bel[i],1,n);
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
        x=gi();y=gi();z=gi();
        printf("%d\n",query(root[y],root[x-1],z,1,n));
    }
}
