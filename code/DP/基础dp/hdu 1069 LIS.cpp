/*************************************************************************
	> File Name: hdu1069.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月24日 星期一 09时56分50秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 180+5;
struct node{
    int a,b,h;
}mm[maxn];
int dp[maxn];
bool cmp(node a,node b)
{
    if (a.a==b.a) return a.b<b.b;
    else return a.a<b.a;
}

int main()
{
    freopen("in","r",stdin);
    int n;
    int xx,yy,zz;
    int cas=1;
    while(scanf("%d",&n) && n)
    {
        int ans=0;
        int cnt=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d%d%d",&xx,&yy,&zz);
            mm[cnt].a=xx,mm[cnt].b=yy,mm[cnt++].h=zz;
            mm[cnt].a=xx,mm[cnt].b=zz,mm[cnt++].h=yy;
            mm[cnt].a=yy,mm[cnt].b=xx,mm[cnt++].h=zz;
            mm[cnt].a=yy,mm[cnt].b=zz,mm[cnt++].h=xx;
            mm[cnt].a=zz,mm[cnt].b=xx,mm[cnt++].h=yy;
            mm[cnt].a=zz,mm[cnt].b=yy,mm[cnt++].h=xx;
        }
        sort(mm,mm+cnt,cmp);

        memset(dp,0,sizeof(dp));
        for (int i=1;i<cnt;i++)
        {
            dp[i]=mm[i].h;
            for (int j=0;j<i;j++)
            {
                if (mm[j].a<mm[i].a && mm[j].b<mm[i].b)
                    dp[i]=max(dp[i], dp[j]+mm[i].h);
            }
        }
        
        for (int i=0;i<cnt;i++)
            ans=max(ans,dp[i]);
        printf("Case %d: maximum height = %d\n",cas++,ans);
    }

    return 0;
}
