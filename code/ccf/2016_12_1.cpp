#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int a[maxn];
int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);

    bool flag=false;
    for(int i=0;i<n;i++)
    {
        int up = upper_bound(a,a+n,a[i])-a;
        int low = lower_bound(a,a+n,a[i])-a;
        if(n-up == low)
        {
            flag=true;
            cout<<a[i];
            break;
        }
    }
    if(!flag)cout<<"-1";
    return 0;
}
