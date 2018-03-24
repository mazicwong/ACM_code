#include <bits/stdc++.h>
using namespace std;
//开始结束, 求最多
const int maxn = 105;
int st[maxn]; int en[maxn];
int ans=0;
struct Node{
    int st;
    int en;
    bool operator <(const Node &x)const{
        if(en == x.en)
            return st<x.st;
        return en<x.en;
    }
}node[maxn];
int main()
{
    int n;
    while(cin>>n && n)
    {
        for(int i=0;i<n;i++) cin>>node[i].st>>node[i].en;
        sort(node,node+n);
        int now=0;
        ans=0;
        for(int i=0;i<n;i++)
        {
            if(now<=node[i].st)
            {
                now = node[i].en;
                ans++;
                continue;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
