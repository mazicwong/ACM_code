#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    n/=10;
    int ans = n/5*(5+2);
    int tmp = n%5;
    if(tmp>=3)
        ans++;
    ans += tmp;
    cout << ans;
    return 0;
}
