/*************************************************************************
	> File Name: hdu6212.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月22日 星期五 22时53分23秒
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
 * http://blog.csdn.net/mengxiang000000/article/details/78031207
 * zuma游戏,0/1两种球,三个以上在一起可以消去
 * 现在给一个线性排列,问最小插入多少球可以使得全部消去
 *
 * 最优解+小数据,区间DP
 *
 *  dp[i,j] = min(dp[i,j], dp[i,k]+dp[k+1,j]);
 *  dp[i,j] = min(dp[i,j], dp[i+1,j-1]+(a[i]+a[j]是否小于3));
 *  dp[i,j] = min(dp[i,j], dp[i+1,k-1]+dp[k+1,j-1]);  //其中a[i]+a[j]<4
 *
 *
 */

const int maxn = 200+5;
char str[maxn];
int a[maxn];
int dp[maxn][maxn];
int main()
{
    freopen("in","r",stdin);
    int t;cin>>t;
    for (int cas=1;cas<=t;cas++)
    {
        scanf("%s",str);
        int n = strlen(str);
        int cnt=1;
        a[1]=1;
        for (int i=1;i<n;i++)
        {
            if (str[i]==str[i-1]) a[cnt]++;
            else a[++cnt]=1;
        }
        for (int len=0;len<=cnt;len++)
        {
            for (int i=1;i<=cnt;i++)
            {
                int j=i+len;
                if (j<=cnt && j>=1)
                {
                    dp[i][j]=2*n;
                    if (len==0)
                        dp[i][j]=3-a[i];
                    else
                    {
                        for (int k=i;k<j;k++)
                            dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                        if ((j-i-1)%2==1)
                        {
                            if (a[i]+a[j]==2)
                                dp[i][j]=min(dp[i][j],dp[i+1][j-1]+1);
                            else
                                dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
                            if (a[i]+a[j]<4)
                            {
                                for (int k=i+2;k<j;k+=2)
                                {
                                    if (a[k]==1)
                                        dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k+1][j-1]);
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("Case #%d: ",++cas);
        printf("%d\n",dp[1][cnt]);
    }
    return 0;
}
