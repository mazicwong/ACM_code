#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn = 20000+5;
int a[maxn];
ll p;
ll s;
long long pre[maxn];

bool check(int mid)
{
    int idx = upper_bound(a,a+n,mid)-a; //0..n
    //cout << "idx: " << idx << endl;
    ll sum=0;
    if(idx==0) sum = 1LL*pre[n-1];
    else sum = 1LL*pre[n-1]-1LL*pre[idx-1];
    //cout << "sum: " << sum << endl;
    sum -= 1LL*(n-1-idx+1)*mid;
    if(sum*p <= s) return true;
    else return false;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    int maxx = a[n-1];
    pre[0]=a[0];
    for(int i=1;i<n;i++){
        pre[i] = pre[i-1]+a[i];
    }
    cin>>p>>s;

    int l=1, r=maxx;
    while(l<r)
    {
        int mid = (l+r)/2;
        if(check(mid)==true){
            r=mid;
        }
        else {
            l=mid+1;
        }
    }
    cout << l;
    return 0;
}
