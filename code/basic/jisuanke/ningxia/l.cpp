#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000+5;
int a[maxn];
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int ans=-1;
        int n; cin>>n;
        for(int i=0;i<n;i++)
        {
            int x; scanf("%d",&x);
            ans = max(ans,x);
        }
        cout<<ans<<endl;
    }
    return 0;
}
