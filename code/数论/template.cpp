1.gcd,lcm
2.中国剩余定理
3.高斯消元法
4.卢卡斯定理
5.容斥原理
6.莫比乌斯反演
7.快速幂
8.素数筛选
9.分解质因数
10.求n的约数个数
11.求因子数d(n)
12.欧拉函数

/*********1.gcd,lcm*********/
int gcd(int a,int b){
    return a==0?b:gcd(b,a%b);
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
/* 扩展gcd,求x,y使得gcd(a,b)=ax+by
 * ax+by=gcd(a,b)
 * 当gcd(a,b)=1,即a,b互质,方程的解是a关于模b的逆元*/
int extgcd(int a,int b,int &x,int &y){
    if (b==0) {x=1;y=0;return a;}
    int d=extgcd(b,a%b,x,y);
    int t=x; x=y; y=t-a/b*y;
    return d;
}


/*********2.中国剩余定理(CRT)*********/
//物不知其数问题  N≡2 (mod 3)≡3 (mod 5)≡2 (mod 7)
int Extended_Euclid(int a,int b,int &x,int &y)    //扩展欧几里得算法  
{  
    int d;  
    if(b==0)  
    {  
        x=1;y=0;  
        return a;  
    }  
    d=Extended_Euclid(b,a%b,y,x);  
    y-=a/b*x;  
    return d;  
}  
int Chinese_Remainder(int a[],int w[],int len)    //中国剩余定理  a[]存放余数  w[]存放两两互质的数  
{  
    int i,d,x,y,m,n,ret;  
    ret=0;  
    n=1;  
    for (i=0;i<len;i++)  
        n*=w[i];  
    for (i=0;i<len;i++)  
    {  
        m=n/w[i];  
        d=Extended_Euclid(w[i],m,x,y);  
        ret=(ret+y*m*a[i])%n;  
    }  
    return (n+ret%n)%n;  
}  
int main()  
{  
    int n,i;  
    int w[15],b[15];  
    while (scanf("%d",&n),n)     
    {  
        for (i=0;i<n;i++)  
        {  
            scanf("%d%d",&w[i],&b[i]);  
        }  
        printf("%d/n",Chinese_Remainder(b,w,n));  
    }  
    return 0;  
}

/*********3.高斯消元*********/



/*********4.卢卡斯定理:(Lucas)组合数取模:*********/
//模运算求二项式系数C(n,r)%p,其中p是素数
//C(n,r) = C(n-1,r)+C(n-1,r-1)
ll mod_pow(ll x,ll n,ll mod){//快速幂
    ll res=1;  
    while(n>0){  
        if(n&1) res=(res*x)%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}
ll fac[100005];
ll getFactor(ll p){//初始化
    fac[0]=1;  
    for(int i=1;i<=p;i++)  
        fac[i]=(fac[i-1]*i)%p;  
}  
ll Lucas(ll n,ll m,ll p){//Lucas 定理
    ll res=1;
    while(n&&m){
        ll a=n%p,b=m%p;
        if(a<b) return 0;
        res=(res*fac[a]*mod_pow(fac[b]*fac[a-b]%p,p-2,p))%p;
        n/=p;
        m/=p;
    }
    return res;
}
//use
getFactor(p);
Lucas(n,m,p);


/*********5.容斥原理*********/
ll Q[100010],factor[110],num;
//Q数组存放的就是右边边各项的因子数以及正负情况，factor[]存放对应对象的数目，num为有几个对象
void get_key(int n) //会重复出现,9999=3*3*9*101
{
    for (int i=2;i<=n;i++){
        while(n!=i){
            if (n%i==0){
                factor[num++]=i;
                n=n/i;
            }
            else break;
        }
    }
    factor[num++]=n;
    num = unique(factor,factor+num)-factor;//如果要去重
}
LL solve(LL n)  //容斥定理
{
    LL k,t,ans;
    t = ans = 0;
    Q[t++] = -1;
    for(LL i = 0; i < num; ++i)
    {
        k = t;
        for(LL j = 0; j < k; ++j)
            Q[t++] = -1*Q[j]*factor[i];
    }
    //A∪B∪C = A+B+C - A∩B - B∩C - C∩A + A∩B∩C
    //Q数组存放的就是A∪B∪C右边边各项的因子数以及正负情况。
    for(LL i = 1; i < t; ++i)
        ans += n/Q[i];
    //n/Q[i]累加起来就是A∪B∪C
    return ans;
}


/*********6.莫比乌斯反演,预处理mu*********/
using namespace std;//O(n)
const int N = 1e6 + 5;
int mu[N], vis[N], prime[N];
int tot;//用来记录 prime 的个数
void init(){
    mu[1] = 1;
    for(int i = 2; i < N; i ++){
        if(!vis[i]){
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < tot && i * prime[j] < N; j ++){
            vis[i * prime[j]] = 1;
            if(i % prime[j]) mu[i * prime[j]] = -mu[i];
            else{
                mu[i * prime[j]] = 0;
                break;
            }
        }
    }
}
int main(){
    init();
    for(int i=0;i<=10;i++)
        cout<<"i:"<<i<<" "<<mu[i]<<endl;
}


/********7.快速幂(反复平方法降复杂度logn)*********/
//x^n%mod,重复n次x的乘积,把n拆为多个2的幂形式(即直接判二进制位)  
//判n的每一位过程中,每次都更新x为x^2,对应上面的2的幂次  
const int mod = 998244353;
ll quick_pow(ll x, ll n,ll mod)//x^n%mod
{
    ll res=1;
    while(n>0)
    {
        if (n&1) res = res*x%mod;//最低位1则要乘以x^(2^i)
        x = x*x%mod;//
        n>>=1;
    }
    return res;
}

//快速乘的快速幂
ll quick_mul(ll x,ll n)
{
    ll res=0;
    while(n)
    {
        if(n&1)res=(res+x)%mod;
        x=(x+x)%mod;
        n>>=1;
    }
    return res;
}
ll quick_pow(ll x,ll n)
{
    ll res=1;
    while(n)
    {
        if(n&1) res=quick_mul(res,x)%mod;
        x=quick_mul(x,x)%mod;
        n>>=1;
    }
    return res;
}

//矩阵快速幂
找F[i]=A*A[i-1]; 
则F[n]=F[1]*A^(n-1);


/*********8.素数筛选*********/
/*
x以内素数个数: pi(x) = x/ln(x)
 x        prime(x)
1e1                 4
1e2                25
1e3               168
1e4             1 229
1e5             9 592
1e6            78 498
1e7           664 579
1e8         5 761 455
1e9        50 847 534
1e10      455 052 511
1e11    4 118 054 813
1e12   37 607 912 018
*/
ll prime[maxn];
ll tot=0;
bool isprime[maxn];
void getprime()
{
    bool(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for (int i=2;i<maxn;i++)
    {
        if (isprime[i])
        {
            prime[tot++]=i;//if need
            for (int j=i+i;j<maxn;j+=i)
                isprime[j]=false;
        }
    }
}
bool isPrime(int n)
{
    int sq = sqrt(n);
    for (int i=2;i<=sq;i++)
        if(n%i==0) return false;
    return true;
}

/*==================================================*\
| 随机素数测试(伪素数原理)
| CALL: bool res = miller(n);
| 快速测试n是否满足素数的'必要'条件, 出错概率很小;
| 对于任意奇数 n>2 和正整数 s, 算法出错概率 <= 2^(-s);
\*==================================================*/
#include<cmath>
bool witness(__int64 a,__int64 n)
{
    __int64 t,d,x;
    d=1;
    int i=ceil(log(n-1.0)/log(2.0)) - 1;
    for(;i>=0;i--)
    {
        x=d;  d=(d*d)%n;
        if(d==1 && x!=1 && x!=n-1) return true;
        if( ((n-1) & (1<<i)) > 0)
            d=(d*a)%n;
    }
    return d==1? false : true;
}
bool miller_rabin(__int64 n)
{
    if(n==2)    return true;
    if(n==1 || ((n&1)==0))    return false;
    for(int i=0;i<50;i++){
        __int64 a=rand()*(n-2)/RAND_MAX +1;
        if(witness(a, n))    return false;
    }
    return true;
}
int main()
{
    int n,cnt;
    __int64 a;
    while(scanf("%d",&n)!=EOF)
    {
        cnt=0;
        while(n--)
        {
            scanf("%I64d",&a);
            if(miller_rabin(a))
                cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}



/*********9.分解质因数:*********/
void get_key(int n) //会重复出现,9999=3*3*9*101
{
    for (int i=2;i<=n;i++){
        while(n!=i){
            if (n%i==0){
                factor[num++]=i;
                n=n/i;
            }
            else break;
        }
    }
    factor[num++]=n;
    //int len = unique(factor,factor+num)-factor;//如果要去重
}
void get_key2(ll n){ //不会重复出现,9999=3*9*101
    num=0;
    for (ll i=2;i*i<=n;i++){
        if (n%i==0){
            while(n%i==0)
                n/=i;
            factor[num++]=i;
        }
    }
    if (n!=1) factor[num++]=n;
}


/*********10.求n的约数个数*********/
//求n的约数个数(eg:`60=2^2*3*5`,`sum=3*2*2=12`)
//num = (p1+1)*(p2+1)*(p3+1)...
getprime();//返回tot和prime[0..tot-1]给后面用
ll cont(ll n)
{
    ll cnt,sum=1;
    for(int i=0;i<tot && prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            cnt=0;
            while(n%prime[i]==0)
            {
                cnt++;
                n/=prime[i];
            }
            sum*=(cnt+1);
        }
    }
    if(n > 1)
        sum*=2;
    return sum;
}


/*********11.求因子数d(n)*********/
n的因子数,分解质因数n=P1^x1 * P2^x2* …… * Pm^xm;
d(n)=(x1+1)*(x2+1)*...*(xm+1)
d(n^k)=(kx1+1)*(kx2+1)...(kxm+1)  n=p1^x1*p2^x2...pm^xm


/*********12.欧拉值*********/
//[1,n)与n互素的个数
ll euler(ll x)
{
    ll i,ans=x;
    for (i=2;i<(int)sqrt(x*1.0)+1;i++)
    {
        if (x%i==0)
        {
            ans=ans/i*(i-1);
            while (x%i==0) x/=i;//保证i是素数
        }
    }
    if (x>1) ans=ans/x*(x-1);
    return ans;
}

//预处理[1,n]每个数的欧拉值
//解法1,效率高
const int N = 1e6+5 ;
int phi[N], prime[N];
int tot;
void init()
{
    phi[1] = 1;
    for(int i=2;i<N;i++)
    {
        if(!phi[i])
        {
            phi[i] = i-1;
            prime[tot++] = i;
        }
        for(int j=0;j<tot && 1ll*i*prime[j]<N;j++)
        {
            if(i%prime[j]) phi[i*prime[j]] = phi[i]*(prime[j]-1);
            else
            {
                phi[i*prime[j]] = phi[i]*prime[j];
                break;
            }
        }
    }
}
//解法二,效率低
const int maxn = 1e6+5;
int phi[maxn];
void init()
{
    for (int i=1;i<=maxn;i++) phi[i]=i;
    for (int i=2;i<=maxn;i+=2) phi[i]/=2;
    for (int i=3;i<=maxn;i+=2)
        if (phi[i]==i)
        {
            for (int j=i;j<=maxn;j+=i)
                phi[j] = phi[j]/i*(i-1);
        }
}

