/*************************************************************************
	> File Name: poj 1321 状压dp.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月17日 星期一 11时21分28秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
//状压写法
//状态转移：当前行不加棋子，加棋子
//dp[i][j]：i行数，j棋子状态(1有，0无)
const int maxn=10;
int n,k;
char mp[maxn][maxn];
int cnt[1<<maxn];
int dp[maxn][1<<maxn]; //i行数，j加不加棋子

int check(int n)
{
    int ans=0;
    while(n)
    {
        if (n%2)
            ans++;
        n/=2;
    }
    return ans;
}
int main()
{
    //freopen("in.txt","r",stdin);
    for (int i=0;i<(1<<maxn);i++)
        cnt[i]=check(i);
    while(cin>>n>>k && n!=-1)
    {
        memset(dp,0,sizeof(dp));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                cin>>mp[i][j];
        dp[0][0]=1;
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<(1<<n);j++)
            {
                if (cnt[j]<=k)
                {
                    dp[i][j]+=dp[i-1][j];  //获取前n-1行的
                    for (int p=1;p<=n;p++) //更新本行
                    {
                        if ( ((1<<(p-1))&j) && mp[i][p]=='#')
                        {
                            dp[i][j]+=dp[i-1][(~(1<<p-1))&j];
                        }
                    }
                }
            }
        }
        int ans=0;
        for (int i=0;i<(1<<n);i++)
            if (cnt[i]==k)
                ans += dp[n][i];
        cout << ans << endl;
    }
    return 0;
}
