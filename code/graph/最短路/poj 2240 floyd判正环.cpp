/*************************************************************************
	> File Name: poj2240.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月22日 星期六 19时46分45秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <map>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 30+5;
double dist[maxn][maxn];
int cnt[maxn];
bool vis[maxn];

map<string,int>mp;
int n,m;

void floyd()
{
    for (int k=1;k<=n;k++)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                dist[i][j]=max(dist[i][j], dist[i][k]*dist[k][j]);
            }
        }
    }
}

int main()
{
    freopen("in","r",stdin);
    string str;
    int cas=1;
    while(scanf("%d",&n) && n)
    {
        mp.clear();
        for(int i=1;i<=n;i++)
        {
            cin >> str;
            mp[str]=i;
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if(i==j) dist[i][j]=1;
                else dist[i][j]=0;
            }
        }
        scanf("%d",&m);
        string str1,str2;
        double tmp;
        for(int i=0;i<m;i++)
        {
            cin >> str1 >> tmp >> str2;
            int a = mp[str1];
            int b = mp[str2];
            dist[a][b]=tmp;
        }
        bool flag = 0;
        floyd();
        for (int i=1;i<=n;i++)
        {
            if (dist[i][i]>1)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            printf("Case %d: Yes\n",cas++);
        else
            printf("Case %d: No\n",cas++);
    }
    return 0;
}
