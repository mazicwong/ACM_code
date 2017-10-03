/*************************************************************************
	> File Name: hdu1540.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月03日 星期二 15时05分31秒
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

/* hdu 1540 线段树,区间合并,最大连续区间
 * http://blog.csdn.net/jinglinxiao/article/details/54575344
 * 地道战,一开始全部相连,   n个城市, m个操作
 *
 * D x  : 第x个城市被摧毁
 * Q x  : 问x可以连接到的城市个数(包括自己)
 * R    : 最后被摧毁的重建了
 * 
 *
 * 思路: 线段树区间合并问题
 * 每个点中,维护3个信息,
 * ls记录该区间左端点最大连续个数,rs记录右端点开始最大连续个数,
 * ms表示该区间最大连续个数
 *
 * 规律:
 * 双亲ms = max(左ms, 右ms, 左rs+右ls);
 *
 */

inline int L(int l){return l<<1;}
inline int R(int r){return (r<<1)+1;}
inline int MID(int l,int r){return (l+r)>>1;}

const int maxn = 50000+5;
int n,m;
int x;
stack<int> S;

struct Node{
    int l,r;
    int ls,rs,ms;
}tr[maxn<<2];

//建立好l,r,ls,rs,ms; 自上向下走一遍就能确定的
void build(int l,int r,int rt)
{
    tr[rt].l=l; tr[rt].r=r;
    tr[rt].ls=tr[rt].rs=tr[rt].ms=r-l+1;
    if (l==r)
        return;
    int mid=MID(l,r);
    build(l, mid, L(rt));
    build(mid+1, r, R(rt));
}

//区间更新
void update(int l,int r,int flag,int rt,int x)
{
    if (l==r)
    {
        if (flag) tr[rt].ls=tr[rt].rs=tr[rt].ms=1; //修复
        else tr[rt].ls=tr[rt].rs=tr[rt].ms=0;   //破坏
        return ;
    }
    //二分区间
    int mid = MID(l,r);
    if (x<=mid)//到左儿子找该区间
        update(l,mid,flag,L(rt),x);
    else 
        update(mid+1,r,flag,R(rt),x);

    //回溯更新所有祖先节点属性
    tr[rt].ls = tr[L(rt)].ls; //ls等于左儿子ls
    tr[rt].rs = tr[R(rt)].rs; //rs等于右儿子rs
    tr[rt].ms = max(tr[L(rt)].ms+tr[R(rt)].ms, max(tr[L(rt)].ms, tr[R(rt)].ms));//ms等于左ms,右ms,
    if (tr[L(rt)].ls==mid-l+1) tr[rt].ls+=tr[R(rt)].ls;
    if (tr[R(rt)].rs==r-mid) tr[rt].rs+=tr[L(rt)].rs;
}

int query(int l,int r,int rt,int x)
{
    if (tr[rt].ms==r-l+1 || tr[rt].ms==0 || l==r)
        return tr[rt].ms;
    int mid = MID(l,r);
    if (x<=mid)
    {
        if (x>=mid-tr[L(rt)].rs+1)
            return query(l,mid,L(rt),x)+query(mid+1,r,R(rt),mid+1);
        else return query(l,mid,L(rt),x);
    }
    else
    {
        if (x<=mid+tr[R(rt)].ls)
            return query(l,mid,L(rt),mid)+query(mid+1,r,R(rt),x);
        else return query(mid+1,r,R(rt),x);
    }
}

int main()
{
    freopen("in","r",stdin);
    while(scanf("%d%d%*c",&n,&m)!=EOF)
    {
        build(1,n,1);
        while(m--)
        {
            char ch;
            scanf("%c%*c",&ch);
            if (ch=='R')           //重建
            {
                x = S.top();
                S.pop();
                update(1,n,1,1,x); //1表示重建
            }
            else
            {
                scanf("%d%*c",&x);
                if (ch=='Q')      //查询
                {
                    cout << query(1,n,1,x) << endl;
                }
                else if (ch=='D') //破坏
                {
                    S.push(x);
                    update(1,n,0,1,x);//0破坏
                }
            }
        }
    }
    return 0;
}
