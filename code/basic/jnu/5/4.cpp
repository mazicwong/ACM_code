#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <time.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll quick_mod(ll x,ll n)
{
    ll res=1;
    while(n>0)
    {
        if(n&1) res = res*x%mod;
        x = x*x%mod;
        n>>=1;
    }
    return res;
}
int main()
{
    long long m,n;
    cin>>m>>n;
    //cout << (m*(m-1)^(n-1))<<endl;
    cout << (quick_mod(m-1,n-1)%mod)*m%mod ;
    return 0;
}
