/*************************************************************************
	> File Name: lightoj1341分解质因数幂次数和.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月03日 星期日 23时10分43秒
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
typedef long long ll;
const int maxn = 1000005;

ll prime[maxn];
ll isprime[maxn];

ll tot=0;
void getprime()
{
    for (int i=2;i<maxn;i++)
        isprime[i]=1;
    for (int i=2;i<maxn;i++)
    {
        if (isprime[i])
        {
            prime[tot++]=i;
            for (int j=i+i;j<maxn;j+=i)
                isprime[j]=false;
        }
    }
}

//分解质因数函数,得到tot和prime[0..tot-1]
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


int main()
{
    freopen("in","r",stdin);
	getprime();
    int t;cin>>t;
    for (int cas=1;cas<=t;cas++)
    {
        int cnt = 0;
        ll ans;
        ll a,b;
        scanf("%lld%lld",&a,&b);
        if (b>sqrt(a)) ans = 0;
        else
        {
            for (ll i=1;i<b;i++)//暴力
                if (a%i==0)
                    cnt++;
            ll num = cont(a)/2;
            ans = num-cnt;
        }
        printf("Case %d: %lld\n",cas,ans);  
    }
    return 0;
}
