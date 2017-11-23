/*************************************************************************
	> File Name: d.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月19日 星期六 00时24分56秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 3e5+5;
int d[maxn];

struct node{
    int to;
    int next;
}e[maxn];

vector<node> V[maxn];
int main()
{
    freopen("in","r",stdin);
    int n,m; cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&d[i]);
    }
    for (int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
    }
    
    return 0;
}
