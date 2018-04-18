/************************************************ 
数据结构：后缀数组(Suffix_Array); 
 
子串: 
字符串S的子串r[i..j]，i≤j，表示r串中从i到j这一段， 
也就是顺次排列r[i],r[i+1],...,r[j]形成的字符串; 
后缀： 
后缀是指从某个位置i开始到整个串末尾结束的一个特殊子串; 
字符串r的从第i个字符开始的后缀表示为Suffix(i),也就是Suffix(i)=r[i...len(r)]; 
 
后缀数组SA:
后缀数组保存的是一个字符串的所有后缀的排序结果; 
其中SA[i]保存的是字符串所有的后缀中第i小的后缀的开头位置; 
名次数组Rank:(RMQ中,a=Rank[a],所以Rank是传入下标)
名次数组Rank[i]保存的是后缀i在所有后缀中从小到大排列的“名次”; 
后缀数组是"排第几的是谁",名次数组是"排第几",即后缀数组和名次数组为互逆运算; 
 
(1)倍增算法: 
用倍增的方法对每个字符开始的长度为2^k的子字符串进行排序，求出排名，即Rank值。 
k从0开始，每次加1，当2^k大于n以后，每个字符开始的长度为2^k的子字符串便相当于所有的后缀。 
并且这些子字符串都一定已经比较出大小，即Rank值中没有相同的值，那么此时的Rank值就是最后的结果。 
每一次排序都利用上次长度为2^k-1的字符串的Rank值， 
那么长度为2^k的字符串就可以用两个长度为2^k-1的字符串的排名作为关键字表示， 
然后进行基数排序，便得出了长度为2^k的字符串的Rank值。 
 
 
时间复杂度： 
倍增算法的时间复杂度为O(nlogn);
 
空间复杂度： 
倍增算法的空间复杂度都是O(n); 
倍增算法所需数组总大小为6n;
 
RMQ(Range Minimum/Maximum Query)问题： 
对于长度为n的数列A，回答若干询问RMQ(A,i,j)(i,j<=n)，
返回数列A中下标在i,j里的最小(大）值，
也就是说，RMQ问题是指求区间最值的问题。
 
LCA(Least Common Ancestors)最近公共祖先问题： 
对于有根树T的两个结点u、v， 
最近公共祖先LCA(T,u,v）表示一个结点x， 
满足x是u、v的祖先且x的深度尽可能大。 
另一种理解方式是把T理解为一个无向无环图， 
而LCA(T,u,v）即u到v的最短路上深度最小的点。 
 
RMQ标准算法： 
先规约成LCA(Lowest Common Ancestor),再规约成约束RMQ，O(n)-O(q); 
首先根据原数列，建立笛卡尔树， 
从而将问题在线性时间内规约为LCA问题; 
LCA问题可以在线性时间内规约为约束RMQ， 
也就是数列中任意两个相邻的数的差都是+1或-1的RMQ问题; 
约束RMQ有O(n)-O(1)的在线解法，故整个算法的时间复杂度为O(n)-O(1); 
 
height数组： 
定义height[i]=suffix(sa[i-1])和suffix(sa[i])的最长公共前缀， 
也就是排名相邻的两个后缀的最长公共前缀; 
 
那么对于j和k，不妨设Rank[j]<Rank[k],则有以下性质： 
suffix(j)和suffix(k)的最长公共前缀为: 
height[Rank[j]+1],height[Rank[j]+2],height[Rank[j]+3],…,height[Rank[k]]中的最小值; 

//mazicwong:
//后缀数组精髓,height[]
da: O(nlogn)
且da代码25行
*************************************************/  

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//Rank[i] 第i个后缀的排名;
//sa[i] 排名为i的后缀位置;
//height[i] 排名为i的后缀sa[i]与排名为(i-1)的后缀sa[i-1]的LCP(相邻排名最长公共前缀)

/*
 * suffix array
 * 倍增算法 O(n*logn)
 * 待排序数组长度为n,放在0~n-1中,在最后面补一个0
 * da(str,n+1,sa,Rank,height, , );//注意是n+1;
 * 例如:
 * n = 8;
 * i      =  { 0  1  2  3  4  5  6  7  8  };
 * num[]  =  { 1, 1, 2, 1, 1, 1, 1, 2, $  };注意num最后一位为0,其他大于0
 * Rank[] =  { 4, 6, 8, 1, 2, 3, 5, 7, 0  };Rank[0~n-1]为有效值,Rank[n]必定为0无效值
 * sa[]   =  { 8, 3, 4, 5, 0, 6, 1, 7, 2  };sa[1~n]为有效值,sa[0]必定为n是无效值(注意对应后缀数组下标是[0..n-1])
 * height[]= { 0, 0, 3, 2, 3, 1, 2, 0, 1  };height[2~n]为有效值
 * 
 *
 *
 * eg2:
 *
 *           a b c a b c
 *  r[]      1 2 3 1 2 3 0
 *  Rank[]   2 4 6 1 3 5 0
 *  sa[]     6 3 0 4 1 5 2
 *  height[] 0 0 3 0 2 0 1
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


char str[MAXN];//原串[0..n-1]
int r[MAXN];//转换为int串[0..n-1]

int main()//hdu4552 求所有前缀出现的次数之和
{
    while(scanf("%s",str)!=EOF)
    {
        int n=strlen(str);
        int len=n;
        for (int i=0;i<n;i++)
            r[i]=str[i]-'a'+1;
        r[n]=0;//记得最后一个放为0
        build_sa(r,n,28);//传入n就行,函数里有n++了,r数组中数的最大值小于m
        //以上都是套路

        
        //法1
        RMQ::init(len+1);
        int ans=n;
        //这里错了很久!!记得用len+1才是符合开始写的那些个条件
        for (int i=1;i<n;i++)
            ans = (ans+RMQ::lcp(0,i))%256;
        printf("%d\n",ans);
    }
    return 0;
}
