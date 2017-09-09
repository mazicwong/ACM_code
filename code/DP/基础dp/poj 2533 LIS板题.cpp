/*************************************************************************
	> File Name: poj2533.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月09日 星期六 10时57分56秒
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
//poj2533  LIS
const int maxn = 1e3+5;
int a[maxn];
int dp[maxn];
int main()
{
    freopen("in","r",stdin);
    int n;cin>>n;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        dp[i]=1;
    }
    for (int i=0;i<n;i++) //0..j..i..n
    {
        for (int j=0;j<i;j++)
        {
            if (a[j]<a[i])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int ans=0;
    for (int i=0;i<n;i++)
    {
        ans = max(ans,dp[i]);
    }
    printf("%d",ans);
    return 0;
}
