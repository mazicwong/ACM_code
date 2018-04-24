#include <bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
int S=2;//测试次数，越大进度越高一般2~6就好O(S*log3n)
ll mod_mul(ll a, ll b, ll n)  //快速乘
{   ll res = 0;
    while(b)
    {
        if(b&1)    res = (res + a) % n;
        a = (a + a) % n;
        b >>= 1;
    }
    return res;
}
ll mod_exp(ll a, ll b, ll n)  //快速幂
{
    ll res = 1;
    while(b)
    {
        if(b&1)    res = mod_mul(res, a, n);
        a = mod_mul(a, a, n);
        b >>= 1;
    }
    return res;
}
bool miller_rabin(ll n)  //复杂度很小
{
    if(n == 2 || n == 3 || n == 5 || n == 7 || n == 11)    return true;
    if(n == 1 || !(n%2) || !(n%3) || !(n%5) || !(n%7) || !(n%11))    return false;
    ll x, pre, u;
    int i, j, k = 0;
    u = n - 1;    //要求x^u % n
    while(!(u&1))      //如果u为偶数则u右移，用k记录移位数
    {
        k++;
        u >>= 1;
    }
    srand((ll)time(0));
    for(i = 0; i < S; ++i)      //进行S次测试
    {
        x = rand()%(n-2) + 2;    //在[2, n)中取随机数
        if((x%n) == 0)    continue;
        x = mod_exp(x, u, n);    //先计算(x^u) % n，
        pre = x;
        for(j = 0; j < k; ++j)      //把移位减掉的量补上，并在这地方加上二次探测
        {
            x = mod_mul(x, x, n);
            if(x == 1 && pre != 1 && pre != n-1)    return false;    //二次探测定理，这里如果x = 1则pre 必须等于 1，或则 n-1否则可以判断不是素数
            pre = x;
        }
        if(x != 1)    return false;    //费马小定理
    }
    return true;
}
inline ll read()
{
    ll x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
map<ll,int> mp;
int main()
{   //*/test miller_rabin
    ll T; T=read();
    mp.clear();
	while(T--)
	{
		ll n; n=read();
    //	cout<<"n= "<<n<<endl;
    	if(n==4)
    	{
    		printf("2 2\n");
    		continue;
		}
		if(n==6)
		{
			printf("3 3\n");
    		continue;
		}
    	ll tn=n/2;
   	 	if(tn%2==0)
    	{
    		int fl=0;
    		for(ll i=1;i<=50000;i+=2)
    		{
                if(mp[tn-i]==0) mp[tn-i] = (miller_rabin(tn-i) == true) ? 1:2;
                if(mp[tn+i]==0) mp[tn+i] = (miller_rabin(tn+i) == true) ? 1:2;
                if(mp[tn-i]==1 && mp[tn+i]==1)
    			//if(miller_rabin(tn-i)&&miller_rabin(tn+i))
    			{
    				//printf("%lld %lld\n",tn-i,tn+i);
    				fl=1;
                    printf("%llu %llu\n",tn-i,tn+i);
    				//cout<<tn-i<<" "<<tn+i<<endl;
    				break;
				}
			}
			if(fl==0)
			{
				for(ll i=2;i<=50000;i++)
				{
                    if(mp[n-i]==0) mp[n-i] = (miller_rabin(n-i) == true) ? 1:2;
                    if(mp[i]==0) mp[i] = (miller_rabin(i) == true) ? 1:2;
                    if(mp[n-i]==1 && mp[i]==1)
					//if(miller_rabin(n-i)&&miller_rabin(i))
					{
                        printf("%llu %llu\n",n-i,i);
						//cout<<n-i<<" "<<i<<endl;
    					break;
					}
				}
			}
		}
		else
		{
			int fl=0;
			for(ll i=0;i<=50000;i+=2)
    		{
                if(mp[tn-i]==0) mp[tn-i] = (miller_rabin(tn-i) == true) ? 1:2;
                if(mp[tn+i]==0) mp[tn+i] = (miller_rabin(tn+i) == true) ? 1:2;
                if(mp[tn-i]==1 && mp[tn+i]==1)
    			//if(miller_rabin(tn-i)&&miller_rabin(tn+i))
    			{
    				//printf("%lld %lld\n",tn-i,tn+i);
    				fl=1;
                    printf("%llu %llu\n",tn-i,tn+i);
    				//cout<<tn-i<<" "<<tn+i<<endl;
    				break;
				}
			}
			if(fl==0)
			{
				for(ll i=3;i<=50000;i+=2)
				{
                    if(mp[n-i]==0) mp[n-i] = (miller_rabin(n-i) == true) ? 1:2;
                    if(mp[i]==0) mp[i] = (miller_rabin(i) == true) ? 1:2;
                    if(mp[n-i]==1 && mp[i]==1)
					//if(miller_rabin(n-i)&&miller_rabin(i))
					{
                        printf("%llu %llu\n",n-i,i);
						//cout<<n-i<<" "<<i<<endl;
    					break;
					}
				}
			}
		}
	}
    return 0;
}
