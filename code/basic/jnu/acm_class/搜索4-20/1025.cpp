//假设：
//S1 = 1
//S2 = 12
//S3 = 123
//S4 = 1234
//hdu 1597
#include <bits/stdc++.h>
using namespace std;
// n=1  s=1
// n=2  s=2..3
// n=3  s=4..6    1,3,6...  n(1+n)/2;
typedef long long ll;

int main()
{
    int k; cin>>k;
    for(int i=0;i<k;i++)
    {
        ll n; cin>>n;
        ll cnt=1;
        while(n>cnt)
            n-=cnt++;
        n%=9; if(n==0) n=9;
        cout << n << endl;
    }
    return 0;
}
