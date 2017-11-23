/*************************************************************************
	> File Name: b.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月15日 星期日 16时10分39秒
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

const int maxn = 1e5+5;
const int INF = 0x3f3f3f3f;
int a[maxn];
//int b[maxn];
int main()
{
    //freopen("in","r",stdin);
    int n,k;cin>>n>>k;
    int minn=INF;
    int maxx=-INF;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        minn=min(minn,a[i]);
        maxx=max(maxx,a[i]);
        //b[i]=a[i];
    }
    //sort(b,b+n);
    if (k>=3)
    {
        cout << maxx;
        return 0;
    }
    if (k==1)
    {
        cout << minn;
        return 0;
    }
    int dp[maxn];
    int rp[maxn];
    if (k==2)
    {
        //max(dp[i])
        dp[0]=a[0];
        for (int i=1;i<n-1;i++)
        {
            dp[i]= min(dp[i-1],a[i]);
        }
        rp[n-1]=a[n-1];
        for (int i=n-2;i>=1;i--)
        {
            rp[i]= min(rp[i+1],a[i]);
        }

        int ans = -INF;
        for (int i=0;i<n-1;i++)
        {
            ans = max(ans,max(dp[i],rp[i+1]));
        }
        cout << ans;
    }
    return 0;
}
