#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 50+5;
ll a[maxn];
void init()
{
    a[1]=1;
    a[2]=2;
    for(int i=3;i<=50;i++)
        a[i] = a[i-1]+a[i-2];
}
int main()
{
    int n; cin>>n;
    int ta,tb;
    init();
    while(n--)
    {
        cin>>ta>>tb;
        cout<<a[tb-ta]<<endl;
    }
    return 0;
}

