#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n,m,k; cin>>n>>m>>k;
    if(k<=n-1){
        cout << k+1 << ' ' << '1';
    }
    else if(k<=n-1+m-1){
        cout << n << ' ' << k-(n-2);
    }
    else{
        k -= (n-1+m-1);
        //cout << k << endl;
        int tmp = k/(m-1);
        if(k%(m-1)!=0) tmp++;
        //cout << tmp << endl;
        cout << n-tmp << ' ';
        int qq = k%(m-1); if(qq==0) qq=m-1;
        if(tmp%2==1) // left
        {
            cout << m-qq+1;
        }
        else
        {
            cout << 1+qq;
        }
    }
    return 0;
}
