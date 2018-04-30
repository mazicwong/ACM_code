#include <bits/stdc++.h>
using namespace std;
const int mod = 3e5;
const int maxn = 3e5+5;
typedef long long ll;
const ll mod1= 1e9;
int main()
{
    srand(time(NULL));
    ll n = rand()%mod1;
    if(n&1==1) n++;
    cout << n << endl;
    ll m = rand()%mod1;
    cout << m << endl;
    ll k=rand()%mod1;
    if(k>n*m) k=n;
    cout <<  k << endl;
    
    return 0;
}
