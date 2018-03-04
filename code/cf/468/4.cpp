#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int a[maxn];
int mp[maxn];
int mp1[maxn];
int main()
{
    int n; cin>>n;
    mp[1]=1;
    mp[2]=1;
    for (int i=2;i<=n;i++)
    {
        scanf("%d",&a[i]);
        mp[i]=mp[a[i]]+1;
    }
    for(int i=2;i<=n;i++)
    {
        mp1[mp[i]]++;
    }
    int ans = 1;
    for(int i=2;i<=n;i++)
    {
        if(mp1[i]!=0 && mp1[i]%2!=0)
        {
            ans++;
        }
    }
    cout << ans;


    return 0;
}
