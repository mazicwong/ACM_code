#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
struct Node{
    int st;
    int en;
    bool operator < (const Node rhs){
        if(en == rhs.en) return st<rhs.st;
        return en<rhs.en;
    }
}node[maxn];

int main()
{
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>node[i].st>>node[i].en;
    }
    sort(node,node+n);
    int cur=node[0].en;
    int ans=1;
    for(int i=1;i<n;i++)
    {
        if(cur<node[i].st)
        {
            cur=node[i].en;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
