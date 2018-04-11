#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int c[maxn];

int n,m; 
bool check()
{
    for(int i=1;i<=n;i++)
    {
        if(c[i]==0) return false;
    }
    return true;
}
void upd()
{
    for(int i=1;i<=n;i++) c[i]--;
}
int main()
{
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        int tmp; cin>>tmp; c[tmp]++;
        if(check()==true)
        {
            upd();
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
