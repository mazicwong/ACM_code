/*************************************************************************
	> File Name: hdu1257.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月06日 星期日 12时33分33秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 3e4+5;
int a[maxn];
int dp[maxn];
int main()
{
    freopen("in","r",stdin);
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            dp[i]=1;
        }
        for (int i=1;i<n;i++)
        {
            for (int j=0;j<i;j++)
            {
                if (a[i]>a[j])
                    dp[i]=max(dp[i],dp[j]+1);
            }
        }
        int ans = -1;
        for (int i=0;i<n;i++)
            ans = max(ans,dp[i]);
        printf("%d\n",ans);
    }


    return 0;
}
