/*************************************************************************
	> File Name: poj3666.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月03日 星期二 22时35分37秒
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
int a[2005];
int b[2005];
int dp[2005][2005];
/*
 * 按照贪心思想,变换后的数一定在原来数列中出现
 * 把以每个作为最后数来dp
 */
int main()
{
    freopen("in","r",stdin);
    int n;cin>>n;
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    memcpy(b,a,sizeof(a));
    sort(b,b+n);
    for (int i=0;i<n;i++)
        dp[0][i]=abs(a[0]-b[i]);
    for (int i=1;i<n;i++)
    {
        int tmp = dp[i-1][0];
        for (int j=0;j<n;j++)
        {
            tmp = min(tmp,dp[i-1][j]);
            dp[i][j] = tmp+abs(a[i]-b[j]);
        }
    }
    int ans = dp[n-1][0];
    for (int i=1;i<n;i++)
        ans = min(ans,dp[n-1][i]);
    cout << ans;

    return 0;
}
