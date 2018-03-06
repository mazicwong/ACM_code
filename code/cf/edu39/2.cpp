#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
int main()
{
    cin>>a>>b;
    while(a!=0 && b!=0)
    {
        if (a>=2*b)
        {
            ll tmp = a/b;
            if(tmp%2==1) tmp--;
            a=a-tmp*b;
        }
        else if (b>=2*a)
        {
            ll tmp = b/a;
            if(tmp%2==1) tmp--;
            b=b-tmp*a;
        }
        else break;
    }
    cout<<a<<' '<<b;
    return 0;
}
