/*************************************************************************
	> File Name: poj3186.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月04日 星期三 13时23分16秒
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
const int maxn = 2005;
int a[maxn];
int dp[maxn][maxn];
/*
 * 给一个序列,每次可以从头取或者从尾巴取,
 * sum += k*a[i] ; k是第几次取,问sum的最大
 *
 * 同样的,不能按照一个固定的方向来进行DP,这里序列是线性的,
 * 则按照区间来进行DP
 * dp[i,j]: i到j的最优解, 长度j-i+1
 * dp[i,j] = max(dp[i+1][j]+a[i]*(n-len+1), dp[i][j-1]+a[j]*(n-len+1));
 */

int main()
{
    freopen("in","r",stdin);
    int n;cin>>n;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        dp[i][i]=a[i]*n;
    }
    //从距离小扩展到距离大
    for (int len=1;len<n;len++)
    {
        for (int i=0;i+len<n;i++)
        {
            int j = i+len;
            dp[i][j] = max(dp[i+1][j]+a[i]*(n-len), dp[i][j-1]+a[j]*(n-len));
        }
    }
    cout << dp[0][n-1];
    return 0;
}
