#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5000;
int sa[MAXN],Rank[MAXN],height[MAXN];
//以下为倍增算法求后缀数组 
int wa[MAXN],wb[MAXN],c[MAXN];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
/**< 传入参数：str,len+1,ASCII_MAX+1 */ 
void da(const char r[],int n,int m)
{
    int i,j,p,*x=wa,*y=wb;
    for(i=0; i<m; i++) c[i]=0;
    for(i=0; i<n; i++) c[x[i]=r[i]]++;//以字符的ascii码为下标 
    for(i=1; i<m; i++) c[i]+=c[i-1];
    for(i=n-1; i>=0; i--) sa[--c[x[i]]]=i;
    /*cout<<"SA"<<endl;;
    for(int i=0;i<n+1;i++)cout<<sa[i]<<' ';*/
    for(j=1,p=1; p<n; j*=2,m=p)
    {
        //直接利用sa数组排序第二关键字
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<m;i++) c[i]=0;
        for(i=0;i<n;i++) c[x[y[i]]]++;
        for(i=1;i<m;i++) c[i]+=c[i-1];
        for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
        //根据sa和x数组计算新的x数组
        for(swap(x,y),p=1,x[sa[0]]=0,i=1; i<n; i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return;
}
//求height数组
/**< str,len >**/
void calheight(const char *r,int n)
{
    int i,j,k=0;
    for(i=1; i<=n; i++) Rank[sa[i]]=i;
    for(i=0; i<n; height[Rank[i++]]=k)
        for(k?k--:0,j=sa[Rank[i]-1]; r[i+k]==r[j+k]; k++);
    for(int i=n;i>=1;--i) ++sa[i],Rank[i]=Rank[i-1];//重排
}

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


char str[MAXN];//原串[0..n-1]
int main()//hdu4552 求所有前缀出现的次数之和
{
    while(scanf("%s",str)!=EOF)
    {
        int len=strlen(str);
        str[len]=0;
        da(str,len+1,125); //A:65, a:97   97+28=125
        calheight(str,len);
        //以上都是套路

        //法1:
        RMQ::init(len+1);
        int ans=len;
        for(int i=2;i<=len;i++)
            ans = (ans+RMQ::lcp(1,i))%256;
        printf("%d\n",ans);
        
        puts("--------------All Suffix--------------");
        for(int i=1; i<=len; ++i)
        {
            printf("%d:\t",i);
                for(int j=i-1; j<len; ++j)
                    printf("%c",str[j]);
                puts("");
        }
        puts("");
        puts("-------------After sort---------------");
        for(int i=1; i<=len; ++i)
        {
            printf("sa[%2d ] = %2d\t",i,sa[i]);
            for(int j=sa[i]-1; j<len; ++j)
                printf("%c",str[j]);
            puts("");
        }
        puts("");
        puts("---------------Height-----------------");
        for(int i=1; i<=len; ++i)
            printf("height[%2d ]=%2d \n",i,height[i]);
        puts("");
        puts("----------------Rank------------------");
        for(int i=1; i<=len; ++i)
            printf("Rank[%2d ] = %2d\n",i,Rank[i]);
        puts("------------------END-----------------");
    }
    return 0;
}
