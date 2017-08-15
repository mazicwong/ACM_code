/*************************************************************************
	> File Name: hdu1114.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月06日 星期日 09时19分59秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 500+5;
const int INF = 0x3f3f3f3f;
int c[maxn],w[maxn];//cost & value(min)

const int maxm = 1e4+5;//背包容量
int dp[maxm];
int main()
{
    freopen("in","r",stdin);
    int t;
    cin >> t;
    int e,f;
    while(t--)
    {
        int e,f;
        scanf("%d%d",&e,&f);
        int vv = f-e;
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d%d",&w[i],&c[i]);

        memset(dp,INF,sizeof(dp));
        dp[0]=0;
        for (int i=0;i<n;i++)
        {
            for (int j=c[i];j<=vv;j++)
            {
                dp[j] = min(dp[j],dp[j-c[i]]+w[i]);
            }
        }
        if (dp[vv]==INF)
            puts("This is impossible.");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[vv]);
    }
    return 0;
}
