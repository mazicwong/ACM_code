/*************************************************************************
	> File Name: 4.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月10日 星期日 12时13分07秒
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

/*
 * 判断一个字符串,最长上升子序列
 *
 */
const int maxn = 1e5+5;
const int INF = 0x3f3f3f3f;

int b[maxn];
int a[maxn];
int dp[maxn];
int cc[maxn];
int main()
{
    freopen("in4","r",stdin);
    int t;cin>>t;
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            dp[i]=1;
        }
        memset(b,INF,sizeof(b));
        for (int i=0;i<n;i++)
        {
            int pos = upper_bound(b,b+n,a[i])-b;
            dp[i]=pos+1;
            b[pos] = a[i];
        }
        int ans = 0;
        for (int i=0;i<n;i++)
            ans = max(ans,dp[i]);
        /*
        cout << ans << endl;
        for (int i=0;i<ans;i++)
            cout << b[i] << ' ';
        cout << endl;
        */
        if (n-k <= ans)
        {
            puts("A is a magic array.");            
            continue;
        }

        //这个判下降序列的不加也A了??
/*
        for (int i=0;i<n;i++)
        {
            cc[n-1-i]=a[i];
            dp[i]=1;
        }
        memset(b,INF,sizeof(b));
        for (int i=0;i<n;i++)
        {
            int pos = upper_bound(b,b+n,cc[i])-b;
            dp[i]=pos+1;
            b[pos] = cc[i];
        }
        int ans1 = 0;
        for (int i=0;i<n;i++)
            ans1 = max(ans1,dp[i]);
        if (n-k <= ans1)
        {
            puts("A is a magic array.");            
            continue;
        }
*/
        else
        {
            puts("A is not a magic array.");
        }
    }
    
    return 0;
}
