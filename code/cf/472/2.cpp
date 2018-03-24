#include <bits/stdc++.h>
using namespace std;
const int maxn = 50+5;
char mp[maxn][maxn];
int n,m; 

void ddebug()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<mp[i][j];
        }
        cout<<endl;
    }
}

bool vis_row[maxn];
bool vis_col[maxn];
void dfs(int x,int y)
{
    for(int i=0;i<n;i++)
    {
        if(vis_row[i]==1) continue;
        for(int j=0;j<n;j++)
        {
            if(vis_col[j]==1) continue;
            if(mp[i][j]=='#')
                dfs(i,j);
        }
    }
    vis_row[x]=1;
    vis_col[y]=1;
}

bool find(int x,int y)
{
    bool flag=true;
    if(vis_row[x]==true) return 1;
    for(int i=x+1;i<n;i++)
    {
        if(vis_row[i]==true) continue;
        bool ceng=false;
        for(int j=0;j<m;j++)
        {
            if(mp[x][j]=='#' && mp[i][j]=='#')
            {
                ceng=true;
                break;
            }
        }
        if(ceng==false) continue;
        for(int j=0;j<m;j++)
        {
            //if(vis_col[j]==true)continue;
            if(mp[x][j]==mp[i][j])
            {
                if(mp[i][j]=='#')
                    flag=find(i,j);
                if(flag==false)return false;
                continue;
            }
            else
            {
                return false;
            }
            /*
            if(mp[x][y]=='#')
            {
                if(mp[i][j]!='#')
                {
                    return false;
                }
                else
                {
                    if(find(i,j)==false) flag=false;
                }
            }
            else
            {
                if(mp[i][j]=='#')
                {
                    return false;
                }
            }*/
        }
    }
    vis_row[x]=true;
    return flag;
}
bool vis1[maxn];
bool check(int now)
{
    for(int i=now+1;i<n;i++)
    {
        if(vis1[i]==1)
        {
            for(int j=0;j<m;j++)
            {
                if(mp[i][j]!=mp[now][j])
                {
                    return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    //freopen("in","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        scanf("%s",&mp[i]);
    }
    memset(vis_row,false,sizeof(vis_row));
    memset(vis_col,false,sizeof(vis_col));

    for(int i=0;i<n;i++)
    {
        if(vis_row[i]==true)continue;
        for(int ii=0;ii<n;ii++) vis1[ii]=0;
        bool fff=false;
        for(int j=0;j<m;j++)
        {
            if(mp[i][j]=='#')
            {
                fff=true;
                for(int ii=i+1;ii<n;ii++)
                {
                    if(mp[ii][j]=='#') vis1[ii]=1;
                }
            }
        }
        if(fff==false)continue;
        if(check(i)==false)
        {
            cout<<"No";
            return 0;
        }
        for(int i=0;i<n;i++)
            if(vis1[i]==true) vis_row[i]=true;
        vis_row[i]=true;
    }
    cout<<"Yes";
    return 0;
}
