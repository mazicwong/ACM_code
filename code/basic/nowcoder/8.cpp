#include <bits/stdc++.h>
using namespace std;
const int maxn = 600+5;
int a[maxn];
typedef pair<int,int> pii;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    set<pii> st;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(gcd(a[i],a[j]) == 1)
                ans++;
        }
    }
    cout << ans;
    return 0;
}
