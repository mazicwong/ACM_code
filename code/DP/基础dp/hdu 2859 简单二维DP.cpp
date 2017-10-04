/*************************************************************************
	> File Name: hdu2859.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月04日 星期三 10时03分08秒
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
 * 给n*n矩阵,问最大对称子矩阵是多大(沿着左下角到右上角对称)
 *
 * 先转换为主对角线矩阵
 * 然后从右下角开始往左上角
 * dp[i][j] = dp[i][j]+cnt;  cnt是dp[i][j]沿着对角线向右下角能走多远.
 * 当超过dp[i+1][j+1]或者超过矩阵,就退出,
 *
 */

const int maxn = 1005;
char matrix[maxn][maxn];
int dp[maxn][maxn];
int main()
{
    freopen("in","r",stdin);
    int n;
    while(scanf("%d",&n) && n)
    {
        for (int i=n-1;i>=0;i--) //换成主对角.方便些
            scanf("%s",matrix[i]);
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++)
                dp[i][j]=1;

        for (int i=n-1;i>=0;i--)
        {
            for (int j=n-1;j>=0;j--)
            {
                bool flag=true;
                int cnt=0;
                for (int rr=1;rr<=dp[i+1][j+1];rr++)
                {
                    if (i+rr>=n || j+rr>=n)
                        break;
                    if (matrix[i][j+rr] != matrix[i+rr][j])
                    {
                        break;
                    }
                    cnt++;
                }
                dp[i][j]=dp[i][j]+cnt;
            }
        }
        int ans=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                ans = max(ans,dp[i][j]);
        cout << ans << endl;
    }
    return 0;
}
