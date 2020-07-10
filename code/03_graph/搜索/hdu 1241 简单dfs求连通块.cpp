/*************************************************************************
	> File Name: hdu1241.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月19日 星期三 15时08分37秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 100+5;
int to[8][2]={
    {-1,-1},{-1,0},{-1,1},
    {1,1},{1,0},{1,-1},
    {0,1},{0,-1}
};
int n,m;
char mp[maxn][maxn];

void dfs(int i,int j)
{
    if (mp[i][j]=='*' || i<0 || i>=n || j<0 || j>=m)
        return; //回溯
    mp[i][j]='*';

    for (int tt=0;tt<8;tt++)
        dfs(i+to[tt][0],j+to[tt][1]);

}
int main()
{
    freopen("in","r",stdin);
    while(cin>>n>>m && n && m)
    {
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> mp[i][j];
        
        //对所有点dfs一次
        int ans = 0;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (mp[i][j]=='@')
                {
                    dfs(i,j);
                    ans++;
                }
        cout << ans << endl;
    }

    return 0;
}
