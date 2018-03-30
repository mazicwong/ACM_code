#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 105;
struct Node{
    int st,en;
}node[maxn];
bool cmp(const Node a, const Node b)
{
    return a.en<b.en;
}
int main()
{
    while(cin>>n && n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>node[i].st>>node[i].en;
        }
        sort(node,node+n,cmp);
        int now=node[0].en;
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(node[i].st>=now)
            {
                now=node[i].en;
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
