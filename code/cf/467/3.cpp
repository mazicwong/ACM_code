#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    //k  off
    //t   2t
    //d  circule
    
    ll k,d,t; cin>>k>>d>>t;
    double ans = 0;
        if (k%d == 0)
            ans = t;
        else
        {
            double tmp = k/d;
            double m = (tmp+1)*d;
            double ss = k+(m-k)*0.5;
            ll cnt = t/ss;
            ans += cnt*m;
            double left_time = t-ss*cnt;
            if(left_time<=k) ans+=left_time;
            else ans+=k+(left_time-k)*2;
        }
        printf("%.10lf",ans);
        //cout << ans;
    return 0;
}
