/*************************************************************************
	> File Name: hdu2546.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月05日 星期六 20时22分57秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1000+5;
int price[maxn];
int dp[maxn];
int main()
{
    freopen("in","r",stdin);
    int n;
    int v;
    while(scanf("%d",&n)!=EOF && n)
    {
        for (int i=1;i<=n;i++)
            scanf("%d",&price[i]);
        scanf("%d",&v);
        memset(dp,0,sizeof(dp));
        sort(price+1,price+n+1);
        if (v<5)
        {
            printf("%d\n",v);
            continue;
        }
        v-=5;
        for (int i=1;i<n;i++)
        {
            for (int j=v;j>=price[i];j--)
            {
                dp[j]=max(dp[j], dp[j-price[i]]+price[i]);
            }
        }
        printf("%d\n",v+5-dp[v]-price[n]);
    }
    
    return 0;
}
