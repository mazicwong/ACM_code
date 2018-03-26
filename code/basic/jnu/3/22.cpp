#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e7+5;

bool witness(ll a,ll n)
{
    ll t,d,x;
    d=1;
    int i=ceil(log(n-1.0)/log(2.0)) - 1;
    for(;i>=0;i--)
    {
        x=d; d=(d*d)%n;
        if(d==1 && x!=1 && x!=n-1) return true;
        if( ((n-1) & (1<<i)) > 0 )
        d=(d*a)%n;

    }
    return d==1? false : true;

}
bool miller_rabin(ll n)
{
    if(n==2)
    return true;
    if(n==1 || ((n&1)==0))
    return false;
    for(int i=0;i<50;i++){
        ll a=rand()*(n-2)/RAND_MAX +1;
        if(witness(a, n))
        return false;
    }
    return true;
}
ll prime[maxn];
ll tot=0;
int n;
bool isprime[maxn];
void getprime()
{
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for (int i=2;i<maxn;i++)
    {
        if (isprime[i])
        {
            prime[++tot]=i;
            if(tot==n)
            {
                cout<<prime[tot];
                return;
            }
            for (int j=i+i;j<maxn;j+=i)
                isprime[j]=false;
        }
    }
}

int main()
{
    cin>>n;
    if(n<=1e5) //1299709
    {
        getprime();
    }
    else if(n>1e6+5000)
    {
        int cnt=15485863; //1e6
        for(int i=cnt+1;i<=1226564;i++)
        {
            if(miller_rabin(i))
                cnt++;
            if(cnt==1226564)
            {
                cout<<i;
                return 0;
            }
        }
    }
    else if (n<)
    return 0;
}
