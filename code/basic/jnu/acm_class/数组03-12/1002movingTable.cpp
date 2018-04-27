//The famous ACM (Advanced Computer Maker) Company has rented a floor
#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int s[maxn];
int t[maxn];
int cnt[maxn];
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int st,en;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)
        {
            cin>>st>>en;
            st = (st+1)>>1;
            en = (en+1)>>1;
            if(st>en) swap(st,en);
            for(int k=st;k<=en;k++)
                cnt[k]++;
        }
        int ans=-1;
        for(int i=1;i<=200;i++)
            ans = max(ans,cnt[i]);
        cout << ans*10 << endl;
    }
    return 0;
}
