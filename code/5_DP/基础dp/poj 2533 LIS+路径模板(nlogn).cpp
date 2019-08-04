/*************************************************************************
	> File Name: poj 2533 裸LIS(二分做法).cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月18日 星期五 13时30分55秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/*
 * LIS+记录最大串
 * 复杂度: O (nlogn)
 * b[i]:保存每个以a[i]结尾的最长上升子序列
 * 其中low_bound 返回第一个大于它的数的下标。
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
