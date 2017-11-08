/*************************************************************************
	> File Name: hdu2795.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年11月01日 星期三 20时30分38秒
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
const int maxn = 2e5+5;

//选最上,最左的空格放东西
//查询,给一个公告的宽度,问放在第几行

int arr[maxn];
struct node{
    int l,r;
    int num;//该行剩余长度
}tr[maxn*3];

inline int L(int l){return l<<1;}
inline int R(int r){return (r<<1)+1;}
inline int MID(int l,int r) {return (l+r)>>1;}

int h,w,n;

void build(int l,int r,int rt){
    tr[rt].l=l; tr[rt].r=r; tr[rt].num=w;//一开始有w个长度是空
    if (l==r){
        return;
    }
    int mid = MID(l,r);
    build(l,mid,L(rt));
    build(mid+1,r,R(rt));
}
/*
void update(int l,int r,int rt,int val){
    if (l<=tr[rt].l && tr[rt].r<=r){
        return ;
    }
    int mid = MID(tr[rt].l, tr[rt].r);
    if (mid<l) update(l,r,R(rt),val);
    else if (mid>=r) update(l,r,L(rt),val);
    else{
        update(l,mid,L(rt),val);
        update(mid+1,r,R(rt),val);
    }
    pushup(rt);
}*/
int query(int x,int rt){
    if (tr[rt].l==tr[rt].r){
        tr[rt].num -= x;
        return tr[rt].l;
    }

    int sum1=0; int sum2=0;
    int mid = MID(tr[rt].l, tr[rt].r);
    if (mid<l) sum1=query(l,r,R(rt));
    else if (mid+1>=r) sum2=query(l,r,L(rt));
    else {
        query(l,mid,L(rt));
        query(mid+1,r,R(rt));
    }
}
int main()
{
    //freopen("in","r",stdin);
    while(scanf("%d%d%d",&h,&w,&n)!=EOF){
        build(1,h,1);
        int ww;
        for (int i=0;i<n;i++){
            scanf("%d",&ww); //输出放在第几行
            if (ww <= tr[1].r) printf("%d\b",query(ww,1));
            else printf("-1\n");
        }
    }
    return 0;
}
