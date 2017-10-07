/*************************************************************************
	> File Name: hdu3533.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月03日 星期日 19时17分18秒
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

//预处理has[x][y][dep]: dep时刻,该点有无子弹

int mp[105][105];
void init()
{
    for (int i)
}

struct castle{
    int dir;
    int t; //period
    int v; //velocity
    int x,y;//coor
}G[105];


    int m,n;//100
    int k;//100  shoot
    int d;//1000   enegy

void dfs(int r,int l,int dep)
{
    if ()
    if (dep>d)
        return;
    

}
int main()
{
    freopen("in","r",stdin);

    while(scanf("%d",&m)!=EOF)
    {
        scanf("%d%d%d%*c",&n,&k,&d);
        char dir;
        for (int k=0;i<n;k++)
        {
            scanf("%c%d%d%d%d%*c",&G[i].dir,&G[i].t,&G[i].v,&G[i].x,&G[i].y);

        }
        int a;
    }
    
    return 0;
}
