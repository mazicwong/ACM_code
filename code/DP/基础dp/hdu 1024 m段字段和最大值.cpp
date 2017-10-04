/*************************************************************************
	> File Name: hdu1024.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月04日 星期三 08时57分02秒
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
 * hdu1024
 * n个数,找m个不重叠的区间,使得每个区间的和最大,输入最大值
 */

const int maxn = 1e6+5;
int a[maxn];
int dp[maxn];//dp[i][j]: 前j个分为i段的最大
int maxx[maxn];
int main()
{
    freopen("in","r",stdin);
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int ans = 0;
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(maxx,0,sizeof(maxx));
        memset(dp,0,sizeof(dp));

        for (int i=1;i<=m;i++)
        {
            ans = -0x3f3f3f3f; //dp[i-1][j]前j个的最大
            for (int j=i;j<=n;j++)
            {
                dp[j] = max(dp[j-1]+a[j], maxx[j-1]+a[j]); //最后一个也在,最后一个独立
                maxx[j-1] = ans;
                ans = max(ans,dp[j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
