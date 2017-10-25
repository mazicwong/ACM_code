1. Trie: 多模板串建立字典用于查询(见数据结构模板)
2. KMP: 单模式串匹配问题    O(n+m)
3. AC自动机(trie+KMP): 多模式串匹配问题
4. 后缀数组: 最长公共前缀lcp
   倍增算法
5. manacher: 回文串匹配
在O(n)时间内,找到以每个字符为中心的最长回文串


////////////////////////////////////////////////////////////////////////////////
2. KMP   //O(m)预处理,O(n)匹配
// O(n+m)
T[]: 母串
P[]: 模式串
next[]: 除当前字符外的最长相同前缀后缀(位数要比P[]多一位,next[0]=-1)
next[j]=k: j之前的字符串中有最大长度为k的相同前缀后缀

kmp思想: 对模式串P预处理计算出next[]数组;查找时,i只扫一遍,当T[i]与P[j]失配时,P向右移动j-next[j],即j=next[j]
* 如果j=-1,或者当前字符匹配成功(即S[i]==P[j]),都令i++,j++,继续匹配下一个字符;
* 如果j!=-1,且当前字符匹配失败(即S[i] != P[j]),则令i不变,j=next[j]。
此举意味着失配时，模式串P相对于文本串S向右移动了j-next[j]位。

应用:
1.给定一个P串和一群不同的T串,问P串是那些串的子串(裸)
2.子串在母串中出现几次(kmp_count())
3.求循环节(hdu 3746)

注意:下面两套模板是可以混搭的,一套是自己总结的(容易理解),一套是kuangbin大神的(比赛敲起来块)
最好用1的.

char T[1000];//母串
char P[100];//模板串
int next[101];//[1..m]
void getNext()
{//next从1开始,字符串从0开始
    int pp = strlen(P);
    next[0]=-1;
    int k=-1,j=0;
    while(j<pp)
    {
        if (k==-1 || P[k]==P[j]) //P[k]前缀,P[j]后缀
        {
            j++;k++;
            /*
             * //优化版,出现P[j]=P[nxt[j]]时进行递归,k=nxt[k]=nxt[nxt[k]]
             * if (P[j]!=P[k]) nextval[j]=k;
             * else next[j]=nextval[k];
             */
            next[j]=k;
        }
        else k=next[k];//不等,左边就自己返回,(运用了kmp思想了)
    }
}

//返回P在T中首次出现的位置,从0开始
int kmp()
{
    int tt=strlen(T),pp=strlen(P);
    int i=0,j=0;
    while(i<tt && j<pp)
    {
        //如果j=-1，或者当前字符匹配成功（即T[i] == P[j]）,都令i++,j++
        if (j==-1 || T[i]==P[j]) i++,j++;
        //如果j!=-1，且当前字符匹配失败（即T[i] != P[j]）,则令i不变,j=next[j]
        else j=next[j];
    }
    if (j==pp) return i-j;
    else return -1;
}
//返回模式串P在主串T中出现的次数(可重叠)(法1:较慢)
int kmp_count()
{
    int tt=strlen(T),pp=strlen(P);
    int i=0,j=0;
    int ans=0;
    while(i<tt)
    {
        if (j==-1 || T[i]==P[j]) i++,j++;
        else j=nxt[j];
        if (j>=pp)
        {
            ans++;
            j=nxt[j];//不可重叠的话就把这里改为j=0;
        }
    }
    return ans;
}

/******************************KMP**************************/

/*************************扩展KMP****************************/
s[i]: 主串中以第i个位置为起始的后缀,(KMP:求s[i]=模式串长度 的情况)
next[i]:"模式串的后缀"和"模式串P"的最长公共前缀
extend[i]:"s[i]"与"模式串P"的最长公共前缀(用next[i]求)

扩展KMP思想: 给出模板串T和子串B，长度分别为lenT和lenB，要求在线性时间内，对于每个T[i]（0<=i<lenT)，求出T[i..lenT-1]与B的最长公共前缀长度，记为ex[i]（或者说，ex[i]为满足T[i..i+z-1]==T[0..z-1]的最大的z值）。

