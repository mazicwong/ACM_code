#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int n; cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    int flag=0;
    set<int> st;
    for (int i=0;i<n;i++)
    {
        if (a[i]==0)
            flag=1;
        st.insert(a[i]);
    }
    int ans = st.size();
    if (flag==1)
        ans--;
    cout << ans;

    return 0;
}
