#include <bits/stdc++.h>
using namespace std;
long long f[25];
int main()
{
    f[1]=2;
    for(int i=2;i<=21;i++)
    {
        f[i] = f[i-1]*2;
    }
    int n; cin>>n;
    cout << f[n];
    return 0;
}
