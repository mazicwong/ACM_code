/*************************************************************************
	> File Name: poj3660.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月22日 星期六 10时15分43秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 100+5;
int n,m;
int win[maxn][maxn];
void floyd()
{
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (win[i][k] && win[k][j])
                    win[i][j]=1;
}
int main()
{
    freopen("in","r",stdin);
    scanf("%d%d",&n,&m);
    int a,b;
    memset(win,0,sizeof(win));
    for (int i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        win[a][b]=1;
    }
    floyd();
    int ans = 0;
    int j;
    for (int i=1;i<=n;i++) //判闭包
    {
        for (j=1;j<=n;j++)
        {
            if (i!=j)
            {
                if(win[i][j]==0 && win[j][i]==0)
                    break;
            }
        }
        if (j==n+1) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
