//hdu1240
//You're in space.
//You want to get home.
//There are asteroids.
//You don't want to hit them.
#include <bits/stdc++.h>
using namespace std;
int n;
int st_x,st_y,st_z;
int en_x,en_y,en_z;
const int maxn = 12;
char mp[maxn][maxn][maxn];
int to[6][3]={
    {0,0,1},{0,0,-1},
    {0,1,0},{0,-1,0},
    {1,0,0},{-1,0,0}
};
bool check(int x,int y,int z)
{
    if(x<0||x>n-1||y<0||y>n-1||z<0||z>n-1) return 0;
    if(mp[z][x][y]=='X') return 0;
    return 1;
}
struct node{
    int x,y,z;
    int dep;
};
int bfs()
{
    queue<node> Q;
    node now; 
    now.x=st_x; now.y=st_y; now.z=st_z;now.dep=0; Q.push(now);
    if(now.x==en_x && now.y==en_y && now.z==en_z) return now.dep;
    while(!Q.empty()){
        now = Q.front(); Q.pop();
        node nxt;
        for(int i=0;i<6;i++)
        {
            nxt.x = now.x+to[i][0];
            nxt.y = now.y+to[i][1];
            nxt.z = now.z+to[i][2];
            nxt.dep = now.dep+1;
            if(check(nxt.x,nxt.y,nxt.z)==false) continue;
            if(nxt.x==en_x && nxt.y==en_y && nxt.z==en_z) return nxt.dep;
            mp[nxt.z][nxt.x][nxt.y] = 'X';
            Q.push(nxt);
        }
    }
    return -1;
}

int main()
{
    //freopen("in","r",stdin);
    //ios::sync_with_stdio(false);
    string str;
    while(cin>>str)
    {
        cin>>n;
        for(int z=0;z<n;z++)  //mp[z][x][y]
        {
            for(int x=0;x<n;x++)
            {
                scanf("%s",mp[z][x]);
            }
        }

        cin>>st_x>>st_y>>st_z;
        cin>>en_x>>en_y>>en_z;
        cin>>str;
        int ans=bfs();
        if(ans==-1) cout << "NO ROUTE" << endl;
        else cout << n << ' ' << ans << endl;
    }
    return 0;
}
