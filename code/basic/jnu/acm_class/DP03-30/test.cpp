//////////////////////////////////////////////////数组/////////////////////////////////////////
//在讲述DP算法的时候，一个经典的例子就是数塔问题
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int dp[maxn][maxn];
int main()
{
    int t;cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        int n;cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                cin>>dp[i][j];
        for(int i=n;i>=1;i--)
            for(int j=1;j<=i;j++)
                dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + dp[i][j];
        cout<<dp[1][1]<<endl;
    }
    return 0;
}

***********************************************************************************************
//The famous ACM (Advanced Computer Maker) Company has rented a floor
#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int s[maxn];
int t[maxn];
int cnt[maxn];
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int st,en;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)
        {
            cin>>st>>en;
            st = (st+1)>>1;
            en = (en+1)>>1;
            if(st>en) swap(st,en);
            for(int k=st;k<=en;k++)
                cnt[k]++;
        }
        int ans=-1;
        for(int i=1;i<=200;i++)
            ans = max(ans,cnt[i]);
        cout << ans*10 << endl;
    }
    return 0;
}



***********************************************************************************************
//Nowadays, a kind of chess game called “Super Jumping! Jumping! Jumping
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
long long a[maxn];
int n;
//LIS
long long dp[maxn];
int main()
{
    while(cin>>n && n)
    {
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) cin>>a[i], dp[i]=a[i];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[i] > a[j]) dp[i]=max(dp[i],dp[j]+a[i]);
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++) ans=max(ans,dp[i]);
        cout << ans << endl;
    }
    return 0;
}



***********************************************************************************************
//Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
int dp[maxn];
typedef long long ll;
//zuidazichuanheasdf
int len[maxn];
int main()
{
    int T; cin>>T;
    for(int cas=1;cas<=T;cas++)
    {
        int n;cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i],dp[i]=a[i];
        memset(len,0,sizeof(len));

        for(int i=2;i<=n;i++)
        {
            if(dp[i-1]>=0) dp[i] = dp[i-1]+a[i], len[i]=len[i-1]+1;
            else dp[i] = a[i], len[i]=0;
        }
        int ans = -0x3f3f3f3f;
        for(int i=1;i<=n;i++)
            ans = max(ans,dp[i]);
        cout << "Case " << cas << ":\n";
        for(int i=1;i<=n;i++)
        {
            if(ans == dp[i])
            {
                cout << ans << ' ' << i-len[i] << ' ' << i << endl;
                break;
            }
        }
        if(cas!=T) cout << endl;
    }
    return 0;
}



***********************************************************************************************
//“今年暑假不AC？”
//hdu2037
#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 105;
struct Node{
    int st,en;
}node[maxn];
bool cmp(const Node a, const Node b)
{
    return a.en<b.en;
}
int main()
{
    while(cin>>n && n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>node[i].st>>node[i].en;
        }
        sort(node,node+n,cmp);
        int now=node[0].en;
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(node[i].st>=now)
            {
                now=node[i].en;
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}




//////////////////////////////////////////////////DP/////////////////////////////////////////
//Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence
#include <bits/stdc++.h>
using namespace std;
//zuida zichuan he
const int maxn = 100000+5;
int dp[maxn];
int len[maxn];
int a[maxn];
int main()
{
    int t;cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        memset(len,0,sizeof(len));
        memset(dp,0,sizeof(dp));
        int n;cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i],dp[i]=a[i];
        for(int i=2;i<=n;i++)
        {
            if(dp[i-1]>=0)
                dp[i]=dp[i-1]+a[i], len[i]=len[i-1]+1;
            else dp[i]=a[i], len[i]=0;
        }
        int ans=-0x3f3f3f3f;
        for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
        cout<<"Case "<<cas<<":\n";
        for(int i=1;i<=n;i++){
            if(ans==dp[i])
            {
                cout<<ans<<' '<<i-len[i]<<' '<<i<<endl;
            }
        }
        if(cas!=t) cout<<endl;
    }
    return 0;
}



***********************************************************************************************
//FatMouse believes that the fatter a mouse is, the faster it runs. To disprove this, you want to take the data on a collection of mice and put as large a subset of this data as possible into a sequence so that the weights are increasing, but the speeds are decreasing. 
//hdu1160
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std ;  

#define maxn 2000

struct node {
    int w , s ; 
    int index ; //最初的序号，避免排序后乱掉顺序
};
node num[maxn] ; 
int pre[maxn] ; //记录i对应的上一个数据
int dp[maxn] ; //dp[i]表示以第i个数据结尾的符合要求的子列长度
int res[maxn+10];//存放最终结果下标
// 用res数组输出结果  或者函数递归输出 
int maxi ; 
int maxlen ; 

bool cmp(node a , node b){
    //重量递增排序 ， 重量相等 速度递减排序 
    if(a.w < b.w) return true ; 
    else if(a.w == b.w ) return a.s > b.s ; 
    else return false ;  
}

void print(int i){
     
    if(i == 0 ){
        return;
    }
    print(pre[i]) ; 
    printf("%d\n" , num[i].index ) ; 
}
int main(){
    
    int i=1 ; 
    while(~scanf("%d %d" , &num[i].w , &num[i].s)){
        dp[i] = 1 ; 
        pre[i] = 0 ; 
        num[i].index = i ; 
        ++ i ; 
    }
    maxlen = 0 ; //最长序列长度
    int n = i - 1 ; 
    sort(num + 1 , num + n + 1 , cmp) ; 
    
    dp[1] = 1 ; 
    for(int i=1 ; i<= n ; i++){
        for(int j=1 ; j<i ; j++){
            if(num[i].w>num[j].w && num[i].s < num[j].s&&dp[j]+1>dp[i]){
                dp[i] = dp[j] + 1 ; 
                pre[i] = j ; 
                if(dp[i] > maxlen){
                    maxi = i ; //最长序列的最后一个数下标
                    maxlen = dp[i] ; 
                }
            }
        }
    }
    printf("%d\n" , maxlen) ; 
    print(maxi) ; 
    return  0 ; 
}



***********************************************************************************************
//Nowadays, a kind of chess game called “Super Jumping! Jumping! Jumping!”
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
long long a[maxn];
int n;
//LIS
long long dp[maxn];
int main()
{
    while(cin>>n && n)
    {
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) cin>>a[i], dp[i]=a[i];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[i] > a[j]) dp[i]=max(dp[i],dp[j]+a[i]);
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++) ans=max(ans,dp[i]);
        cout << ans << endl;
    }
    return 0;
}




