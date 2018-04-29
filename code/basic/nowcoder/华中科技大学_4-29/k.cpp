#include <bits/stdc++.h>
using namespace std;
//走k步，最小化最大的一步
typedef long long ll;
int n,k;
const int maxn = 1e5+5;
ll a[maxn];

bool check(ll mid)
{
    int cnt=0;
    ll sum=0;
    for(int i=0;i<n-1;i++){
        if(sum+a[i] <= mid){
            sum+=a[i];
        }
        else {
            sum=a[i];
            cnt++;
        }
    }
    if(sum!=0) cnt++;
    return cnt<=k;
}

int main()
{
    cin>>n>>k;
    ll maxx = 0;
    for(int i=0;i<n-1;i++){
        scanf("%lld",&a[i]);
        maxx = max(a[i],maxx);
    }
    ll l=maxx; ll r=1e10;
    while(l<r)
    {
        ll mid = (l+r)/2;
        if(check(mid)==true){
            r = mid;
        }
        else {
            l = mid+1;
        }
    }
    cout << l;
    return 0;
}
