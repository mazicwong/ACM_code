#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
int a[maxn];
int main()
{
    int n;
    while(cin>>n && n)
    {
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        if(n%2==1)
            cout << a[n/2] << endl;
        else
            cout << (a[n/2]+a[n/2-1])/2 << endl;
    }
    return 0;
}
