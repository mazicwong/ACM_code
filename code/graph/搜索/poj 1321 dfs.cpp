/*************************************************************************
	> File Name: poj 1321.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月16日 星期日 23时46分42秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn=10;
char mp[maxn][maxn];//棋盘
bool visit[maxn];//一列是否放过棋子
int n,k;
int ans;//方案数

//k<=n，有两种情况，dfs中分开讨论，记得避免越界
void dfs(int row,int cnt) //逐行深搜，row是当前行，cnt是已经填充的棋子数
{
    if (k==cnt) //判等时保持变化量写右边 :) 习惯
    {
        ans++;
        return;
    }

    if (row>n)  //因为有dfs(row+1,cnt),这里要避免搜索越界，很多搜索都会有
        return;

    for (int j=1;j<=n;j++)
    {//对一行进行深搜
        if (visit[j]==0 && mp[row][j]=='#')
        {
            visit[j]=true; //假设在这里放下棋子，然后再遍历下一行
            dfs(row+1,cnt+1); //
            visit[j]=false; //回溯后，上面的状态已经记录了，还原标记
        }
    }
    dfs(row+1,cnt); //这里是难点，上面已经把放下棋子情况搜了一遍，并且已经回溯了
                    //这里再搜一遍不放棋子的，不要漏掉这种
}

int main()
{
    freopen("in.txt","r",stdin);
    while(cin>>n>>k && n!=-1)
    {
        ans=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
                cin>>mp[i][j];
        }
        memset(visit,0,sizeof(visit));
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
