#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans=-20000;
    int n;cin>>n;
    int a[1050];for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n-1;i++)
    {
        ans=max(ans,abs(a[i+1]-a[i]));
    }
    cout<<ans;

    return 0;
}
