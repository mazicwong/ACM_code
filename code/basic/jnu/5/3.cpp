#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <time.h>
using namespace std;
const int maxn = 1e5+5;
int sa[maxn];
int Rank[maxn],height[maxn];
int t1[maxn],t2[maxn],c[maxn];//求SA数组需要的中间变量,不需要赋值

/**************倍增算法**************************/
bool cmp(int *str,int a,int b,int l)
{
    return str[a]==str[b] && str[a+l]==str[b+l];
}
void build_sa(int str[],int n,int m)
{
    n++;//有n++了,所有传入build_sa(n)就好
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

    //计算height[]; void getHeight(int n)
    int k=0;
    n--;//传入n++了,这里改回来原来的n
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
int dp[maxn][20];
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

char str[maxn];
int r[maxn];

int main()
{
    //freopen("in","r",stdin);
    cin>>str;
    int n=strlen(str);
    int len=n;
    for(int i=0;i<n;i++) r[i]=str[i]-'a'+1; r[n]=0;
    build_sa(r,n,28);
    int k; cin>>k;

    RMQ::init(len+1);
    int ans=0;
    for(int i=0;i+k<n;i++)
        ans = max(ans,RMQ::lcp(i,i+k));
    cout<<ans;
    return 0;
}
