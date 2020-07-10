/*************************************************************************
	> File Name: poj3261.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月16日 星期六 09时38分43秒
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
 * 出现至少k次的最长子串
 * height[i]是sa[i]与sa[i-1]的lcp
 * 然后二分最长长度,O(n)判断能否有该串
 * height[]性质:相同前缀的在一起,所以找到连续k个height[]>=t说明存在k个长度t的子串
 */
typedef long long ll;
inline ll read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;

}

const int MAXN = 1e6+5000;
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

int r[MAXN];
int n,k; 
bool check(int mid)
{
    int cnt=0;
    for (int i=2;i<=n;i++)//注意这里的范围
    {
        if (height[i]>=mid)
            cnt++;//找连续k个这样的height
        else cnt=1;
        if (cnt>=k)
            return 1;
    }
    return 0;
}
int main()
{
    //freopen("in","r",stdin);
    cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        r[i]=read();
        r[i]++;
    }
    r[n]=0;
    build_sa(r,n,1000005);

    int ll=0,rr=n;
    while(ll<=rr)
    {
        int mid = (ll+rr)>>1;
        if (check(mid))
            ll=mid+1;
        else rr=mid-1;
    }
    cout << rr << endl;
    return 0;
}
