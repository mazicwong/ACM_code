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
const int maxn = 105;
vector<int> G[maxn];
//欧拉通路,经过所有点
int cnt=0;
inline void read(string str,int u)
{
    for(int i=0;i<str.size();i++)
    {
        char ch=str[i];
        int x=0;
        while(ch>='0' && ch<='9')  {x=x*10+ch-'0'; ch=str[++i];}
        cnt++;
        G[u].push_back(x);
        G[x].push_back(u);
    }
}

int m,n;
bool vis[maxn];
bool flag=false;
void dfs(int u, int fa, int cnt)
{
    //if(u==0 && fa!=-1)
    if((m==0&cnt==n) || (m!=0&&cnt==n-1))
    if(u==0)
    //if(cnt==n && u==0)
    {
        flag=true;
        return;
    }
    for(int i=0;i<G[u].size();i++)
    {
        if(G[u][i]==fa) continue;
        if(vis[G[u][i]]) continue;

        vis[G[u][i]]=true;
        dfs(G[u][i], u, cnt+1);
        vis[G[u][i]]=false;
    }
}

//给个图,给个起点m,问能否走到0,点有多个边,不能走重复点
int main()
{
    //freopen("in","r",stdin);
    string str;
    while(cin>>str && str=="START")
    {
        cin>>m>>n;getchar();
        string tmp;
        cnt=0;
        for(int i=0;i<n;i++)
        {
            getline(cin,tmp);
            read(tmp,i);
        }
        cin>>str;

        int even =0;
        vector<int> odd;
        cout << "************"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<G[i].size();j++)
            cout << G[i][j] <<' ';
            cout<<endl;
        }
        for(int i=0;i<n;i++)
        {
            G[i].erase(unique(G[i].begin(),G[i].end()),G[i].end());
            if(G[i].size()%2==0)
            {
                even++;
            }
            else odd.push_back(i);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<G[i].size();j++)
            cout << G[i][j] <<' ';
            cout<<endl;
        }

        if(even==n && m==0)
        {
            cout << "YES " << cnt << endl;
        }
        else 
        {
            //cout << "odd: "<<odd.size() << endl;
            if(odd.size()==2 && m!=0)
            {
                cout << "YES " << n << endl;
                continue;
            }
            else{
                cout << "NO" << endl;
                continue;
            }
            bool ff=false;
            if(odd.size()==2)
            {
                int arr[2];
                arr[0]=odd[0]; arr[1]=odd[1];
                sort(arr,arr+2);
                if(arr[0]==0 && arr[1]==m)
                {
                    cout << "YES " << (m==0?n:n-1)<<endl;
                    ff=true;
                }
            }
            if(false==ff) cout << "No" <<endl;
        }
        /*
        memset(vis,0,sizeof(vis));
        flag=false;
        dfs(m,-1,0);
        if(flag==true && m==0) cout << "YES " << n << endl;
        else if(flag==true && m!=0) cout << "YES " << n-1 << endl;
        else cout << "NO" <<endl;
        */
    }
    return 0;
}
