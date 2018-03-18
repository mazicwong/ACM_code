#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    int a[1005];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int ans=0x3f3f3f3f;
    for(int i=1;i<n;i++)
    {
        ans = min(ans, a[i]-a[i-1]);
    }
    cout << ans;

    return 0;
}
