#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,A,B;
int main()
{
    cin>>n>>k>>A>>B;
    ll ans = 0;
    ll x = n;
    ans = (x-(x/k*k))*A;  x=x/k*k;
    while((x-x/k)*A > B)
    {
        ans += B;
        x = x/k;

        ans += (x-x/k*k)*A; x=x/k*k;
    }
    ans += (x-1)*A;

    cout << ans;
    return 0;
}
