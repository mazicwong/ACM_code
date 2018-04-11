#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <time.h>
using namespace std;

const int maxn = 1000+5;
int a[maxn];

map<pair<int,int>,int> mp;
struct Node{
    int x,y;
}node[maxn];
inline int read()
{
    int x=0,f=1; char ch =getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const int mod = 19260817;
int hash[mod];
void init()
{
    memset(hash,-1,sizeof(hash));
}
void insert(int x,int y)
{
    int h = (x*x+y*y)%mod;
    hash[h] = 1;
}
bool query(int x,int y)
{
    int h = (x*x+y*y)%mod;
    return hash[h]==1;
}
int main()
{
    int n;
    while(cin>>n && n)
    {
        mp.clear();
        init();
        for(int i=0;i<n;i++)
        {
            node[i].x=read();  node[i].y=read();
            insert(node[i].x, node[i].y);
            //mp[make_pair(node[i].x,node[i].y)] = 1;
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                //if(node[i].x==node[j].x || node[i].y==node[j].y) continue;
                int x3 = node[i].x - (node[i].y - node[j].y);
                int y3 = node[i].y + (node[i].x - node[j].x);
                int x4 = node[j].x - (node[i].y - node[j].y);
                int y4 = node[j].y + (node[i].x - node[j].x);
                //pair<int,int> tmp = make_pair(x3,y3);
                //pair<int,int> tmp2 = make_pair(x4,y4);
                //if(mp[tmp]==1 && mp[tmp2]==1) ans++;
                if(query(x3,y3)==1 && query(x4,y4)==1) ans++;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                //if(node[i].x==node[j].x || node[i].y==node[j].y) continue;
                int x3 = node[i].x + (node[i].y - node[j].y);
                int y3 = node[i].y - (node[i].x - node[j].x);
                int x4 = node[j].x + (node[i].y - node[j].y);
                int y4 = node[j].y - (node[i].x - node[j].x);
                //pair<int,int> tmp = make_pair(x3,y3);
                //pair<int,int> tmp2 = make_pair(x4,y4);
                //if(mp[tmp]==1 && mp[tmp2]==1) ans++;
                if(query(x3,y3)==1 && query(x4,y4)==1) ans++;
            }
        }
        cout << ans/4 << endl;
    }
    return 0;
}
