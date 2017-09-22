/*************************************************************************
	> File Name: lightoj1422.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月23日 星期六 01时08分05秒
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

const int maxn = 100+5;
int dp[maxn][maxn];
int a[maxn];
int n;

int main()
{
    freopen("in","r",stdin);
    int t;cin>>t;
    for (int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for (int i=1;i<=n;i++)
            for (int j=i;j<=n;j++)
                dp[i][j]=j-i+1;
        for (int i=n-1;i>=1;i--)
        {
            for (int j=i+1;j<=n;j++)
            {
                dp[i][j] = dp[i+1][j]+1;
                for (int k=i+1;k<=j;k++)
                {
                    if (a[i]==a[k])
                    {
                        dp[i][j] = min(dp[i][j],dp[i][k-1]+dp[k+1][j]);
                    }
                }
            }
        }
        printf("Case %d: %d\n",cas,dp[1][n]);
    }
    return 0;
}
