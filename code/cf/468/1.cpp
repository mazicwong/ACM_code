#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;cin>>a>>b;
    int ans = abs(a-b);
    if(ans%2==0)
        cout << (ans/2*(1+ans/2));
    else cout << (((ans/2)*(1+ans/2))/2+(ans/2+1)*(2+ans/2)/2);
    

    return 0;
}
