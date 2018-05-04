#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000+5;
typedef long long ll;

ll a[maxn];
ll suf[maxn];
ll reser[maxn];

int n,q; 
ll idx=0;
void upd()
{
    for(int i=0;i<n;i++) a[i]=reser[i];
    idx=0;
}
int main()
{
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        reser[i]=a[i];
    }
    suf[n-1]=a[n-1];
    suf[n]=0;
    for(int i=n-2;i>=0;i--)
    {
        suf[i]=suf[i+1]+a[i];
    }
    idx=0;
    while(q--)
    {
        ll num; cin>>num;
        if(a[idx]>num) 
        {
            a[idx]-=num;
            int ans=n-idx;
            cout << ans << endl;
            continue;
        }
        else if(a[idx]==num)
        {
            a[idx]=0;
            idx++;
            int ans=n-idx;
            if(ans==0) {upd();ans=n;}
            cout << ans << endl;
            continue;
        }
        /*
        else if(idx==n-1) //a[idx]<num
        {
            upd();
            cout << n << endl;
            continue;
        }*/
        if(suf[idx+1]+a[idx]<=num) 
        {
            upd();
            cout << n << endl;
            continue;
        }
        
        num-=a[idx];
        idx++;
        ll l=idx; ll r=n-1;
        while(l<r)
        {
            ll mid = (l+r)/2;
            if(suf[l]-suf[mid+1] >= num) 
            {
                r = mid;
            }
            else l=mid+1;
        }
        ll del = num - (suf[idx]-suf[l]);
        idx=l;
        a[idx]-=del;
        if(a[idx]==0)
        {
            idx++;
        }
        ll ans=n-idx;
        if(ans==0) {upd(); cout << n << endl;}
        else cout << ans << endl;
    }
    return 0;
}
