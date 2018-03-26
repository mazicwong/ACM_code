#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
struct Node{
    int a,b;
}node[maxn];
bool cmp(const Node a,const Node b)
{
    return a.b-a.a > b.b-b.a; //先放cost小,且need大的
    /*if(a.a+b.b<a.b+b.a) return 1;
    else if(a.a+b.b==a.b+a.a) return a.b>b.b;
    return 0;*/
}
int main()
{
    //freopen("in","r",stdin);
    int t;cin>>t;
    while(t--)
    {
        int v,n; cin>>v>>n;
        for(int i=0;i<n;i++) 
        {
            cin>>node[i].a>>node[i].b;//cost,need
        }
        sort(node,node+n,cmp);
        int now_v=v;
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            if(now_v >= node[i].b)
            {
                now_v -= node[i].a;
            }
            else
            {
                flag=false;
                break;
            }
        }
        if(flag==false||now_v<0) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}
