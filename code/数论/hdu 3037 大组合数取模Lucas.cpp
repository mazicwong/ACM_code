/*
* hdu 1799
* author  : mazciwong
* creat on: 2016-1-15
*/

/*
 * 最多m个种子放n颗树上,有多少种放法(可不放超过m个)
 * 即划分成n块
  * C(n,m)%p 裸题
  * 思路见: http://blog.csdn.net/helloworld10086/article/details/48494613
 *
 * m取满的状态,插板法知道是C(n+m-1,m)
 * 所以所有答案就是C(n+m,m)
*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <functional> //greater
#include <algorithm>
using namespace std;
typedef long long ll;

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

int main()
{
    int t;cin>>t;
    ll n,m,p;
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&m,&p);
        getFactor(p);
        printf("%lld\n",Lucas(n+m,n,p));
    }
	return 0;
}