***********************************************************************************************
//在讲述DP算法的时候，一个经典的例子就是数塔问题，它是这样描述的：
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int dp[maxn][maxn];
int main()
{
    int t;cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        int n;cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                cin>>dp[i][j];
        for(int i=n;i>=1;i--)
            for(int j=1;j<=i;j++)
                dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + dp[i][j];
        cout<<dp[1][1]<<endl;
    }
    return 0;
}


***********************************************************************************************
//A subsequence of a given sequence is the given sequence with some elements (possible none) left out. Given a sequence X = <x1, x2
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[1005],b[1005];
int dp[1005][1005];
int main()
{
    while(cin>>a>>b)
{
    int len1=strlen(a);
    int len2=strlen(b);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=len1;i++)
    for(int j=1;j<=len2;j++)
    {
        if(a[i-1]==b[j-1])
        dp[i][j]=dp[i-1][j-1]+1;
        else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]); //传递最大值
    }
    cout<<dp[len1][len2]<<endl;
}
    return 0;
}



***********************************************************************************************
//都说天上不会掉馅饼，但有一天gameboy正走在回家的小径上，忽然天上掉下大把大把的馅饼。说来gameboy的人品实在是太好了，这馅饼别处
#include<bits/stdc++.h>
using namespace std;
int a[100001][12];
int f[100001][12];
int main(){
	int n;
	while(scanf("%d", &n) != EOF && n){
		memset(a, 0, sizeof(a));
		memset(f, 0, sizeof(f));
		int x, T, i, j, maxT = 0, ans = 0;
		while(n--){
			scanf("%d%d", &x, &T);
			++a[T][x];
			maxT = max(maxT, T);
		}
		f[1][4] = a[1][4];
		f[1][5] = a[1][5];
		f[1][6] = a[1][6];
		for(i = 2; i <= maxT; ++i){
			for(j = 0; j < 11; ++j){
				f[i][j] = f[i - 1][j];
				if(j > 0)
					f[i][j] = max(f[i][j], f[i - 1][j - 1]);
				if(j < 10)
					f[i][j] = max(f[i][j], f[i - 1][j + 1]);
				f[i][j] += a[i][j];
				//printf("%d ", f[i][j]);
			}
			//printf("\n");
		}
		for(i = 0; i < 11; ++i)
				ans = max(ans, f[maxT][i]);
		printf("%d\n", ans);
	}
	return 0;
}


***********************************************************************************************
//A number whose only prime factors are 2,3,5 or 7 is called a humble number. The sequence 1, 2, 3
//hdu1058
#include<iostream>    
#include<string.h>  
#include<algorithm>    
  
using namespace std;  
  
int a[6000];  
  
int main()  
{  
    a[1] = 1;  
    int i2, i3, i5, i7;  
    i2 = i3 = i5 = i7 = 1;  
  
    for (int i = 2; i <= 5842; i++)  
    {  
        int x = min(min(a[i2] * 2, a[i3] * 3), min(a[i5] * 5, a[i7] * 7));  
  
        if (x == a[i2] * 2) i2++;//这个地方不能用if...else语句，因为四个数的比较可能存在相等的  
        if (x == a[i3] * 3) i3++;  
        if (x == a[i5] * 5) i5++;  
        if (x == a[i7] * 7) i7++;  
  
        a[i] = x;  
    }  
  
    int n;  
  
    while (scanf("%d", &n) && n)  
    {  
        if (n % 10 == 1 && n % 100 != 11)  
            printf("The %dst humble number is ", n);  
        else if (n % 10 == 2 && n % 100 != 12)  
            printf("The %dnd humble number is ", n);  
        else if (n % 10 == 3 && n % 100 != 13)  
            printf("The %drd humble number is ", n);  
        else  
            printf("The %dth humble number is ", n);  
  
        printf("%d.\n", a[n]);  
  
    }  
      
    return 0;  
}  


***********************************************************************************************
//A group of researchers are designing an experiment to test the IQ of a monkey. They will hang a banana at the 
//hdu1069
#include<iostream>  
#include<cstdio>  
#include<algorithm>  
using namespace std;  
const int MAX = 200;  
struct ss  
{  
    int x, y ,z;  
    int maxhight;  
}block[MAX];  
bool cmp(ss a, ss b)  
{  
    if(a.x == b.x) return a.y < b.y;  
    else return a.x < b.x;  
}  
int N, x, y, z, ans, cnt, kase = 1;  
int main()  
{  
    while(scanf("%d", &N) != EOF && N)  
    {  
        cnt = ans = 0;  
        for(int i = 0;i < N; ++i)  
        {  
            scanf("%d %d %d", &x, &y, &z);  
            block[cnt].x = x;block[cnt].y = y;block[cnt].z = z;block[cnt].maxhight = block[cnt].z;cnt++;  
            block[cnt].x = y;block[cnt].y = z;block[cnt].z = x;block[cnt].maxhight = block[cnt].z;cnt++;  
            block[cnt].x = z;block[cnt].y = x;block[cnt].z = y;block[cnt].maxhight = block[cnt].z;cnt++;  
            block[cnt].x = x;block[cnt].y = z;block[cnt].z = y;block[cnt].maxhight = block[cnt].z;cnt++;  
            block[cnt].x = y;block[cnt].y = x;block[cnt].z = z;block[cnt].maxhight = block[cnt].z;cnt++;  
            block[cnt].x = z;block[cnt].y = y;block[cnt].z = x;block[cnt].maxhight = block[cnt].z;cnt++;  
        }  
        sort(block, block+cnt, cmp);  
        for(int i = 1;i < cnt; ++i)  
        {  
            for(int j = 0;j < i; ++j)  
            {  
                if(block[i].x > block[j].x && block[i].y > block[j].y)  
                {  
                    block[i].maxhight = max(block[i].maxhight, block[j].maxhight+block[i].z);  
                }  
            }  
            ans = max(ans, block[i].maxhight);  
        }  
        printf("Case %d: maximum height = %d\n", kase++, ans);  
    }  
    return 0;  
}  



***********************************************************************************************
//自从见识了平安夜苹果的涨价后，Lele就在他家门口水平种了一排苹果树，共有N棵。
//hdu2151
#include<cstdio>  
#include<cstring>  
int main()  
{  
    int n,p,m,t,i,j,dp[105][105];  
    while(~scanf("%d%d%d%d",&n,&p,&m,&t))  
    {  
        memset(dp,0,sizeof(dp));  
        dp[0][p]=1;  
        for(i=1;i<=m;i++)  
            for(j=1;j<=n;j++)  
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];  
                printf("%d\n",dp[m][t]);      
    }  
    return 0;  
 }   



