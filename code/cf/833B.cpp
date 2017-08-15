/*************************************************************************
	> File Name: d.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月31日 星期一 00时47分39秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 35000+5;
/*
 * 线段树每个位置x记录的是dp[i-1][x-1]+val[x]
 * val[x]表示从位置x到当前枚举的位置j这段中不同种类的数的个数
 */

int dp[55][maxn]; //dp[i][j]: 前j个分成i部分的最大和
int ls[maxn];
int last[maxn];

int n,k;
int arr[maxn];

inline int L(int l){return l<<1;}
inline int R(int r){return (r<<1)+1;}
inline int MID(int l,int r){return (l+r)>>1;}
typedef struct{
    int mx; //dp[i-1][x-1]+val[x] (前x-1分成i-1段,从x到j是一段)
    int lazy;
}node;
node t[maxn*5];

void pushup(int root)
{
    t[root].mx=max(t[L(root)].mx, t[R(root)].mx);
}

void pushdown(int root,int l,int r)
{
    if(l==r) return;

    if (t[root].lazy)
    {
        int tmp = t[root].lazy;
        t[L(root)].mx += tmp;
        t[R(root)].mx += tmp;
        t[L(root)].lazy += tmp;
        t[R(root)].lazy += tmp;
        t[root].lazy=0;
    }
}

void build(int d,int l,int r,int now)
{
    t[d].lazy=0;
    if (l==r)
    {
        t[d].mx=dp[now][l-1];//建树时初值用dp[i-1][x],后面insert再加上val[x]
        return;
    }
    int mid=MID(l,r);
    build(L(d),l,mid,now);
    build(R(d),mid+1,r,now);
    pushup(d);
}

void insert(int d,int l,int r,int x,int y,int z)
{
    if (x>y) return;
    pushdown(d,l,r);
    if (l==x && r==y)
    {
        t[d].mx+=z; //更新时加上val[x]  (x到j距离)
        t[d].lazy+=z;
        return;
    }
    int mid=MID(l,r);
    insert(L(d),l,mid,x,min(y,mid),z);
    insert(R(d),mid+1,r,max(x,mid+1),y,z);
    pushup(d);
}

int query(int d,int l,int r,int x,int y)
{//查询前缀最大
    if(x>y) return 0;
    pushdown(d,l,r);
    if(l==x && r==y) return t[d].mx;
    int mid=MID(l,r);
    return max(query(L(d),l,mid,x,min(y,mid)), query(R(d),mid+1,r,max(x,mid+1),y));
}

int main()
{
    freopen("in","r",stdin);
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        ls[i]=last[arr[i]];//ls: 上一次出现arr[i]的位置
        last[arr[i]]=i;//last: arr[i]最后一次出现的地方
    }
    for (int i=1;i<=k;i++)
    {
        build(1,1,n,i-1);
        for (int j=1;j<=n;j++) //前j个数分成i段
        {
            insert(1,1,n,ls[j]+1,j,1);//更新ls[j]+1到j的mx
            dp[i][j]=query(1,1,n,1,j);//查询1~j的前缀和的mx
        }
    }
    printf("%d",dp[k][n]);
    return 0;
}
