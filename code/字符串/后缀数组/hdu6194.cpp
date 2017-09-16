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
typedef long long ll;
//Rank[i] 第i个后缀的排名; sa[i] 排名为i的后缀位置;
//height[i] 排名为i的后缀与排名为(i-1)的后缀的LCP(相邻排名最长公共前缀)


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
int dp[MAXN][20];
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


/******以上为模板*******/

/* hdu6194
 * 给一个字符串,问有多少个子串在字符串中出现了k次
 * 
 * 思路: 预处理出sa[]和height[],然后由于sa数组相邻的两项是最接近的，
 * 也就是说出现了k次的子串它的起始位置在sa数组中是连续的。
 *
 * 那么我们考虑去枚举长度为区间，比如我们现在枚举的区间为[l,l+k-1]，那么我们我们利用RMQ求出这一段区间的lcp(最长公共前缀)。
 *
 * 假设lcp为x，那么说明在枚举的区间内有x个子串在字符串中至少出现了k次，但是我们要求的是正好出现k次的。
 *
 * 很容易想到可以用至少出现k次的数目减去至少出现(k+1)次的便是正好出现k次的数目。
 *
 */

char str[MAXN];
int r[MAXN];
int main()//hdu6194 哪些子串在字符串中出现k次
{
    //freopen("in","r",stdin);
    int t;cin>>t;
    while(t--)
    {
        int k;
        scanf("%d%s",&k,str);
        int n=strlen(str);
        int len=n;
        for (int i=0;i<n;i++)
            r[i]=str[i]-'a'+1;
        r[n]=0;
        build_sa(r,n,28);            //得到sa,Rank,height数组
        RMQ::init(len+1);            //RMQ预处理区间最长公共前缀
        int ans=0;
        for (int i=1;i+k-1<=n;i++)   //枚举区间
        {
            //得到区间内出现至少k次的子串
            ans+=RMQ::lcp(i,i+k-1);//k长度
            if (i>1) ans-=RMQ::lcp(i-1,i+k-1);//k+1长度
            if (i+k<=n) ans-=RMQ::lcp(i,i+k);//k+1长度
            if (i>1 && i+k<=n) ans+=RMQ::lcp(i-1,i+k);//k长度
        }
        printf("%d\n",ans);
    }
    return 0;
}
