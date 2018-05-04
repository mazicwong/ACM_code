#include <bits/stdc++.h>
using namespace std;
void solve()
{
    double lat1,lng1,lat2,lng2;
    cin>>lat1>>lng1>>lat2>>lng2;
    lat1 = abs(lat1-lat2);
    lng1 = abs(lng1-lng2);
    double r = 6371009;
    cout << (double)((double)802333*802333-r*r-r*r-2*r*r) << endl;
}

int main()
{
    int t;cin>>t;
    while(t--)
    solve();
    return 0;
}
