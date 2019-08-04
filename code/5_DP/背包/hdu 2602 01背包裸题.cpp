/*************************************************************************
	> File Name: hdu2602.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月05日 星期六 21时02分44秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1000+5;
int dp[maxn];
int w[maxn];
int v[maxn];
int main()
{
    freopen("in","r",stdin);
    int t;
    cin >> t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        int n,vv;
        cin >> n >> vv;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&w[i]);
        }
        for (int i=0;i<n;i++)
        {
            scanf("%d",&v[i]);
        }
        for (int i=0;i<n;i++)
            for (int j=vv;j>=v[i];j--)
                dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        printf("%d\n",dp[vv]);
    }
    
    return 0;
}