***********************************************************************************************
//据说在很久很久以前，可怜的兔子经历了人生中最大的打击——赛跑输给乌龟后，心中郁闷，发誓要报仇雪恨，于是
//hdu2059
#include <cstdio>  
#include <cmath>  
#include <cstring>  
#include <queue>  
#include <stack>  
#include <algorithm>  
using namespace std;  
#define INF 0x3f3f3f3f  
double a[110];  
double dp[110];  
int main()  
{  
    double l,d,T;  
    int n;  
    double vtu,vguikuai,vguiman;  
    while(scanf("%lf",&l)!=EOF)  
    {  
        scanf("%d%lf%lf",&n,&d,&T);  
        scanf("%lf%lf%lf",&vtu,&vguikuai,&vguiman);  
        for(int i=1;i<=n;i++)  
        {  
            scanf("%lf",&a[i]);  
        }  
        a[0]=0;  
        a[n+1]=l;//终点当做加油站   
        dp[0]=0;  
        for(int i=1;i<=n+1;i++)  
        {  
            dp[i]=INF;  
            for(int j=0;j<i;j++)//从j充电站充好电后到达第i个充电站所用的最短时间   
            {  
                double time=0;  
                if(a[i]-a[j]>d)//从j不能直接快速的跑到i   
                {  
                    time=time+d/vguikuai+(a[i]-a[j]-d)/vguiman;  
                }  
                else  
                {  
                    time=time+(a[i]-a[j])/vguikuai;  
                }  
                if(j>0)//在j要充电出发   
                {  
                    time=time+T;  
                }  
                dp[i]=min(dp[i],dp[j]+time);  
            }  
        }  
        double tutime=l/vtu;  
        double guitime=dp[n+1];  
        if(tutime<guitime)  
        {  
            printf("Good job,rabbit!\n");  
        }  
        else  
        {  
            printf("What a pity rabbit!\n");  
        }  
    }  
    return 0;  
}


***********************************************************************************************
//You, the leader of Starship Troopers, are sent to destroy a base of the bugs. The base is built
//hdu1011

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

const int MAXN=110;
struct Node
{
    int to;
    int next;
}edge[MAXN*2];
int tol;
int head[MAXN];
int bug[MAXN];
int bra[MAXN];
int n,m;
int dp[MAXN][MAXN];
void init()
{
    memset(head,-1,sizeof(head));
    memset(dp,0,sizeof(dp));
    tol=0;
}

void add_edge(int a,int b)
{
    edge[tol].to=b;
    edge[tol].next=head[a];
    head[a]=tol++;
    edge[tol].to=a;
    edge[tol].next=head[b];
    head[b]=tol++;
}

void dfs(int u,int p)
{
    int temp=(bug[u]+19)/20;
    for(int i=temp;i<=m;i++)
       dp[u][i]=bra[u];
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==p)continue;
        dfs(v,u);
        for(int j=m;j>=temp;j--)//一定要倒序
          for(int k=1;k+j<=m;k++)
            dp[u][j+k]=max(dp[u][j+k],dp[u][j]+dp[v][k]);
    }
}
int main()
{
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int a,b;
    while(scanf("%d%d",&n,&m))
    {
        init();
        if(n==-1&&m==-1)break;
        for(int i=1;i<=n;i++)
          scanf("%d%d",&bug[i],&bra[i]);
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            add_edge(a,b);
        }
        if(m==0)
        {
            printf("0\n");
            continue;
        }
        dfs(1,-1);
        printf("%d\n",dp[1][m]);

    }
    return 0;
}


***********************************************************************************************
//Now I think you have got an AC in Ignatius.L's "Max Sum" problem. To be a brave ACMer,
//hdu1024

#include <iostream>  
#include <cstdio>  
#include <cstring>  
  
using namespace std;  
  
#define N 1000000  
#define INF 0x7fffffff  
  
int a[N+10];  
int dp[N+10],Max[N+10];//max( dp[i-1][k] ) 就是上一组 0....j-1 的最大值。  
  
int main()  
{  
    int n,m,mmax;  
    while (~scanf("%d%d",&m,&n))  
    {  
        for (int i=1;i<=n;i++)  
        {  
            scanf("%d",&a[i]);  
        }  
        memset(dp,0,sizeof(dp));  
        memset(Max,0,sizeof(Max));  
        for (int i=1;i<=m;i++)//分成几组  
        {  
            mmax=-INF;  
            for (int j=i;j<=n;j++)//j个数分成i组，至少要有i个数  
            {  
                dp[j]=max(dp[j-1]+a[j],Max[j-1]+a[j]);  
                Max[j-1]=mmax;  
                mmax=max(mmax,dp[j]);  
            }  
        }  
        printf ("%d\n",mmax);  
    }  
    return 0;  
}  


***********************************************************************************************
//You probably know those quizzes in Sunday magazines: given the sequence 1, 2, 3, 4, 5, what is the next number
//hdu1121
#include<stdio.h>  
#define NN 102  
int main(){  
    int T, i, j, S, C;  
    int f[NN][NN];  
    scanf("%d", &T);  
    while (T--){  
        scanf("%d%d", &S, &C);  
        for (i = 0; i < S; i++)//输入数列  
            scanf("%d", &f[0][i]);  
        for (i = 1; i < S; i++)  
            for (j = 0; i + j < S; j++)  
                f[i][j] = f[i - 1][j + 1] - f[i - 1][j];  
        for (i = 1; i <= C; i++)  
            f[S - 1][i] = f[S - 1][0];  
        for (i = S - 2; i >= 0; i--)  
            for (j = S - i; j < C + S; j++)  
                f[i][j] = f[i][j - 1] + f[i + 1][j - 1];  
        for (i = S; i < S + C - 1; i++)  
            printf("%d ", f[0][i]);  
        printf("%d\n", f[0][i]);  
    }  
    return 0;  
}  



***********************************************************************************************
//hdu1121
#include<stdio.h>  
#define NN 102  
int main(){  
    int T, i, j, S, C;  
    int f[NN][NN];  
    scanf("%d", &T);  
    while (T--){  
        scanf("%d%d", &S, &C);  
        for (i = 0; i < S; i++)//输入数列  
            scanf("%d", &f[0][i]);  
        for (i = 1; i < S; i++)  
            for (j = 0; i + j < S; j++)  
                f[i][j] = f[i - 1][j + 1] - f[i - 1][j];  
        for (i = 1; i <= C; i++)  
            f[S - 1][i] = f[S - 1][0];  
        for (i = S - 2; i >= 0; i--)  
            for (j = S - i; j < C + S; j++)  
                f[i][j] = f[i][j - 1] + f[i + 1][j - 1];  
        for (i = S; i < S + C - 1; i++)  
            printf("%d ", f[0][i]);  
        printf("%d\n", f[0][i]);  
    }  
    return 0;  
}  



