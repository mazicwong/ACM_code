#include <bits/stdc++.h>
using namespace std;
const int maxn = 200+5;
int n;
struct Node{
    int st,en;
}node[maxn];
bool cmp(const Node a,const Node b)
{
    if(a.en==b.en) return a.st<b.st;
    return a.en<b.en;
}
bool vis[maxn];
int tmp[maxn<<2];
int main()
{
    //freopen("in","r",stdin);
    int t;cin>>t;
    while(t--)
    {
        cin>>n;
        memset(vis,0,sizeof(vis));
        memset(tmp,0,sizeof(tmp));
        for(int i=0;i<n;i++)
        {
            cin>>node[i].st>>node[i].en;
            if(node[i].st > node[i].en)
             swap(node[i].st,node[i].en);
            if(node[i].st%2==0) tmp[node[i].st-1]++;
            if(node[i].en%2==1) tmp[node[i].en+1]++;
            for(int j=node[i].st;j<=node[i].en;j++) tmp[j]++;
        }
        //sort(node,node+n,cmp);
        int ans=0;
        for(int i=0;i<=(maxn*2);i++) ans=max(ans,tmp[i]);
        cout<<(ans*10)<<endl; continue;
        while(1)
        {
            int now=0;
            bool flag=false;
            for(int i=0;i<n;i++)
            {
                if(vis[i]==0)
                {
                    flag=true;
                    vis[i]=1;
                    now=node[i].en;
                    break;
                }
            }
            if(flag==false) break;
            for(int i=0;i<n;i++)
            {
                if(vis[i]==0)
                {
                    if(node[i].st>now)
                    {
                        now=node[i].en;
                        vis[i]=1;
                    }
                }
            }
            ans+=10;
        }
        cout<<ans<<endl;
    }
    return 0;
}
