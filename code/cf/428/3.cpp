/*************************************************************************
	> File Name: 2.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月12日 星期六 22时45分01秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 求平均期望
 * n点,n-1边,每条边权值都为1,马从1点开始走,不走重复,直到不能再走时停止,问路程的期望值
 * 
 * 给一棵树,n个点,马
 *
 * 注意:不能用建树,然后搜叶子节点的方法,
 */
const int maxn = 1e5+5;
vector<int>G[maxn];
double ans;

void dfs(int u,int fa,int len,double x)
{
    int m = G[u].size();
    double y = m;
    if(fa!=-1)
        y--;
    int flag=true;
    for(int i=0;i<m;i++)
    {
        int vv = G[u][i];
        if(vv==fa)
            continue;
        flag=false;
        dfs(vv,u,len+1,x/y);
    }
    if(flag)
        ans+=x*len;
}

int main()
{
    freopen("in3","r",stdin);
    int n;
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ans = 0;
    dfs(1,-1,0,1.0);
    printf("%.15lf\n",ans);
    return 0;
}
