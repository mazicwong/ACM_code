#include <bits/stdc++.h>
using namespace std;
//[1,10000]
//其他好说，注意空图是树这个点。。
const int maxn = 1e4+5;
int node[maxn];
int main()
{
    int u,v;
    int cas=1;
    int in[maxn];
    int out[maxn];
    while(1)
    {
        bool ff=1;
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        int bian=0;
        map<int,int> mp;
        int cnt=0;
        while(scanf("%d%d",&u,&v)!=EOF)
        {
            if(u==-1 && v==-1){ff=false;break;}
            if(u==0 && v==0) break;
            if(mp[u]==0) mp[u]=++cnt;
            if(mp[v]==0) mp[v]=++cnt;
            out[mp[u]]++;
            in[mp[v]]++;
            bian++;
        }
        if(ff==false)break;
        if(cnt==0)
        {
            cout << "Case " << cas++ << " is a tree." << endl;
            continue;
        }
        /*
        if(bian!=cnt-1)
        {
            cout << "Case " << cas++ << " is not a tree." << endl;
            continue;
        }*/
        int n = cnt;
        int in1=0;
        int in0=0;
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            if(in[i]==1)
                in1++;
            else if(in[i]==0)
                in0++;
            else {flag=false;break;}
        }
        if(flag==true && in0==1)
            cout << "Case " << cas++ << " is a tree." << endl;
        else cout << "Case " << cas++ << " is not a tree." << endl;
    }
    return 0;
}
