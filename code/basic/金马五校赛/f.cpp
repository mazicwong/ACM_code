#include <bits/stdc++.h>
using namespace std;
 
// 1,2,4,5,8,9,10,16,17,18,20,21,
long long nxt(long long x)
{
    long long y = x|(x>>1);
    long long z = y+1;
    z = z&-z;
    x ^= z;
    x &= ~(z-1);
    return x;
}
 
const int maxn = 2;
typedef long long ll;
 
ll fib[100];
ll ans=0;
 
void solve(ll n,int up)
{
    if(n==1)
    {
        ans+=1;
        return ;
    }
    for(int i=up;i>=0;i--)
    {
        if(fib[i] < n) //<= ??
        {
            ans += 1LL<<(i-2);
            //ans += pow(2,i-2);
            solve(n-fib[i],i-1);
            return;
        }
    }
}
 
int main()
{
    //for(int i=1;i<=50;i++) if((i^(2*i))==(3*i)) cout << i << ',';
    fib[1]=1; fib[2]=1;
    for(int i=3;i<=80;i++) fib[i]=fib[i-1]+fib[i-2];
 
    ll n;
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        ans = 0;
        solve(n+1,79);
        cout << ans-1 << endl;
    }
    return 0;
}
