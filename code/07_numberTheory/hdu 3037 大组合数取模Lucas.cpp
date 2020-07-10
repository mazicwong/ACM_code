/*
* hdu 1799
* author  : mazciwong
* creat on: 2016-1-15
*/

/*
 * ���m�����ӷ�n������,�ж����ַŷ�(�ɲ��ų���m��)
 * �����ֳ�n��
  * C(n,m)%p ����
  * ˼·��: http://blog.csdn.net/helloworld10086/article/details/48494613
 *
 * mȡ����״̬,��巨֪����C(n+m-1,m)
 * �������д𰸾���C(n+m,m)
*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <functional> //greater
#include <algorithm>
using namespace std;
typedef long long ll;

ll mod_pow(ll x,ll n,ll mod){//������
    ll res=1;  
    while(n>0){  
        if(n&1) res=(res*x)%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}
ll fac[100005];  
ll getFactor(ll p){//��ʼ��
    fac[0]=1;  
    for(int i=1;i<=p;i++)  
        fac[i]=(fac[i-1]*i)%p;  
}  
ll Lucas(ll n,ll m,ll p){//Lucas ����
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
