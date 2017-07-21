/*************************************************************************
	> File Name: hdu3567.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月19日 星期三 21时57分07秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

struct node{
    int x,y;
    char mp[5][5];
    node(){}
    node(char *s)
    {
        int i,j;
        int xx=0,yy=0;
        for (int i=0;i<strlen(s);i++)
        {
            mp[xx][yy] = s[i];
            if(s[i]=='x')
            {
                x=xx;
                y=yy;
            }
            yy++;
            if(yy==3)
            {
                xx++;
                yy=0;
            }
        }
    }
}
const int maxn = 500000;
node s;
char str[20];
int num[20],hash[20];
bool vis[maxn];
int pre[10][maxn],ans[10][maxn];
int to[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
char way[10]="dlru";

int cantor(node a)
{
    int i,j,k;
    int cnt;
    int ans=0;
    int b[20];
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            b[3*i+j] = a.mp[i][j];
            cnt = 0;
            for (int k=3*i+j-1;k>=0;k--)
                if (b[k]>b[3*i+j])
                    cnt++;
            ans += hash[3*i+j]*cnt;
        }
    }
    return ans;
}

void bfs(int p)
{
    memset(pre[p],-1,sizeof(pre[p]));
    memset(vis,false,sizeof(vis));
    node a,next;
    queue<node> Q;
    Q.push(s);
    vis[cantor(s)]=true;
    while(!Q.empty())
    {

    }

}

int main()
{
    http://blog.csdn.net/libin56842/article/details/38019427



    return 0;
}