***********************************************************************************************
//Squares and rectangles fascinated the famous Dutch painter Piet Mondriaan. One night, after producing t
//poj2411
#include<iostream>
#include<string.h> 
using namespace std;
long long  f[12][1<<12];//fullfil level i,the imfactto sta   ; target f[m][0];
int n,m;
int num=0;
int F1[1<<23];
int F2[1<<23];
void dfs(int i,int fromm,int too)
{
    if(i>n) return;
    if(i==n)   
    {   
    num++;  
    F1[num]=fromm;
    F2[num]=too;    
    }
    dfs(i+1,(fromm<<1)+1,too<<1);
    dfs(i+1,fromm<<1,(too<<1)+1);
    dfs(i+2,fromm<<2,too<<2);
}
int main()
{
    while(cin>>n>>m)
    {  
    if(n==0&&m==0)
    return 0;
    num=0;
    memset(f,0,sizeof(f));

    f[0][0]=1;
    dfs(0,0,0);
    for(int i=0;i<=m-1;i++)
      for(int j=1;j<=num;j++)
          {
            f[i+1][F2[j]]+=f[i][F1[j]];
          }


   cout<<f[m][0]<<endl;

    }
}


***********************************************************************************************
//This is a problem from ZOJ 2432.To make it easyer,you just need output the length of the subsequence
//hdu1423
#include <stdio.h>  
#include <string.h>  
  
#define MAX 501  
  
int T;  
int seq1[MAX], seq2[MAX];  
int len1, len2;  
int dp[MAX];  
  
int LCIS(){  
    int i, j;  
    int Max;  
    memset(dp, 0, sizeof(dp));  
    for (i = 1; i <= len1; ++i){  
        Max = 0;  
        for (j = 1; j <= len2; ++j){  
            if (seq1[i] > seq2[j] && Max < dp[j])  
                Max = dp[j];  
            if (seq1[i] == seq2[j])  
                dp[j] = Max + 1;  
        }  
    }  
    Max = 0;  
    for (i = 1; i <= len2; ++i){  
        if (Max < dp[i])  
            Max = dp[i];  
    }  
    return Max;  
}  
  
int main(void){  
    int i;  
    scanf("%d", &T);  
    while (T-- != 0){  
        scanf("%d", &len1);  
        for (i = 1; i <= len1; ++i)  
            scanf("%d", &seq1[i]);  
        scanf("%d", &len2);  
        for (i = 1; i <= len2; ++i)  
            scanf("%d", &seq2[i]);  
        printf("%d\n", LCIS());  
        if (T)  
            putchar('\n');  
    }  
  
    return 0;  
}


***********************************************************************************************
//A histogram is a polygon composed of a sequence of rectangles aligned at a common base line. The rectangles have equal widths but may have different heights.
//hdu1506
#include<cstdio>  
#include<iostream>  
using namespace std;  
typedef long long ll;  
ll a[100005],Left[100005],Right[100005];  
ll Max;  
int main()  
{  
    int t;  
    int n;  
    while(cin>>n,n)  
    {  
        for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);  
        Left[1]=1;  
        Right[n]=n;  
        //求每个点左边连续比它大的最左边的下标，保存在Left[]数组里  
        for(int i=2;i<=n;i++)  
        {  
            t=i;  
            while(t>1 && a[i]<=a[t-1]) t=Left[t-1];  
            Left[i]=t;  
        }  
        //求每个点右边连续比它大的最右边的下标，保存在Right[]数组里  
        for(int i=n-1;i>=1;--i)  
        {  
            t=i;  
            while(t<n && a[i]<=a[t+1]) t=Right[t+1];  
            Right[i]=t;  
        }  
        Max=0;  
        for(int i=1;i<=n;i++)  
        {  
            if((Right[i]-Left[i]+1)*a[i]>Max) Max=(Right[i]-Left[i]+1)*a[i];  
        }  
        cout<<Max<<endl;  
    }  
    return 0;  
}  


***********************************************************************************************
//String Distance is a non-negative integer that measures the distance between two strings. Here we give the definition. A transform list is a list of string, where each string
//hdu1516
#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
  
const int maxn = 85;  
char A[maxn],B[maxn];  
int dp[maxn][maxn],len1,len2;  
  
void path()  
{  
    int tmp, i = len1, j = len2;  
    int step = 0;  
    while(i >= 1 || j >= 1)  
    {  
        if(A[i-1] == B[j-1]) tmp = 0;  
        else tmp = 1;  
        if(dp[i][j] == dp[i-1][j-1] + tmp && i >= 1 && j >= 1)  
        {  
            if(tmp)  
                printf("%d Replace %d,%c\n",++step,i,B[j-1]);  
            i--, j--;  
        }  
        else if(dp[i][j] == dp[i-1][j] + 1 && i >= 1)  
        {  
            printf("%d Delete %d\n",++step,i);  
            i--;  
        }  
        else if(dp[i][j] == dp[i][j-1] + 1 && j >= 1)  
        {  
            printf("%d Insert %d,%c\n",++step,i+1,B[j-1]);  
            j--;  
        }  
    }  
}  
  
int main()  
{  
    while(scanf("%s %s",A,B)!=EOF)  
    {  
        getchar();  
        len1 = strlen(A);  
        len2 = strlen(B);  
        memset(dp,0,sizeof(dp));  
        for(int i = 0; i <= len1; i++)  
            dp[i][0] = i;  
        for(int i = 0; i <= len2; i++)  
            dp[0][i] = i;  
        for(int i = 1; i <= len1; i++)  
            for(int j = 1; j <= len2; j++)  
            {  
                int tmp = min(dp[i][j-1],dp[i-1][j]) + 1;  
                int d = A[i-1] == B[j-1] ? 0 : 1;  
                dp[i][j] = min(tmp,dp[i-1][j-1]+d);  
            }  
        printf("%d\n",dp[len1][len2]);  
        path();  
    }  
    return 0;  
}  


***********************************************************************************************
//劲乐团是这样一个游戏：当游戏开始时，一边播放背景音乐，一边从上至下不断随着音乐掉落Note。（Note是
//hdu1206



