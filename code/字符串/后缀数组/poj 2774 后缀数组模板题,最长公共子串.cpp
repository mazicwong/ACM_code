/*************************************************************************
	> File Name: poj2774.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月15日 星期五 20时20分29秒
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

const int MAXN = 2e5+5;//开大一倍,因为要存双份
int sa[MAXN];
int rank[MAXN],height[MAXN];
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
    n--;
    for(i=0;i<=n;i++) rank[sa[i]]=i;  
    for(i=0;i<n;i++)  
    {
        if(k) k--;
        j=sa[rank[i]-1];
        while(str[i+k]==str[j+k]) k++;
        height[rank[i]]=k;
    }
}
/**************倍增算法**************************/

char str[MAXN];
char str1[MAXN];
int r[MAXN];
int main()
{
    freopen("in1","r",stdin);
    while(scanf("%s",str)!=EOF)
    {
        scanf("%s",str1);

        int n=0;
        int len = strlen(str);
        for (int i=0;i<len;i++)
            r[n++]=str[i]-'a'+1;
        r[n++]=28;
        len = strlen(str1);
        for (int i=0;i<len;i++)
            r[n++]=str1[i]-'a'+1;
        r[n]=0;
        build_sa(r,n+1,30);
        int ans = 0;
        len = strlen(str);

        for (int i=2;i<n;i++)
        if (height[i]>ans)
        {
            if (0<=sa[i-1] && sa[i-1]<len && len<sa[i])
            ans = height[i];
            if (0<=sa[i] && sa[i]<len && len<sa[i-1])
            ans = height[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
