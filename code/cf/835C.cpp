/*************************************************************************
	> File Name: 3.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月31日 星期一 23时01分34秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100+5;
int t,x1,y1,x2,y2;

int main()
{
    int mp[11][105][105];
    freopen("in","r",stdin);
    int n,q,c;
    scanf("%d%d%d",&n,&q,&c);
    int xx,yy,ss;
    memset(mp,0,sizeof(mp));
    for (int i=0;i<n;i++)
    {
        scanf("%d%d%d",&xx,&yy,&ss);
        for (int k=0;k<=10;k++)
        {
            mp[k][xx][yy] += ((ss+k)%(c+1));
        }
    }
    
    for (int k=0;k<=10;k++)
    {
        for (int i=1;i<=100;i++)
        {
            for (int j=1;j<=100;j++)
            {
                mp[k][i][j] = mp[k][i][j] - mp[k][i-1][j-1] + mp[k][i][j-1] + mp[k][i-1][j];
            }
        }
    }

    while(q--)
    {
        int ans=0;
        scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
        t%=(c+1);
        printf("%d\n",mp[t][x2][y2]-mp[t][x2][y1-1]-mp[t][x1-1][y2]+mp[t][x1-1][y1-1]);
    }
    return 0;
}
