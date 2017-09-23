/*************************************************************************
	> File Name: 1.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月23日 星期六 16时12分25秒
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
```

int main()
{
    freopen("in","r",stdin);
    
    return 0;
}

/*
 * LIS+记录最大串
 * 复杂度: O (nlogn)
 * b[i]:保存每个以a[i]结尾的最长上升子序列
 * 其中low_bound 返回第一个大于它的数的下标。
 * 非严格递增(non-decreasing order):把lower_bound改为upper_bound
 * b[0...max(dp[i])]: 记录LIS结果
 */

const int maxn = 1e3+5;
const int INF = 0x3f3f3f3f;
int a[maxn];
int b[maxn];
int dp[maxn];

int main()
{
    freopen("in","r",stdin);
    int n; cin >> n;
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    memset(b,INF,sizeof(b));
    memset(dp,0,sizeof(dp));
    for (int i=0;i<n;i++)
    {
        int pos = lower_bound(b,b+n,a[i])-b;//a[i]在b[]中的位置
        dp[i] = pos+1;
        b[pos] = a[i];
    }
    int ans = 0;
    for (int i=0;i<n;i++)
        ans=max(ans,dp[i]);
    cout << ans;
    /*cout << endl;
    for (int i=0;i<ans;i++)
        cout << b[i] << " ";*/
    return 0;
}
```

