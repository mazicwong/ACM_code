/*************************************************************************
	> File Name: poj1287.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月09日 星期六 09时51分41秒
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
const int maxn = 50+5;//point
const int maxm = 1500+5;//edge
/*
 * point: 1..n
 * edge: 0..m-1
 */
int n,m;//点,边

//建图
struct edge{
    int x,y;
    int d;
}E[maxm];
int cmp(edge a1,edge a2){return a1.d<a2.d;}

//并查集
int fa[maxn];
void init() {for (int i=1;i<=n;i++) fa[i]=i;}
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
void unite(int x,int y)
{
    int nx=find(x),ny=find(y);
    if (nx!=ny) fa[nx]=ny;
}

//kruskal
int kruskal(int num)
{
    init();
    sort(E,E+num,cmp);
    int ans=0,cnt=0;
    for (int i=0;i<num;i++)
    {
        if (find(E[i].x)!=find(E[i].y))
        {
            ans += E[i].d;
            unite(E[i].x,E[i].y);
            cnt++;
        }
        if (n-1==cnt)
            return ans;
    }
}

int main()
{
    freopen("in","r",stdin);
    while(scanf("%d",&n) && n)
    {
        scanf("%d",&m);
        for (int i=0;i<m;i++)
            scanf("%d%d%d",&E[i].x,&E[i].y,&E[i].d);
        printf("%d\n",kruskal(m));
    }
    return 0;
}
