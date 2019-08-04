/*************************************************************************
	> File Name: hdu1556.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年11月01日 星期三 18时54分16秒
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
const int maxn = 1e5+5;
//也可以利用树状数组,很巧妙的方法

//[1,n]个气球,对区间涂色,求每个气球涂了多少次
//线段树所做的优化,就是每次更新只更新到lazy,在最终查询的时候再一次pushdown;

//lazy思想
int arr[maxn];
struct node{
    int l,r;
    int num;
}tr[maxn*3];
inline int L(int l){return l<<1;}
inline int R(int r){return (r<<1)+1;}
inline int MID(int l,int r){return (l+r)>>1;}

void build(int l,int r,int rt){
    tr[rt].l=l; tr[rt].r=r; tr[rt].num=0;
    if (l==r){
        return;
    }
    int mid = MID(l,r);
    build(l,mid,L(rt));
    build(mid+1,r,R(rt));
}
void update(int l,int r,int rt){
    if (l<=tr[rt].l && tr[rt].r<=r){
        tr[rt].num +=1;
        return ;
    }

    if (tr[rt].l == tr[rt].r) return;
    int mid = MID(tr[rt].l,tr[rt].r);
    if (mid<l) update(l,r,R(rt));
    else if (mid>=r) update(l,r,L(rt));
    else{
        update(l,mid,L(rt));
        update(mid+1,r,R(rt));
    }
}
//只是pushdown所有lazy
void query(int rt){ 
    if (tr[rt].num)
        for (int i=tr[rt].l; i<=tr[rt].r; i++)
            arr[i] += tr[rt].num;
    if (tr[rt].l == tr[rt].r) return;
    query(L(rt));
    query(R(rt));
}

int main()
{
    //freopen("in","r",stdin);
    int n; //n点,n次更新,1次询问(输出所有点)
    while(scanf("%d",&n) && n){
        int a,b;
        build(1,n,1);
        memset(arr,0,sizeof(arr));
        for (int i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            update(a,b,1);
        }
        query(1);
        for (int i=1;i<n;i++)
            printf("%d ",arr[i]);
        printf("%d\n",arr[n]);
    }
    return 0;
}
