#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
typedef long long ll;
ll a[maxn];
ll reser[maxn];
int main()
{
    for(int i=0;i<14;i++){
        cin>>a[i];
        reser[i]=a[i];
    }
    ll ans=0;
    for(int i=0;i<14;i++)
    {
        for(int j=0;j<14;j++) a[j] = reser[j];
        if(a[i]==0) continue;

        ll rator = a[i]/14;
        ll res = a[i]%14;
        a[i]=0;
        for(int j=0;j<14;j++)
        {
            a[j]+=rator;
        }
        for(int j=1;j<=res;j++)
        {
            int idx = (i+j)%14;
            a[idx]++;
        }
        long long tmp=0;
        for(int j=0;j<14;j++)
        {
            if(a[j]%2==0)
            {
                tmp += a[j];
            }
        }
        ans = max(ans,tmp);
    }
    cout<<ans;

    return 0;
}
