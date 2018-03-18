#include <bits/stdc++.h>
using namespace std;
int n,m,k,d;

//从蓝色点出发，bfs到绿色点
const int maxn = 100+5;
int mp[maxn][maxn];
int path[maxn][maxn];
struct Node{
    int x,y;
    int c;
}node[maxn*maxn];

int to[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool check(int x,int y)
{
    if(x<=0 || x>n || y<=0 || y>n)
        return false;
    if(mp[x][y]==-1) return false;
    return true;
}
struct noo{
    int x,y;
    int dep;
    noo(int _x=0,int _y=0,int _dep=0):x(_x),y(_y),dep(_dep){}
};
bool vis[maxn][maxn];
void bfs(int x,int y)
{
    int cccc=0;
    memset(vis,0,sizeof(vis));
    queue<noo> Q;
    noo now; now.x=x; now.y=y; now.dep=0;
    Q.push(now);
    while(!Q.empty())
    {
        noo now=Q.front(); Q.pop();
        int x=now.x,y=now.y;
        int dep=now.dep;
        vis[x][y]=1;
        //cout << x << "----------" << y << endl;
        for(int i=0;i<4;i++)
        {
            int nx=x+to[i][0];
            int ny=y+to[i][1];
            int ndep=dep+1;
            if(!check(nx,ny)) continue;
            if(vis[nx][ny]) continue;
            //if(mp[nx][ny]==2) return ndep;
            if(mp[nx][ny]==1)
            {
                vis[nx][ny]=1;
                path[nx][ny]=min(path[nx][ny],ndep);
                cccc++;
                if(cccc==k) return;
            }
            noo tmp; tmp.x=nx; tmp.y=ny; tmp.dep=ndep;
            Q.push(tmp);
        }
    }
}

struct NNode{
    int x,y;
}nnode[maxn*maxn];
int mmp[maxn][maxn];
int vvis[maxn][maxn];
int main()
{
    memset(mp,0,sizeof(mp));
    cin>>n>>m>>k>>d;
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y); //分店
        node[cnt].x=x; node[cnt].y=y;
        cnt++;
        mp[x][y] = 2;
    }
    int ccnt=0;
    memset(mmp,0,sizeof(mmp));
    for(int i=1;i<=k;i++)
    {
        int x,y,c; scanf("%d%d%d",&x,&y,&c);
        mp[x][y] = 1;
        nnode[ccnt].x=x; nnode[ccnt].y=y;
        ccnt++;
        //客户坐标，订餐量
        //node[cnt].x=x; node[cnt].y=y; node[cnt].c=c;
        //cnt++;
        mmp[x][y]+=c;
    }
    for(int i=1;i<=d;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y); //不通
        mp[x][y] = -1;
    }

    memset(path,0x3f3f3f3f,sizeof(path));
    for(int i=0;i<cnt;i++) bfs(node[i].x,node[i].y);
    
    long long ans=0;
    memset(vvis,0,sizeof(vvis));
    for(int i=0;i<ccnt;i++)
    {
        if(vvis[nnode[i].x][nnode[i].y]) continue;
        ans += path[nnode[i].x][nnode[i].y]*mmp[nnode[i].x][nnode[i].y];
        vvis[nnode[i].x][nnode[i].y]=1;
    }
    cout << ans;

    
    /*long long ans=0;
    for(int i=0;i<cnt;i++)
    {
        long long tmp=bfs(node[i].x,node[i].y);
        ans+=tmp*node[i].c;
    }
    cout << ans;*/
    return 0;
}
