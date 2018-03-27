#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
int a[maxn];
/*
 * 5 3
 * 4 6 8 9 10
 */
int main()
{
    int n,u;
    cin>>n>>u;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    //cout<<upper_bound(a,a+n,8)-a-1;

    double ans=-1;
    for(int i=0;i<n;i++)
    {
        int now=a[i];
        int nxt=upper_bound(a,a+n,a[i]+u)-a-1;
        if(nxt==i+1 || nxt==i) continue;
        double tmp = ((double)a[nxt]-(double)a[i+1])/((double)a[nxt]-(double)a[i]);
        if(tmp>ans) ans=tmp;
    }
    printf("%.09lf",ans);
    return 0;
}