***********************************************************************************************
//Consider a code string S of N symbols, each symbol can only be 0 or 1. In any consecutive substring of S, the number of 0's differs from the number of 1's by at most K. How many such valid code strings S are there? 
//hdu1545
#include<cstdio>  
#include<cstring>  
#define ll __int64  
const int W=5;  
int n,k;  
int max(int a,int b){return a>b?a:b;}  
int min(int a,int b){return a<b?a:b;}  
ll dp[63][10][10];  
int main(){  
    int i,j,p;  
    while(~scanf("%d%d",&n,&k)){  
        memset(dp,0,sizeof(dp));  
        dp[0][W][W]=1;  
        for(i=0;i<n;i++){  
            for(j=-k+W;j<=W;j++)for(p=W;p<=k+W;p++){  
                dp[i+1][min(j+1,W)][p+1]+=dp[i][j][p];  
                dp[i+1][j-1][max(p-1,W)]+=dp[i][j][p];  
            }  
        }  
        ll ans=0;  
        for(i=-k+W;i<=W;i++)for(j=W;j<=k+W;j++)ans+=dp[n][i][j];  
        printf("%I64d\n",ans);  
    }  
    return 0;  
}  


***********************************************************************************************
//It is well known that a human gene can be considered as a sequence, consisting of four nucleotides, which are simply denoted by four letters, A, C, G, and T. Biologists have been interested in identifying human genes and determining their functions, because these can be used to diagnose human diseases and to design new drugs for them. 
//hdu1080
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define max(a,b) a>b?a:b
#define INF 100000
using namespace std;
int v[5][5]={{0,-3,-4,-2,-1},{-3,5,-1,-2,-1},{-4,-1,5,-3,-2},{-2,-2,-3,5,-2},{-1,-1,-2,-2,5}};
int dp[105][105];
int s1[105],s2[1059];

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int q=1;q<=n;q++){
            memset(s1,0,sizeof(s1));
            memset(s2,0,sizeof(s2));
            int l1,l2;
            scanf("%d",&l1);
            int i,j;
            getchar();
            char a;
            dp[0][0]=0;
            for(i=1;i<=l1;i++){
                a=getchar();
                if(a=='A') s1[i]=1;
                else if(a=='C') s1[i]=2;
                else if(a=='G') s1[i]=3;
                else if(a=='T') s1[i]=4;
                dp[i][0]=dp[i-1][0]+v[s1[i]][0];
            }
            scanf("%d",&l2);
            getchar();
            for(i=1;i<=l2;i++){
                a=getchar();
                if(a=='A') s2[i]=1;
                else if(a=='C') s2[i]=2;
                else if(a=='G') s2[i]=3;
                else if(a=='T') s2[i]=4;
                dp[0][i]=dp[0][i-1]+v[0][s2[i]];
            }
            int k;
/*
            printf("s1:");
            for(i=1;i<=l1;i++)printf("%d",s1[i]);
            printf("\n");
            printf("s2:");
            for(i=1;i<=l2;i++)printf("%d",s2[i]);
            printf("\n");
*/
            for(i=1;i<=l1;i++){
                for(j=1;j<=l2;j++){
                    dp[i][j]=-INF;
                    dp[i][j]=max(dp[i][j],dp[i-1][j]+v[s1[i]][0]);
                    dp[i][j]=max(dp[i][j],dp[i][j-1]+v[0][s2[j]]);
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+v[s1[i]][s2[j]]);
                }
            }
            printf("%d\n",dp[l1][l2]);
        }
    }
    return 0;
}


***********************************************************************************************
//给定一个由n个正整数组成的整数序列
//a1 a2 a3 ... an
//求按先后次序在其中取m段长度分别为l1、l2、l3...lm的不交叠的连续整数的和的最大值。
#include<iostream>
using namespace std;

int n, m;
int list[1001], sum[1001], maxx[1001], len[20], sumlen[20];

int main()
{
	while (cin >> n)
	{
		if (n == 0)break;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> len[i];
			sumlen[i] = len[i];
			if (i)sumlen[i] += sumlen[i - 1];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> list[i];
			sum[i] = list[i];
			if (i)sum[i] += sum[i - 1];
		}
		for (int i = 0; i < n; i++)maxx[i] = 0;
		maxx[0] = sum[len[0] - 1];
		for (int j = 1; j <= n - len[0]; j++)
		{
			maxx[j] = sum[j + len[0] - 1] - sum[j - 1];
			if (maxx[j] < maxx[j - 1])maxx[j] = maxx[j - 1];
		}
		for (int i = 1; i < m; i++)
		{
			for (int j = n - len[i]; j >= sumlen[i - 1]; j--)
			maxx[j] = sum[j + len[i] - 1] - sum[j - 1] + maxx[j - len[i - 1]];
			for (int j = 1; j <= n - len[i]; j++)
			if (maxx[j] < maxx[j - 1])maxx[j] = maxx[j - 1];
		}
		if (n >= len[m - 1])cout << maxx[n - len[m - 1]] << endl;
		else cout << 0 << endl;
	}
	return 0;
}



//////////////////////////////////////////////////贪心+DP+搜索/////////////////////////////////////////
//FatMouse prepared M pounds of cat food, ready to trade with the cats guarding the warehouse containing his favorite food
//hdu 1009
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int MAXN = 1010;
struct node
{
    double j,f;
    double r;
}a[MAXN];
/*
int cmp(const void *a,const void *b)//从大到小排序 
{
    struct node *c=(node *)a;
    struct node *d=(node *)b;
    if(c->r > d->r) return -1;
    else return 1;
}    */
bool cmp(node a,node b)
{
    return a.r  >  b.r;
}    
int main()
{
    int N;
    double M;
    double ans;
    while(scanf("%lf%d",&M,&N))
    {
        if(M==-1&&N==-1) break;
        for(int i=0;i<N;i++)
        {
           scanf("%lf%lf",&a[i].j,&a[i].f);
           a[i].r=(double)a[i].j/a[i].f;
        }    
        //qsort(a,N,sizeof(a[0]),cmp);
        sort(a,a+N,cmp);
        ans=0;
        for(int i=0;i<N;i++)
        {
            if(M>=a[i].f)
            {
                ans+=a[i].j;
                M-=a[i].f;
            }    
            else 
            {
                ans+=(a[i].j/a[i].f)*M;
                break;
            }    
        }   
        printf("%.3lf\n",ans); 
    }    
    return 0;
}    


***********************************************************************************************
//Here is a famous story in Chinese history.
"That was about 2300 years ago. General Tian Ji was a high official in the country Qi. He likes to play horse racing with the king and others."
"Both of Tian and the king have three horses in different classes, namely, regular, plus, and super. The rule is to have three rounds in a match; each of the horses must be used in one round. The winner of a single round takes two hundred silver dollars from the loser."
//hdu1052

