/*************************************************************************
	> File Name: hdu2224.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月23日 星期六 10时56分35秒
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
hdu 2224 TSP问题(货郎担问题)----求最短哈密顿回路

离散数学P326
*/

const int maxn = 200+5;
struct pp{
    double x,y;
}p[maxn];
double dist(struct pp &a,struct pp &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
const int INF = 0x3f3f3f3f;
int dp[maxn];
int b[maxn];
bool flag[maxn];
int main()
{
    freopen("in","r",stdin);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    memset(b,INF,sizeof(INF));
    memset(dp,0,sizeof(dp));
    memset(flag,0,sizeof(flag));
    for (int i=0;i<n;i++)
    {
        int pos=lower_bound(b,b+n,p[i].y)-b;
        dp[i]=pos+1;
        b[pos]=p[i].y;
    }
    int maxlen=0;
    for (int i=0;i<n;i++)
        maxlen = max(maxlen,dp[i]);

    double ans=0;
    for (int i=0;i<maxlen;i++)
    {
        ans+=dist(p[b[i]],p[b[i+1]]);
        flag[b[i]]=1;
    }
    int pre = n-1;
    for (int i=n-1;i>=0;i--)
    {
        if (flag[i]==0)
        {
            ans += dist(p[i],p[pre]);
            pre = i;
        }
    }
    ans += dist(p[pre],p[0]);

    cout << ans << endl;

    //cout << dist(p[3],p[1])+dist(p[3],p[2])+dist(p[2],p[1]) << endl;
    //cout << dist(p[3],p[2])+dist(p[1],p[2])+dist(p[3],p[1]) << endl;
    
    return 0;
}
