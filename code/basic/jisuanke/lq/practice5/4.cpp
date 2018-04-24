#include <bits/stdc++.h>
using namespace std;


const int mod = 1e9+7;

int quick_mod(int x,int n)
{
    int res=1;
    while(n)
    {
        if(n&1) res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}

int pw(int x, int n) {
    if (!n) {
        return 1;
    }
    int res = pw(x*x%mod,n>>1);
    if (n & 1) {
        res = res * x % mod;
    }
    return res;
}

int main()
{
    cout << quick_mod(5,2) << endl;
    cout << quick_mod(5,3) << endl;
    cout << quick_mod(2,10) << endl;
    cout << pw(5,2) << endl;
    cout << pw(5,3) << endl;
    cout << pw(2,10) << endl;
    return 0;
}
