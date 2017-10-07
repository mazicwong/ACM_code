/*************************************************************************
	> File Name: hdu1078.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月04日 星期三 10时54分15秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;
/*
 * n*n矩阵,吃奶酪
 * 走四个方向,每次最多走k步
 * 且要求走的地方的奶酪是递增的,问最多能迟到多少奶酪
 * 
 * 明显,直接DP,虽然子问题重复,但是不满足无后效性,因为每次移动的方向不是固定的,而且四个方向,所以用记忆花搜搜
 * 这题要DP的话,先将所有点按权值排列,这样找到一个方向后,可以进行DP
 */

//DP写法   
const int maxn = 100+5;
int mp[maxn][maxn],dp[maxn][maxn];
int n,k;
struct Node{
    int i,j;
    int val;
    bool operator <(const Node& mm) const{
        return val<mm.val;
    }
}node[maxn*maxn];
int main()
{
    freopen("in","r",stdin);
    while(scanf("%d%d",&n,&k) && n!=-1)
    {
        int tot=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                scanf("%d",&mp[i][j]);
                if (i==0 && j==0)
                    continue;
                node[tot].i=i; node[tot].j=j; node[tot++].val=mp[i][j];
            }
        }
        sort(node,node+tot);
        memset(dp,-1,sizeof(dp));
        dp[0][0]=mp[0][0];
        int ans = dp[0][0];
        for (int tt=0;tt<tot;tt++) //找到范围内比他小的点
        {
            int i=node[tt].i, j=node[tt].j;
            for (int rr=max(0,i-k);rr<=min(n-1,i+k);rr++)
            {
                if (mp[rr][j]>=mp[i][j]) continue;
                if (dp[rr][j]==-1) continue;
                dp[i][j] = max(dp[i][j], dp[rr][j]+mp[i][j]);
            }
            for (int cc=max(0,j-k);cc<=min(n-1,j+k);cc++)
            {
                if (mp[i][cc]>=mp[i][j]) continue;
                if (dp[i][cc]==-1) continue;
                dp[i][j] = max(dp[i][j], dp[i][cc]+mp[i][j]);
            }
            ans = max(ans,dp[i][j]);
        }
        cout << ans << endl;
    }
    return 0;
}



/*
//搜索写法  109ms, 1.8MB
const int maxn = 100+5;
int mp[maxn][maxn];
int dp[maxn][maxn];
int to[4][2]={
    {0,1},{0,-1},{1,0},{-1,0}
};
int n;int k;
int dfs(int i,int j)
{
    int ans=0;
    if (!dp[i][j]) //这里是记忆化搜索
    {
        for (int len=1;len<=k;len++)//最多走k次
        {
            for (int tt=0;tt<4;tt++)//4个方向
            {
                int nx = i+to[tt][0]*len;
                int ny = j+to[tt][1]*len;
                if (nx>=0 && nx<n && ny>=0 && ny<n && mp[nx][ny]>mp[i][j])
                    ans = max(ans,dfs(nx,ny));//ans:最大的dp[nx][ny]
            }
        }
        dp[i][j] = ans+mp[i][j];
    }
    return dp[i][j];
}

int main()
{
   // freopen("in","r",stdin);
    while(scanf("%d%d",&n,&k) && n!=-1)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                scanf("%d",&mp[i][j]);
            }
        }
        memset(dp,0,sizeof(dp));
        int ans = dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
*/
