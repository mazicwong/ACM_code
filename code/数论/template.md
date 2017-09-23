[太菜了,开始系统学习下数论知识点 & 整理模板](http://blog.csdn.net/ACdreamers/article/category/1159392)

http://www.cnblogs.com/linyujun/category/784324.html

* [1.数论基础](#1)
  * [1.1图片](#1.1)
  * [1.2换行](#1.2)

[欧几里得]
[扩展欧几里得]
[中国剩余定理]
[高斯消元法]
[卢卡斯定理]
[容斥原理]
[莫比乌斯反演]
[快速幂]
[素数筛选]
[分解质因数]
[求因子数]
[欧拉函数]



***
<h2 id="1">数论基础</h2>


***
<h3 id="1.1">欧几里得:辗转相除法</h3>



***
<h3 id="1.2">拓展欧几里得:</h3>
>ax+by=gcd(a,b)
当gcd(a,b)=1,即a,b互质,方程的解是a关于模b的逆元




***
中国剩余定理(CRT):
>"物不知其数问题"  N≡2 (mod 3)≡3 (mod 5)≡2 (mod 7)




***
高斯消元法:
>


***
卢卡斯定理:(Lucas)组合数取模
//模运算求二项式系数C(n,r)%p,
//其中p是素数
//C(n,r) = C(n-1,r)+C(n-1,r-1)

```cpp
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
```



***
[容斥原理:](http://www.cppblog.com/vici/archive/2011/09/05/155103.html)
>  




***
[莫比乌斯反演:](https://www.zhihu.com/question/23764267/answer/26007647)
>



***
快速幂:(反复平方法降复杂度logn)
>x^n%mod,重复n次x的乘积,把n拆为多个2的幂形式(即直接判二进制位)  
判n的每一位过程中,每次都更新x为x^2,对应上面的2的幂次  

```cpp
ll mod_pow(ll x, ll n,ll mod)//x^n%mod
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
//北大版本2,还没调试过
const int mod = 998244353;
int pow(int a,int b){
    int res=1;
    for (int i=1;i<=n;i<<=1,a=1LL*a*a%mo) if(b&i) res=1LL*res*a%mo;
    return res;
}
```




***
素数筛选:

x以内素数个数: pi(x) = x/ln(x)
x      prime(x)
1e1    4
1e2    25
1e3    168
1e4    1,229
1e5    9,592
1e6    78,498
1e7    664,579
1e8    5,761,455
1e9    50,847,534
1e10   455,052,511
1e11   4,118,054,813
1e12   37,607,912,018

```cpp
ll prime[maxn];
ll tot=0;
bool isprime[maxn];
void getprime()
{
    bool(isprime,true,sizeof(isprime));
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
```



***
分解质因数:

```cpp
void get_key(int n)
{
    for (int i=2;i<=n;i++)
    {
        while(n!=i)
        {
            if (n%i==0)
            {
                printf("%d*",i);
                n=n/i;
            }
            else break;
        }
    }
    printf("%d",n);
}
```


***
求n的约数个数(eg:`60=2^2*3*5`,`sum=3*2*2=12`)
`num = (p1+1)*(p2+1)*(p3+1)...`
```cpp
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
```





***
[求因子数d(n):](http://blog.sina.com.cn/s/blog_818d3d9301017436.html)
>n的因子数,分解质因数n=P1^x1 * P2^x2* …… * Pm^xm;
d(n)=(x1+1)*(x2+1)*...*(xm+1)
d(n^k)=(kx1+1)*(kx2+1)...(kxm+1)  n=p1^x1*p2^x2...pm^xm


***
欧拉值:
>[1,n)与n互素的个数

```cpp
ll euler(ll x)
{
    ll i,ans=x;
    for (i=2;i<(int)sqrt(x*1.0)+1;i++)
    {
        if (x%i==0)
        {
            ans=ans/i*(i-1);
            while (x%i==0) x/=i;
        }
    }
    if (x>1) ans=ans/x*(x-1);
    return ans;
}
```

>预处理[1,n]每个数的欧拉值

```cpp
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
```

