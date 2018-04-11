#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
int t[maxn];

int main()
{
    int n,k; cin>>n>>k;
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>t[i];
        if(t[i]==1) ans+=a[i];
    }

    int cnt=0;
    for(int i=1;i<=k;i++)
    {
        if(t[i] == 0)
        {
            cnt += a[i];
        }
    }
    int maxx = cnt;

    for(int i=2;i<=n-k+1;i++)  //[n-k,   n]
    {
        if(t[i-1]==0)
        {
            cnt -= a[i-1];
        }
        if(t[i+k-1]==0)
        {
            cnt += a[i+k-1];
        }
        maxx = max(maxx,cnt);
    }
    cout << maxx+ans;
    return 0;
}
