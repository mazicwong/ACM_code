#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000+5;
struct Node{
    int key;
    int timee;
    bool st;
}node[maxn*2];

bool cmp(const struct Node a, const struct Node b)
{
    if(a.timee==b.timee)
    {
        if(a.st==b.st)
        {
            return a.key<b.key;
        }
        else return a.st<b.st;
    }
    else return a.timee<b.timee;
}

int vis[1000+5]; //格子
int pos[1000+5]; //key的位置
int main()
{
    int n,k; cin>>n>>k;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        vis[i]=i;
        pos[i]=i;
    }
    for(int i=0;i<k;i++)
    {
        int key,st,len;
        cin>>key>>st>>len;
        int en=st+len;
        node[cnt].key=key; node[cnt].timee=st; node[cnt++].st=1;
        node[cnt].key=key; node[cnt].timee=en; node[cnt++].st=0;
    }
    sort(node,node+cnt,cmp);
   // for(int i=0;i<cnt;i++)
   // cout << node[i].timee << ' ' << node[i].st << endl;;
    for(int i=0;i<cnt;i++)
    {
        int key=node[i].key;
        int tt=node[i].timee;
        int sst=node[i].st;
        if(sst==1)
        {
            //取出
            vis[pos[key]]=-1;
        }
        else
        {
            //放入
            for(int i=1;i<=n;i++)
            {
                if(vis[i]==-1)
                {
                    vis[i]=key;
                    pos[key]=i;
                    break;
                }
            }
        }
    }
    for(int i=1;i<n;i++)
        cout << vis[i] << ' ';
    cout<<vis[n];
    return 0;
}
