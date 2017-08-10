/*************************************************************************
	> File Name: poj3061.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月11日 星期五 00时36分20秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
//https://vjudge.net/article/180  斜率优化DP?
const int maxn = 1e5+5;
const int INF = 0x3f3f3f3f;

int S;
int n;
int a[maxn];
int sum[maxn];
void solve()
{
    int ans = INF;
    int s=0,t=0,sum=0;//左右端点和前缀和
    while(1)
    {
        while(t<n && sum<S)
            sum += a[t++];//右端点右移
        if (sum<S) break;
        ans = min(ans,t-s);
        sum -= a[s++];//左端点右移
    }
    if (ans == INF) ans=0;
    printf("%d\n",ans);
}
int main()
{
    freopen("in","r",stdin);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> S;
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sum[0]=a[0];
        for (int i=1;i<n;i++)//预处理前缀和
            sum[i]=sum[i-1]+a[i];

        solve();
    }
    return 0;
}
