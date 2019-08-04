/*************************************************************************
	> File Name: 88.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月10日 星期四 16时54分03秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
//解释的很清楚: http://blog.csdn.net/archger/article/details/77073334
const int maxn = 5e3+5;
char a[maxn];
char num[maxn];
int m;
int solve(int len)
{//传入:num[0..len-1]是左右两段区间对应的dist值(预处理)
 //所求对应为找最大区间使得sum{num[]}<=m
    int ans=0;
    int s=0,t=0,sum=0;//左右端点+前缀和
    while(1)
    {
        while(sum+num[t]<=m && t<len)//右端点t向右移动
        {
            sum+=num[t];
            ans=max(t-s+1,ans);
            t++;
        }
        sum -= num[s++];//左端点s向右移动
        if(s>=len) break;
    }
    return ans;
}
int main()
{
    freopen("in","r",stdin);
    int t;
    cin >> t;
    while(t--)
    {
        scanf("%d",&m);
        scanf("%s",a);
        int n = strlen(a);
        int ans = 0;


        //分为两种情况，把可能的dis值存入num[]中，然后对num[]进行尺取
        for (int mid=0;mid<=n;mid++) //枚举两串对称的中点
        {
            int cnt = 0;
            for (int t=1;mid+t<n && mid-t>=0;t++)//奇数情况
                num[cnt++] = abs(a[mid+t]-a[mid-t]);
            ans = max(ans,solve(cnt));
        }
        for (int mid=0;mid<=n;mid++) //枚举两串对称的中点
        {
            int cnt = 0;
            for (int t=1;mid+(t-1)<n && mid-(t)>=0;t++)//偶数情况
                num[cnt++] = abs(a[mid+t-1]-a[mid-t]);
            ans = max(ans,solve(cnt));
        }

        /*
        for (int mid=1;mid<n;mid++)//枚举中间位置
        {
            int cnt=1;//
            int dis=0;
            for (int t=1;mid-t>=0 && mid+t<n;t++)
            {//[mid-t,mid-cnt]与[mid+cnt,mid+t]两串,固定初始为[mid-t,mid],通过cnt将mid左移直到`dis<=n`且串最大,右边同理
                dis += abs(a[mid-t]-a[mid+t]);
                while(dis>m)
                {
                    cnt++;
                    dis -= abs(a[mid-cnt]-a[mid+cnt]);
                }
                ans = max(ans,t-cnt+1);//len[a,b]=a-b+1
            }
            cnt=1,dis=0;
            for (int t=1;mid-(t)>=0 && mid+(t-1)<n;t++)
            {//[mid-t,mid]与[mid,mid+(t-1)]两串
                dis += abs(a[mid+t-1]-a[mid-t]);
                while(dis>m)
                {
                    cnt++;
                    dis -= abs(a[mid+cnt-1]-a[mid-cnt]);
                }
                ans = max(ans,t-cnt+1);
            }
        }*/

        printf("%d\n",ans);
    }
    return 0;
}
