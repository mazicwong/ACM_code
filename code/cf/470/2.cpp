#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5; //78498
bool isprime[maxn];
int cnt=0;
int prime[maxn];
void get_prime(int n)
{
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for(int i=2;i<n;i++)
    {
        if(isprime[i]==false)continue;
        prime[++cnt]=i;
        for(int j=i+i;j<n;j+=i)
            isprime[j]=false;
    }
}
int main()
{
    int n;cin>>n;
    get_prime(n);
    for(int i=1;i<cnt;i++)
    {
        for(int x1=prime[i]+1;x1<=)

    }
    

    return 0;
}
