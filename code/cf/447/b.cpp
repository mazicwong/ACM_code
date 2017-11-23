#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
using namespace std;
const int maxn = 2000 + 5;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;


ll mod_pow(ll x, ll n)//x^n%mod
{
    ll res=1;
    x=x%mod;
    while(n>0)
    {
        if (n&1) res = res*x%mod;
        x = x*x%mod;
        n>>=1;
    }
    return res;
}

int main()
{
	ll n, m, k;
    while(1) {
        cin >> n >> m >> k;
        ll p = min(n,m);
        ll q = max(n,m);
        if(p==1 && ((q%2)==0 && k == -1)){
	    	cout <<"0"<<endl;
	        return 0;
	    }
        ll ans1 = 1, ans2 = 1;
        ans1 = mod_pow(2,(n-1));
        ans2 = mod_pow(ans1,(m-1));
        cout << 1LL* ans2 << endl;       
    }

	return 0;
}
