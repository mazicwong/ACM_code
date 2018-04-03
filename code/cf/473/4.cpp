#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    /*int n; cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);*/
    cout << gcd(6,12) << endl;
    cout << gcd(6,9) << endl;

    return 0;
}
