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
const int MAXN=1e6+50000;

/*
 * 这组input组数据能卡两次后缀数组的做法
 * input
 * 9
 * 9 -2 8 1 1 8 1 1 2
 *
 * output
 * -2 9 1 1 8 1 1 nt sa[MAXN],Rank[MAXN],height[MAXN];nt wa[MAXN],wb[MAXN],c[MAXN]nt cmp(int *r,int a,int b,int l);8 2
 */

int sa[MAXN],Rank[MAXN],height[MAXN];
//以下为倍增算法求后缀数组 
int wa[MAXN],wb[MAXN],c[MAXN];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
/**< 传入参数：str,len+1,ASCII_MAX+1 */ 
void da(const int r[],int n,int m)
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
void calheight(const int *r,int n)
{
    int i,j,k=0;
    for(i=1; i<=n; i++) Rank[sa[i]]=i;
    for(i=0; i<n; height[Rank[i++]]=k)
        for(k?k--:0,j=sa[Rank[i]-1]; r[i+k]==r[j+k]; k++);
    for(int i=n;i>=1;--i) ++sa[i],Rank[i]=Rank[i-1];//重排
}

int a[MAXN];
int str[MAXN];//原串[0..n-1]
int ans[MAXN];

int main()
{
    //10    5 6 7 8   1 2 3 4   99 1111
    //freopen("in","r",stdin);
    int n; cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);    // a = {10 1 2 3 4}
    map<int,int> mp; mp.clear();
    map<int,int> ni; ni.clear();
    int tmp[MAXN];
    for(int i=0;i<n;i++) tmp[i]=a[i];
    sort(tmp,tmp+n);
    int size=unique(tmp,tmp+n)-tmp;
    for(int i=0;i<n;i++)
    {
        int tt = lower_bound(tmp,tmp+size,tmp[i])-tmp+1;
        mp[tmp[i]]=tt;
        ni[tt]=tmp[i];
        //tmp[i]=lower_bound(tmp,tmp+size,tmp[i])-tmp+1;
    }
    for(int i=0;i<n;i++) a[i] = mp[a[i]];
    //for(int i=0;i<n;i++) printf("%d ",a[i]); puts("");
    //以上，从a[i]得到新的a[i], mp<>, ni<>

    //for(int i=0;i<n;i++) cout << a[i] << ' '; cout << endl;
    for(int i=0;i<n;i++) str[i]=a[n-1-i];  //str = {4 3 2 1 10}
    str[n]=0;
    //cout << "str:::" << endl;
    //for(int i=0;i<n;i++) printf("%d ",str[i]); puts("");

    //第一阶段
    da(str,n+1,MAXN);
    calheight(str,n);
    int idx = sa[1];  // [0....len-idx] 第一阶段  4
    if(idx==1) idx=sa[2];
    if(idx==2) idx=sa[3];
    //cout << idx << "asf" <<endl;
    for(int i=0;i<=n-idx;i++)
    {
        ans[i] = str[i+(idx-1)];   // ans = {1,10}
    }
    int ans_cnt=n-idx+1; //2

    //第二阶段
    n-=(n-idx+1);  // 3  str={4 3 2}
    for(int i=0;i<n;i++) str[i+n]=str[i];
    n+=n;
	str[n]=0;
    da(str,n+1,MAXN);
    calheight(str,n);
    n/=2;
    idx = sa[1];   // 3
    int cc=2;
    while(idx==1 || idx>n)
    {
        idx=sa[cc++];
    }
    //cout << "NONO :  " << idx << endl;
    for(int i=0;i<=n-idx;i++)
    {
        ans[i+ans_cnt] = str[i+(idx-1)];  //ans = {1,10  2}
    }
    ans_cnt = n-idx+ans_cnt+1;  // 3

    //第三阶段
    n-=(n-idx+1); // 2 str={4 3}
    for(int i=0;i<n;i++)
    {
        ans[i+ans_cnt] = str[i]; // ans = {1,10  2  4,3}
    }
    ans_cnt += n;

    for(int i=0;i<ans_cnt;i++)
    {
        printf("%d\n",ni[ans[i]]);
        //cout << ans[i] << endl;
    }
    return 0;
}