#include<cstdio>  
#include<cstring>  
#include<cctype>  
#include<algorithm>  
using namespace std;  
  
const int maxn=1e3;  
int a[maxn+10],b[maxn+10];  
  
int getin()  
{  
  int ans=0;char tmp;  
  while(!isdigit(tmp=getchar()));  
  do ans=(ans<<3)+(ans<<1)+tmp-'0';  
  while(isdigit(tmp=getchar()));  
  return ans;  
}  
  
int main()  
{  
  int n,i,j,ans,la,ra,lb,rb;  
  while(n=getin(),n)  
    {  
      for(i=1;i<=n;i++)a[i]=getin();  
      for(i=1;i<=n;i++)b[i]=getin();  
      sort(a+1,a+n+1);  
      sort(b+1,b+n+1);  
        
      la=lb=1,ra=rb=n,ans=0;  
      while(la<=ra)  
        if(a[ra]==b[rb])  
          {  
            while(la<=ra && a[la]>b[lb])  
              ans++,la++,lb++;  
            if(la>ra)break;  
            ans-=(a[la]<b[rb])?1:0;  
            la++,rb--;        
          }  
        else  
          {  
            if(a[ra]>b[rb])ans++,ra--,rb--;  
            else ans--,la++,rb--;  
          }  
      printf("%d\n",ans*200);    
    }  
  return 0;  
}  



***********************************************************************************************
//A subsequence of a given sequence is the given sequence with some elements (possible none) left out. Given a sequence X = <x1, x2, ..., xm> another sequence Z = <z1, z2, ..., zk> is a subsequence of X if
//hdu1159
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char a[1111],b[1111];
int dp[1111][1111];//最长公共子序列长度，下标为序列ab的长度
int main()
{
    int la,lb,i,j;
    while(scanf("%s%s",a,b)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        la=strlen(a);
        lb=strlen(b);
        for(i=1;i<=la;i++)
        {
            for(j=1;j<=lb;j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("%d\n",dp[la][lb]);
    }
    return 0;
}


***********************************************************************************************
//Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence. For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.
//hdu1003
#include <stdio.h>      //动态规划 
int main()
{
    int n,T,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&T);
        int sum=0,k=1,end=1,start=1;     //用k表示每次最大和的开始  
        int Max=-1001;                   
        for(int j=1;j<=T;j++)
        {
            scanf("%d",&m);
            sum+=m; 
            if(sum>Max)
            {
                Max=sum;
                start=k;
                end=j;
            }
            if(sum<0)
            {
                sum=0;
                k=j+1;
            }
        }
        if(i!=1)printf("\n");  //格式的控制！！！ 
        printf("Case %d:\n",i);
        printf("%d %d %d\n",Max,start,end);

    }
    return 0;
 } 



***********************************************************************************************
//You are given a number of case-sensitive strings of alphabetic characters, find the largest string X, such that either X, or its inverse can be found as a substring of any of the given strings.
//hdu1238
#include<stdio.h>  
#include<string.h>  
char str[100][101];  
int n;  
int searchMaxSubString(char *source)  
{  
    int i, j, subStrLen,sourceStrLen;  
        int foundMaxSubStr;  
    char subStr[101], revSubStr[101];  
    subStrLen= sourceStrLen=strlen(source) ;  
    while ( subStrLen > 0 )  
    {                                                                    //搜索不同长度的子串，从最长的子串开始搜索  
        for (i = 0; i <= sourceStrLen - subStrLen; i++)   
        {                                                                //搜索长度为subStrLen 的全部子串，共 sourceStrLen – subStrLen个  
                                                                         //取source字符串中第i个字符开始的长度为subStrLend的子串  
            strncpy(subStr, source+i, subStrLen);  
            strncpy(revSubStr, source+i, subStrLen);  
            subStr[subStrLen] = revSubStr[subStrLen] = '\0';  
            strrev(revSubStr);                                           //得到反序子串  
            foundMaxSubStr = 1;  
            for( j = 0; j < n; j++)  
                if ( strstr(str[j], subStr) == NULL &&   
                    strstr(str[j], revSubStr) == NULL )   
                {  
                    foundMaxSubStr = 0;  
                    break;  
                }  
                if (foundMaxSubStr)  
                    return(subStrLen);  
        }  
        subStrLen--;  
    }  
    return 0;  
}  
int main()  
{  
    int N,min,a,x,i;  
    scanf("%d",&N);  
    while(N--)  
    {  
        scanf("%d",&n);  
        min=100,i=0;  
        while(i<n)  
        {  
            scanf("%s",str[i]);  
            a=strlen(str[i]);  
            if(min>a)  
            {  
                min=a;x=i;  
            }  
            i++;  
        }  
        printf("%d\n",searchMaxSubString(str[x]));  
    }     
    return 0;  
}  


//////////////////////////////////////////////////母函数/////////////////////////////////////////
//People in Silverland use square coins. Not only they have square shapes but also their values are square numbers. Coins with values of all square numbers up to 289 (=17^2), i.e., 1-credit coins, 4-credit coins, 9-credit coins, ..., and 289-credit coins, are available in Silverland. 
There are four combinations of coins to pay ten credits: 
//
#include<stdio.h>  
#include<string.h>  
int a[400],b[400];  
int main(){  
    int n,i,j,k;  
    while(~scanf("%d",&n))  
    {  
        if(n==0)  
        break;  
        memset(a,0,sizeof(a));  
        memset(b,0,sizeof(b));  
        for(i=0;i<=n;i++)  
        {  
            a[i]=1;b[i]=0;  
        }  
        for(i=2;i<=n;i++)  
    {  
        for(j=0;j<=n;j++)  
        for(k=0;k+j<=n;k+=i*i)  
        b[k+j]+=a[j];  
        for(int i=0;i<=n;i++)  
        {  
            a[i]=b[i];b[i]=0;  
        }  
    }  
    printf("%d\n",a[n]);  
    }  
    return 0;  
}  


***********************************************************************************************
//We all know that Bin-Laden is a notorious terrorist, and he has disappeared for a long time. But recently, it is reported that he hides in Hang Zhou of China! 
“Oh, God! How terrible! ”
#include <iostream>  
  
using namespace std;  
  
int main()  
{  
    int a,b,c;  
    while(cin>>a>>b>>c)  
    {  
        if(!a&&!b&&!c)  
            break;  
        int v[3000];  
        for(int i=0; i<a; i++)  
            v[i]=1;  
        for(int i=a; i<a+b; i++)  
            v[i]=2;  
        for(int i=a+b; i<a+b+c; i++)  
            v[i]=5;  
        int sum=0;  
        for(int i=0;i<a+b+c;i++)  
        {  
            if(sum+1<v[i])  
            break;  
            sum+=v[i];  
        }  
        cout<<sum+1<<endl;  
    }  
    return 0;  
}  


