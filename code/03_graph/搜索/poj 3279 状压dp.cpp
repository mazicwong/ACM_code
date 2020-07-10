/*************************************************************************
	> File Name: poj3279.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月17日 星期一 20时02分42秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 15+3;
const int INF = 0x3f3f3f3f;
int n,m;
int ans;
int mp[maxn][maxn];
int state[maxn][maxn];
int tmp[maxn][maxn];
int res[maxn][maxn];
const int to[5][2]={
    {-1,0},
    {1,0},
    {0,-1},
    {0,1},
    {0,0}
};

void flip(int x,int y)
{
    tmp[x][y]=1;
    int nx,ny;
    for (int i=0;i<5;i++)
    {//5个方向都要更新状态
        nx = x+to[i][0];
        ny = y+to[i][1];
        state[nx][ny] = !state[nx][ny];
    }
}

bool isEmpty(int n)
{
    for (int j=1;j<=m;j++)
    {
        if (state[n][j])
            return false;
    }
    return true;
}

void solve(int st) //st是state状态
{
    memcpy(state,mp,sizeof(mp));
    memset(tmp,0,sizeof(tmp));
    int cnt=0;
    //如果理解不了的话，可以把这里传进来的状态看成是第1行在上面那行的状态
    
    //第一行
    for (int j=0;j<m;j++)
    {
        if ((st>>j) & 1) //取出状态
        {
            flip(1,j+1);
            cnt++;
        }
    }
    //第二行到最后
    for (int i=2;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (state[i-1][j] == 1)
            {
                flip(i,j);
                cnt++;
            }
        }
    }
    if (isEmpty(n) && cnt<ans)
    {
        ans = cnt;
        memcpy(res,tmp,sizeof(tmp));
    }
}


int main()
{
    freopen("in","r",stdin);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin >> mp[i][j];
    ans = INF;
    int col = 1<<m;
    for (int st=0;st<col;st++) //2^m种情况
        solve(st);
    if (ans == INF)
        puts("IMPOSSIBLE");
    else
    {
        for (int i=1;i<=n;i++)
        {
            //printf("%d",res[i][1]);
            for (int j=1;j<=m;j++)
                printf(j!=m?"%d ":"%d\n",res[i][j]);
                //printf(" %d",res[i][j]);
            //puts("");
        }
    }
    return 0;
}
