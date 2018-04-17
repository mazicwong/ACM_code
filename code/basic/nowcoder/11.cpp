#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++) cin>>a[i];
        if(n==1)
        {
            cout << "0 " << a[0] << endl;
            continue;
        }
        for(int i=0;i<n;i++) a[i]+=(a[i]&1);
        int ans=0;
        set<int> st;
        while(1)
        {
            int tmp0=a[n-1]/2;
            a[n-1]/=2;// a[n-1]+=(a[n-1]&1);
            for(int i=n-2;i>=0;i--)
            {
                a[i+1] += a[i]/2;
                a[i]/=2; //a[i]+=(a[i]&1);
                //st.insert(a[i+1]);
            }
            a[0]+=tmp0;
            st.insert(a[0]);
            st.clear();
            for(int i=0;i<n;i++) a[i]+=(a[i]&1), st.insert(a[i]);
            //for(int i=0;i<n;i++) cout << a[i] << ' '; cout << endl;
            ans++;
            if(st.size()==1)
            {
                cout << ans << " " << a[0] << endl;
                break;
            }
        }
    }
    return 0;
}