题型:
1.求一个字符串的最长回文子串和最长重复子串
2.求'主串的每一个后缀' 和 '模式串' 的最长公共前缀
void getNext(char *P)
{
    int a=0;
    int pp=strlen(P);
    next[0]=pp;
    while(a<pp-1 && P[a]==P[a+1]) a++;
    next[1]=a;
    a=1;
    for(int k=2;k<pp;k++)
    {
        int p=a+next[a]-1,L=next[k-a];
        if((k-1)+L>=p)
        {
            int j=(p-k+1)>0? p-k+1:0;
            while(k+j<pp && T[k+j]==T[j]) j++;
            next[k]=j;
            a=k;
        }
        else next[k]=L;
    }
}

void GetExtend(char *S,char *T)  
{  
    int a=0;
    getNext(T);
    int Slen=strlen(S);
    int Tlen=strlen(T);
    int MinLen=Slen<Tlen? Slen:Tlen;
    while(a<MinLen && S[a]==T[a]) a++;
    extend[0]=a;
    a=0;
    for(int k=1;k<Slen;k++) 
    {
        int p=a+extend[a]-1,L=next[k-a];
        if((k-1)+L>=p)
        {
            int j=(p-k+1)>0? p-k+1:0;
            while(k+j<Slen&&j<Tlen&&S[k+j]==T[j]) j++;
            extend[k]=j;
            a=k;
        }
        else extend[k]=L;
    }
}
/*************************扩展KMP****************************/


////////////////////////////////////////////////////////////////////////////////
3. AC自动机
/*
 * hdu2222 找所有单词在文章中出现多少个
 */
const int maxn = 500000+5;//50*10000
struct AC_auto{
    int chd[maxn][26]; //trie
    int v[maxn];       //节点属性值
    int f[maxn];       //失配指针
    int last[maxn],tot,ans;
    void init()
    {
        tot=1;ans=0;
        memset(v,0,sizeof(v));
        memset(f,0,sizeof(f));
        memset(chd[0],0,sizeof(chd[0]));
    }
    void insert(char *p)
    {
        int now=0;
        for(;*p;p++)
        {
            int id=*p-'a';
            if(chd[now][id]==0)
            {
                memset(chd[tot],0,sizeof(chd[tot]));
                chd[now][id]=tot++;
            }
            now=chd[now][id];
        }
        v[now]++; //标记结束的地方
    }
    bool query(char *p)
    {
        int now=0;
        for(;*p;p++)
        {
            int id=*p-'a';
            if (chd[now][id]==0) break;
            now=chd[now][id];
        }
        return v[now]&&(!(*p)); //走到末尾
    }
    int getFail()
    {
        queue<int> Q;
        f[0]=0;
        for(int c=0;c<26;c++)
        {
            int u=chd[0][c];
            if (u)
            {
                f[u]=0; Q.push(u); last[u]=0;
            }
        }
        while(!Q.empty())
        {
            int r=Q.front(); Q.pop();
            for(int c=0;c<26;c++)
            {
                int u=chd[r][c];
                if (!u) {chd[r][c]=chd[f[r]][c]; continue;}
                Q.push(u);
                int vv=f[r];
                while(vv && !chd[vv][c]) vv=f[vv];
                f[u]=chd[vv][c];
                last[u]=v[f[u]] ? f[u] : last[f[u]];
            }
        }
    }
    void solve(int j)
    {
        if (!j) return;
        if (v[j])
        {
            ans+=v[j];
            v[j]=0;
        }
        solve(last[j]);
    }
    void find(char *T)
    {
        int len=strlen(T);
        int now=0;
        getFail();
        for (int i=0;i<len;i++)
        {
            int id=T[i]-'a';
            now=chd[now][id];
            if (v[now]) solve(now);
            else if(last[now]) solve(last[now]);
        }
    }

}ac;

