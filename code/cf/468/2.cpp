#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int a,b; cin>>a>>b;
    a--; b--;
    while(a!=b)
    {
        cnt++;
        a/=2;
        b/=2;
        n/=2;
    }
    if(n==1) cout << "Final!";
    else cout << cnt;

    return 0;
}