***********************************************************************************************
//"Well, it seems the first problem is too easy. I will let you know how foolish you are later." feng5166 says.
"The second problem is, given an positive integer N, we define an equation like this:
//hdu 1028
#include <stdio.h>  
#define MAX 150  
  
int main()  
{  
    int c1[MAX] , c2[MAX] , n;  
    while(~scanf("%d",&n))  
    {  
        for(int i = 0 ; i <= n ; ++i)  
        {  
            c1[i] = 1 ;  
            c2[i] = 0 ;  
        }  
          
        for(int i = 2 ; i <= n ; ++i)  
        {  
            for(int j = 0 ; j <= n ; ++j)  
            {  
                for(int k = 0 ; j+k <= n ; k+=i)  
                {  
                    c2[j+k] += c1[j] ;  
                }  
            }  
            for(int j = 0 ; j <= n ; ++j)  
            {  
                c1[j] = c2[j] ;  
                c2[j] = 0 ;   
            }  
        }  
        printf("%d\n",c1[n]);  
    }  
    return 0 ;  
}  



***********************************************************************************************
//Nowadays, we all know that Computer College is the biggest department in HDU. But, maybe you don't know that Computer College had ever been split into Computer College and Software College in 2002.
#include <iostream>  
#include <cstring>  
using namespace std;  
#define MAX 250010  
int n,a[MAX],b[MAX],i,j,k,last,last2,v[50],m[50];  
int main()  
{  
    while ((cin>>n)&&n>=0)  
    {  
        for (i=0;i<n;i++)  
            cin>>v[i]>>m[i];  
        a[0]=1;  
        last=0;  
        for (i=0;i<n;i++)  
        {  
            last2=last+m[i]*v[i];  
            memset(b,0,sizeof(int)*(last2+1));  
            for (j=0;j<=m[i];j++)  
                for (k=0;k<=last;k++)  
                    b[k+j*v[i]]+=a[k];  
            memcpy(a,b,sizeof(int)*(last2+1));  
            last=last2;  
        }  
        for (i=last/2;i>=0&&a[i]==0;i--);  
        cout<<last-i<<' '<<i<<endl;  
    }  
    return 0;  
}  



***********************************************************************************************
//在一个国家仅有1分，2分，3分硬币，将钱N兑换成硬币有很多种兑法。请你编程序计算出共有多少种兑法。
#include<iostream>  
using namespace std;  
const int MAX=32768;  
int c1[MAX+1],c2[MAX+1];  
  
int main()  
{  
    int n,j,i,k,num;  
    for(i=0;i<=MAX;i++)  
    {  
        c1[i]=1;c2[i]=0;  
    }  
  
    for(i=2;i<=3;i++)  
    {  
        for(j=0;j<=MAX;j++)  
        for(k=0;k+j<=MAX;k=k+i)  
        {  
            c2[j+k]+=c1[j];  
        }  
        for(j=0;j<=MAX;j++)  
        {  
            c1[j]=c2[j];  
            c2[j]=0;  
        }  
          
    }  
    while(scanf("%d",&num)!=EOF)  
    {  
        printf("%d\n",c1[num]);  
    }  
    return 0;  
}  



***********************************************************************************************
//假设有x1个字母A， x2个字母B,..... x26个字母Z，同时假设字母A的价值为1，字母B的价值为2,..... 字母Z的价值为26。那么，对于给定的字母，可以找到多少价值<=50的单词呢？单词的价值就是组成一个单词的所有字母的价值之和，比如，单词ACM的价值是1+3+14=18，单词HDU的价值是8+4+21=33。(组成的单词与排列顺序无关，比如ACM与CMA认为是同一个单词）。
#include<algorithm>  
#include<cstdio>  
#include<cstring>  
#include<cstdlib>  
#include<iostream>  
#include<vector>  
#include<queue>  
#include<stack>  
#include<map>  
#include<string>  
#include<climits>  
#include<cmath>  
#define N 1000010  
#define LL long long  
using namespace std;  
  
int cnt[100],c1[100],c2[100];  
int main()  
{  
    ios_base::sync_with_stdio(false);  
    cin.tie(0);  
//    freopen("C:\\Users\\ASUS\\Desktop\\cin.cpp","r",stdin);  
//    freopen("C:\\Users\\ASUS\\Desktop\\cout.cpp","w",stdout);  
    int Cas;  
    cin>>Cas;  
    while(Cas--)  
    {  
        for(int i=1;i<=26;++i)  
            cin>>cnt[i];  
        memset(c1,0,sizeof(c1));   //以防后面越界，最好全部赋值为0  
        memset(c2,0,sizeof(c2));  
        for(int i=0;i<=cnt[1]&&i<=50;++i)  
            c1[i]=1;  
        for(int i=2;i<=26;++i)  
        {  
            for(int j=0;j<=50;++j)  
            {  
                for(int k=0;k+j<=50&&k<=cnt[i]*i;k+=i)  
                {  
                    c2[k+j]+=c1[j];  
                }  
            }  
            for(int j=0;j<=50;++j)  
            {  
                c1[j]=c2[j];  
                c2[j]=0;  
            }  
        }  
        long long ans=0;  
        for(int i=1;i<=50 ;++i)  
            ans+=c1[i];  
        cout<<ans<<endl;  
    }  
    return 0;  
}  



***********************************************************************************************
//话说上回讲到HDU大战东洋小苟，结果自然是中方大胜，这一战也使得海东集团在全球同行业中的地位更加巩固。随着集团的发展，很多创业时期的元老逐步功成身退，先是8600移民海外，然后是linle夫妇退隐山林，逐渐的，最初众多的元老只剩下XHD夫妇和Wiskey三人了。
#include <cstdio>  
#include <cstdlib>  
#include <climits>  
#include <cstring>  
#include <algorithm>  
  
using namespace std;  
  
const int MAX = 102;  
  
int p[MAX],m[MAX],ans[MAX*MAX],tmp[MAX*MAX];  
int n;  
  
