#include <bits/stdc++.h>
using namespace std;
struct Node{
    int w;
    string color;
    bool operator < (const Node &rhs) const {
        return w > rhs.w;
    }
}node[105];

bool cmp(const Node a,const Node b)
{
    return a.w>b.w;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>node[i].w>>node[i].color;
        }
        sort(node,node+n);
        for(int i=0;i<n;i++)
        {
            cout << node[i].color << endl;
        }
    }
    return 0;
}