int main()
{
    freopen("in","r",stdin);
    char str[1000000+5];
    char ss[100];
    int n;
    int t;cin>>t;
    while(t--)
    {
        ac.init();
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",ss);
            ac.insert(ss);       //将所有模板串建立Trie树
        }
        scanf("%s",str);
        ac.find(str);            //
        printf("%d\n",ac.ans);   //单词出现个数;
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
4. 后缀数组
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
名次数组Rank： 
名次数组Rank[i]保存的是后缀i在所有后缀中从小到大排列的“名次”; 
后缀数组是"排第几的是谁",名次数组是"排第几",即后缀数组和名次数组为互逆运算; 
 
(1)倍增算法: 
用倍增的方法对每个字符开始的长度为2^k的子字符串进行排序，求出排名，即Rank值。 
k从0开始，每次加1，当2^k大于n以后，每个字符开始的长度为2^k的子字符串便相当于所有的后缀。 
并且这些子字符串都一定已经比较出大小，即Rank值中没有相同的值，那么此时的Rank值就是最后的结果。 
每一次排序都利用上次长度为2^k-1的字符串的Rank值， 
那么长度为2^k的字符串就可以用两个长度为2^k-1的字符串的排名作为关键字表示， 
然后进行基数排序，便得出了长度为2^k的字符串的Rank值。 
 
(2)DC3算法： 
①先将后缀分成两部分，然后对第一部分的后缀排序; 
②利用①的结果，对第二部分的后缀排序; 
③将①和②的结果合并，即完成对所有后缀排序; 
 
时间复杂度： 
倍增算法的时间复杂度为O(nlogn),DC3算法的时间复杂度为O(n); 
从常数上看，DC3算法的常数要比倍增算法大; 
 
空间复杂度： 
倍增算法和DC3算法的空间复杂度都是O(n); 
倍增算法所需数组总大小为6n,DC3算法所需数组总大小为10n; 
 
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
da: O(nlogn)   dc3: O(n)
但dc3常数更大,时间差不多;且da代码25行,dc3代码40行,所以一般写da
*************************************************/  

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
    //freopen("in","r",stdin);
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

////////////////////////////////////////////////////////////////////////////////
5. manacher
//计算字符串的最长回文字串 O(n)
/* hdu3068
 * manacher“马拉车”算法: 计算字符串的最长回文字串 O(n)
 *
 * 算法:每两个相邻字符中插入一个分隔符'#'
 * 新串下标从1开始
 *
 * 把奇偶长度的回文串同意考虑了
 * 为了避免更新P的时候导致越界，我们在字符串T的前增加一个特殊字符，
 *
 * 比如说‘$’,所以算法中字符串是从1开始的
*/

/*
  原串：       w   a   a   b   w   s   w   f   d
  新串：     # w # a # a # b # w # s # w # f # d #
辅助数组P：  1 2 1 2 3 2 1 2 1 2 1 4 1 2 1 2 1 2 1

P[id]: 记录以str[id]为中心的最长回文串
当以str[id]为第一个字符,这个最长回文串向右延伸了P[id]个字符
P[id]-1就是该回文子串在原串中的长度（包括‘#’）

参数说明:
str[i]:  存原串
Ma[i]:   存插入#扩展后的新串
Mp[i]:   
*/

const int MAXN=110010;
char Ma[MAXN*2];//新串,插入#后的
int Mp[MAXN*2]; //Mp[i]-1是Ma[i]所在的回文子串在原串的长度
void Manacher(char s[],int len)
{
    //计算Ma[0..2*len)   
    int l=0;
    Ma[l++]='$';//字符串开头增加一个特殊字符，防止越界
    Ma[l++]='#';
    for(int i=0;i<len;i++)
    {
        Ma[l++]=s[i];
        Ma[l++]='#';
    }
    Ma[l]=0;

    //计算Mp[0..2*len)
    int mx=0,id=0;//mx为当前计算回文串最右边字符的最大值
    for(int i=0;i<l;i++)
    {
        Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
        while(Ma[i+Mp[i]]==Ma[i-Mp[i]])Mp[i]++;
        if(i+Mp[i]>mx)
        {
            mx=i+Mp[i];
            id=i;
        }
    }
}
 /*
  *
  * * abaaba
  * * i:     0 1 2 3 4 5 6 7 8 9 10 11 12 13
  * * Ma[i]: $ # a # b # a # a # b  #  a  #
  * * Mp[i]: 1 1 2 1 4 1 2 7 2 1 4  1  2  1
  * */
char str[MAXN];
int main()
{
    //freopen("in","r",stdin);
    while(scanf("%s",str)!=EOF)
    {
        int len=strlen(str);
        Manacher(str,len);
        int ans=0;
        for(int i=0;i<2*len+2;i++)
            ans=max(ans,Mp[i]-1);
        printf("%d\n",ans);
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////////


