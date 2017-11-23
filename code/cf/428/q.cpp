/*************************************************************************
	> File Name: q.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月14日 星期一 13时30分20秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

bool vis[10000][10000];
int to[4][2]={
    {1,0},{-1,0},{0,1},{0,-1}
};
//4 12 36 100 284 780 2164
int cnt[50];
void dfs(int i,int j,int len)
{
    if (len>=13) return;
    cnt[len]++;
    for (int k=0;k<4;k++)
    {
        int nx = i+to[k][0];
        int ny = j+to[k][1];
        if (!vis[nx][ny])
        {
            vis[nx][ny]=1;
            dfs(nx,ny,len+1);
            vis[nx][ny]=0;
        }
    }
    return;
}

int main()
{
    //freopen("in","r",stdin);
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
    vis[5000][5000]=1;
    dfs(5000,5000,0);
    for (int i=0;i<=13;i++)
    cout << i << ":  " << cnt[i] << endl;

    return 0;
}