void work(int aim){  
    int i,j,k;  
  
    memset(ans,0,sizeof(ans));  
    memset(tmp,0,sizeof(tmp));  
  
    for(i=0;i<=m[0] && i*p[0]<=aim;++i){  
        ans[i*p[0]] = 1;  
    }  
  
    //(author : CSDN iaccepted)  
    for(i=1;i<n;++i){  
        for(j=0;j<=aim;++j){  
            for(k=0;k<=m[i] && k*p[i]+j<=aim;++k){  
                tmp[j+k*p[i]] += ans[j];  
                tmp[j+k*p[i]] %= 10000;  
            }  
        }  
        for(j=0;j<=aim;++j){  
            ans[j] = tmp[j];  
            tmp[j] = 0;  
        }  
    }  
}  
  
int main(){  
    //freopen("in.txt","r",stdin);  
    //(author : CSDN iaccepted)  
    int i,all;  
    while(scanf("%d",&n)!=EOF){  
        if(n==0)break;  
        all = 0;  
        for(i=0;i<n;++i){  
            scanf("%d %d",&p[i],&m[i]);  
            all += (p[i] * m[i]);  
        }  
        if(all%3!=0){  
            printf("sorry\n");  
            continue;  
        }  
        all /= 3;  
        work(all);  
        if(ans[all]!=0){  
            printf("%d\n",ans[all]);  
        }else{  
            printf("sorry\n");  
        }  
    }  
    return 0;  
}  


***********************************************************************************************
//又到了选课的时间了，xhd看着选课表发呆，为了想让下一学期好过点，他想知道学n个学分共有多少组合。你来帮帮他吧。（xhd认为一样学分的课没区别）
#include<bits/stdc++.h>  
using namespace std;  
const int MAX=1000;  
int c1[MAX];  
int c2[MAX];  
int g[MAX];  
int n;  
  
int main()  
{  
    int i,j,t,k,a,b;  
    cin>>t;  
    while(t--)  
    {  
        cin>>n>>k;  
        memset(g,0,sizeof(g));  
        for(i=1;i<=k;i++)  
        {  
            scanf("%d%d",&a,&b);  
            g[a]=b;  
        }  
        memset(c1,0,sizeof(c1));  
        memset(c2,0,sizeof(c2));  
        for(i=0;i<=41&&i<=g[1];i++) c1[i]=1;  
        for(i=2;i<=8;i++)//第i个表达式   
        {  
            for(j=0;j<=40;j++)//表示前面i个表达式累乘后的表达式里第j个变量  
            {  
                for(int k=0,s=0;j+k<=40&&s<=g[i];k+=i,s++)  
                {  
                    c2[j+k]+=c1[j];  
                }  
            }  
            for(j=0;j<=40;j++)  
            {  
                c1[j]=c2[j];  
                c2[j]=0;  
            }  
        }  
        printf("%d\n",c1[n]);  
    }  
    return 0;  
}  



***********************************************************************************************
//转眼到了收获的季节，由于有TT的专业指导，Lele获得了大丰收。特别是水果，Lele一共种了N种水果，有苹果，梨子，香蕉，西瓜……不但味道好吃，样子更是好看。
于是，很多人们慕名而来，找Lele买水果。
#include <bits/stdc++.h>
using namespace std;  
#define M 1000  
int num[M],a[M],b[M];  
int  c1[M],c2[M];  
#define mod 100  
#define LL long long  
int main()  
{  
    int n,m;  
    while(scanf("%d %d",&n,&m)!=EOF)  
    {  
        for(int i=0;i<n;i++)  
            cin>>a[i]>>b[i];  
  
        memset(c1,0,sizeof(c1));  
        memset(c2,0,sizeof(c2));  
  
        for(int i=a[0];i<=b[0];i++)  
        {  
            c1[i]=1;  
        }  
        for(int i=1;i<n;i++)  
        {  
            for(int j=0;j<=m;j++)  
            {  
                for(int k=a[i];k+j<=m&&k<=b[i];k++)  
                {  
                    c2[j+k]+=c1[j];  
                }  
            }  
            for(int j=0;j<=m;j++)  
            {  
                c1[j]=c2[j];  
                c2[j]=0;  
            }  
        }  
        cout<<c1[m]<<endl;  
    }  
    return 0;  
}  



***********************************************************************************************
//妈妈
你别哭
泪光照亮不了
我们的路
让我们自己
慢慢的走
//hdu2189

#include<stdio.h>  
#include<string.h>  
int main(){  
    int t,d,i,j,k,n;  
    int c1[152];  
    int c2[152];  
    int prim[152];  
    int y[152];  
    memset(y,0,sizeof(y));  
    d=0;  
    for(i=2;i<=75;i++){  
        for(j=i*2;j<=150;j+=i){  
            y[j]=1;  
        }  
    }  
    for(i=2;i<=150;i++){  
        if(!y[i])prim[++d]=i;  
    }  
    scanf("%d",&t);  
    while(t--){  
        scanf("%d",&n);  
        memset(c1,0,sizeof(c1));  
        memset(c2,0,sizeof(c2));  
        for(i=0;i<=n;i+=2){//第一个数为2   
            c1[i]=1;  
        }  
        for(i=2;i<=d;i++){  
            for(j=0;j<=150;j++)  
                for(k=0;k+j<=n;k+=prim[i])  
                c2[k+j]+=c1[j];  
                for(j=0;j<=150;j++){  
                    c1[j]=c2[j];  
                    c2[j]=0;  
                }  
        }  
        printf("%d\n",c1[n]);  
    }  
    return 0;  
}  


***********************************************************************************************
//假设一堆由1分、2分、5分组成的n个硬币总面值为m分，求一共有多少种可能的组合方式（某种面值的硬币可以数量可以为0）。
//hdu2566
#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
int c1[1010][1010],c2[1010][1010];  
int main(){  
    int n,m,i,j,k,t,h;  
    scanf("%d",&t);  
    while(t--){  
        memset(c2,0,sizeof(c2));  
        memset(c1,0,sizeof(c1));  
        scanf("%d%d",&n,&m);  
        for(i=0;i<=n;i++){//初始化   
            c1[i][i]=1;  
        }  
        for(i=2;i<=5;i+=3){  
            for(j=0;j<=m;j++){  
                for(k=0;k*i+j<=m&&k<=n;k++){//计算钱数   
                    for(h=0;k+h<=n;h++)//计算个数   
                    c2[j+k*i][k+h]+=c1[j][h];  
                }  
            }  
            for(j=0;j<=m;j++)  
            for(k=0;k<=n;k++){  
                c1[j][k]=c2[j][k];  
                c2[j][k]=0;  
            }  
        }  
        printf("%d\n",c1[m][n]);  
    }  
    return 0;  
}   




***********************************************************************************************




***********************************************************************************************




***********************************************************************************************




***********************************************************************************************




***********************************************************************************************




***********************************************************************************************




***********************************************************************************************
