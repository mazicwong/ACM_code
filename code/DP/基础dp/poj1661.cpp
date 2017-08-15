/*************************************************************************
	> File Name: poj1661.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月08日 星期二 10时34分37秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1e3+5;
//dp[i][0]表示以i号平台左边为起点到地面的最短时间
//dp[i][1]表示以i号平台右边为起点到地面的最短时间
//dp[i][0] = H[i]-H[m]+min(dp[m][0]+X1[i]-X1[m],dp[m][1]+X2[m]-X1[i]);  m为i左边下面的平台的编号
//dp[i][1] = H[i]-H[m]+min(dp[m][0]+X2[i]-X1[m],dp[m][1]+X2[m]-X2[i]);  m为i右边下面的平台的编号
//
//http://blog.csdn.net/jdplus/article/details/19919531
int x1[maxn],x2[maxn],h[maxn];
int main()
{
    freopen("in","r",stdin);
    int t;
    cin >> t;
    while(t--)
    {
        int n,x,y,maxx;
        scanf("%d%d%d%d",&n,&x,&y,&maxx);
        for (int i=0;i<n;i++)
        {
            scanf("%d%d%d",&x1[i],&x2[i],&h[i]);

        }

    }
    
    return 0;
}
