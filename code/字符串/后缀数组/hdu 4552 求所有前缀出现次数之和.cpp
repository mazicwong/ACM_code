/*************************************************************************
	> File Name: hdu4552.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月15日 星期五 20时52分07秒
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
 * 求每一个前缀出现的次数之和
 *
 * 等价于所有后缀与最长后缀的lcp之和,
 * 因为后缀是和原串匹配的,所以可以理解为前缀
 * 这样就可以把所有的前缀覆盖到!可以手写验证一下
 *
 * 直接后缀数组
 */


const int MAXN = 1e5+5;
int sa[MAXN];
int Rank[MAXN],height[MAXN];
int t1[MAXN],t2[MAXN],c[MAXN];//求SA数组需要的中间变量,不需要赋值
//要排序的母串放在str数组中,从str[0]到str[n-1],长度为n,且最大值小于m,
//除str[n]外的所有str[i]都大于0,r[n]=0
//函数结束以后结果放在sa数组中

/**************倍增算法**************************/
bool cmp(int *str,int a,int b,int l)
{
    return str[a]==str[b] && str[a+l]==str[b+l];
}
void build_sa(int str[],int n,int m)
{
    n++;
    int i,j,p,*x=t1,*y=t2;
    //第一轮基数排序,如果s的最大值很大,可改为快速排序
    for(i=0;i<m;i++) c[i]=0;
    for(i=0;i<n;i++) c[x[i]=str[i]]++;
    for(i=1;i<m;i++) c[i]+=c[i-1];
    for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
    for(j=1;j<=n;j<<=1)
    {
        p=0;
        //直接利用sa数组排序第二关键字
        for(i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<m;i++) c[i]=0;
        for(i=0;i<n;i++) c[x[y[i]]]++;
        for(i=1;i<m;i++) c[i]+=c[i-1];
        for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
        //根据sa和x数组计算新的x数组
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
        if(p>=n)break;
        m=p;//下次基数排序的最大值
    }
    //计算height[]
    int k=0;
    n--;//传入n+1,这里改回来
    for(i=0;i<=n;i++) Rank[sa[i]]=i;  
    for(i=0;i<n;i++)  
    {
        if(k) k--;
        j=sa[Rank[i]-1];
        while(str[i+k]==str[j+k]) k++;
        height[Rank[i]]=k;
    }
}
/**************倍增算法**************************/

/**************RMQ算法***************************/
int dp[MAXN][18];
namespace RMQ //蓝书P198
{
    void init(int n)
    {
        for (int i=1;i<=n;i++) dp[i][0] = height[i];
        for (int j=1;(1<<j)<=n;j++)
            for (int i=1;i+(1<<j)-1<=n;i++)
                dp[i][j] = min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
    }
    int rmq(int l, int r)
    {
        int k=0;
        while (1<<(k+1) <= r-l+1) k++;
        return min(dp[l][k], dp[r-(1<<k)+1][k]);
    }
    int lcp(int a, int b)//lcp的选取方法是当前区间的height[]最小值
    {
        a=Rank[a];b=Rank[b];
        if (a>b) swap(a,b);
        return rmq(a+1,b);//返回sa[a],sa[b]的最大公共前缀,规约到rmq问题
    }
}
/**************RMQ算法***************************/

char str[MAXN];
int r[MAXN];

int main()
{
    freopen("in","r",stdin);
    while(scanf("%s",str)!=EOF)
    {
        int len = strlen(str);
        int n=strlen(str);
        for (int i=0;i<n;i++)
            r[i]=str[i]-'a'+1;
        r[n]=0;//记得最后一个放为0
        build_sa(r,n,28);


        //法1
        int ans=n;//后面所有都不匹配,还有n个串是一样的,就是母串自己的n个前缀
        RMQ::init(len+1);//这里错了很久!!记得用len+1才是符合开始写的那些个条件
        for (int i=1;i<n;i++)
            ans = (ans+RMQ::lcp(0,i))%256;
        printf("%d\n",ans);
        
        //法2
        /*
        int ans=n;
        int t=Rank[0];//字典序最小的串
        int tmp=n;
        while(t>1)
        {
            tmp = min(tmp, height[t]);
            t--;
            ans+=tmp;
        }
        tmp=n;t=Rank[0];
        while(t<n)
        {
            tmp = min(tmp, height[t+1]);
            t++;
            ans+=tmp;
        }
        printf("%d\n",ans%256);
        */
    }
    return 0;
}
