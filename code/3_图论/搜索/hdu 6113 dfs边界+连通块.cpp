/*************************************************************************
	> File Name: 6.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月12日 星期六 15时36分46秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n,m;
const int maxn = 100+5;
/*
 * 0: 一个1组成的连通块,1内有一个0组成的连通块,(0不能在边界)
 * 1: 一个1组成的连通块,1中不能有0
 * -1: 1的连通块数为0或者>=2,或者1的内部有0
 * 判1内的0不在边界,先把边界的所有0搜一遍,剩下1和1里面的0,统计1和0堆数,确定答案
 */


char mp[maxn][maxn];
bool vis[maxn][maxn];
int to[4][2]={
    {0,1},{1,0},{0,-1},{-1,0}
};


void dfs(int i,int j,char s)
{
    int nx,ny;
    vis[i][j]=1;
    for (int k=0;k<4;k++)
    {
        nx = i+to[k][0];
        ny = j+to[k][1];
        if (nx>=0 && nx<n && ny>=0 && ny<m && mp[nx][ny]==s && !vis[nx][ny])
            dfs(nx,ny,s);
    }
}

void dfs1(int i,int j)
{
    int nx,ny;
    vis[i][j]=1;
    for (int k=0;k<4;k++)
    {
        nx = i+to[k][0];
        ny = j+to[k][1];
        if (nx>=0 && nx<n && ny>=0 && ny<m && mp[nx][ny]=='1' && !vis[nx][ny])
            dfs1(nx,ny);
    }
}


int dfs2(int i,int j)
{
    int nx,ny;
    vis[i][j]=1;
    for (int k=0;k<4;k++)
    {
        nx = i+to[k][0];
        ny = j+to[k][1];
        if (nx>=0 && ny>=0 && nx<n && ny<m && mp[nx][ny]=='0' && !vis[nx][ny])
            if (dfs2(nx,ny)==0)
                return 0;
        if (nx<0 || ny<0 || nx>=n || ny>=m)
            return 0;
    }
    return 1;
}

int main()
{
    freopen("in6","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        for (int i=0;i<n;i++)
            scanf("%s",mp[i]);
        
        //处理4个边界的0
        for (int i=0;i<m;i++)
        {
            if (mp[0][i]=='0')
                dfs(0,i,'0');
            if (mp[n-1][i]=='0')
                dfs(n-1,i,'0');
        }
        for(int i=0;i<n;i++)
        {
            if (mp[i][0]=='0')
                dfs(i,0,'0');
            if (mp[i][m-1]=='0')
                dfs(i,m-1,'0');
        }
        
        //搜连通块
        int cnt0=0,cnt1=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (!vis[i][j])
                {
                    if(mp[i][j]=='0')
                        cnt0++;
                    else cnt1++;
                    dfs(i,j,mp[i][j]);
                }
            }
        }
        
        if (cnt1==1 && cnt0==0) puts("1");
        else if (cnt1==1 && cnt0==1) puts("0");
        else puts("-1");


        /*int ans=0,cnt=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (!vis[i][j])
                {
                    if (mp[i][j]=='1')//1
                    {
                        ans++;
                        dfs1(i,j);
                    }
                    else//0
                    {
                        if (dfs2(i,j))
                            cnt++;
                    }
                }
            }
        }
        if(ans==1) //1的连通块数
        {
            if(cnt==1) puts("0");
            else if (cnt==0) puts("1");
            else puts("-1");
        }
        else puts("-1");
        */
    }
    return 0;
}
