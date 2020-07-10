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
const int MAXN=1e6+5000;
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

bool check(int mid,int n,int k)
{
    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        if(height[i]>=mid)
            cnt++;
        else cnt=1;
        if(cnt>=k) return 1;
    }
    return 0;
}

char str[MAXN];//原串[0..n-1]
int main()//hdu4552 求所有前缀出现的次数之和
{
    int n,k; cin>>n>>k;
    int a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        str[i]=a+'a'+1;
    }
    str[n]=0;
    da(str,n+1,1000000+150); //A:65, a:97   97+28=125
    calheight(str,n);
    //以上都是套路

    int l=0,r=n; int mid;
    int ans=0;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid,n,k))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout << ans;
    return 0;
}
