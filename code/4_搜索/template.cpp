1.bfs
2.dfs
  
1. 迷宫bfs
const int maxn = 100+5;
char mp[maxn][maxn];
int n,m; 
bool vis[maxn][maxn];
int to[4][2]={{0,1},{0,-1},{1,0},{-1,0}}; // 方向向量，(x,y)周围的四个方向  
struct node // BFS 队列中的状态数据结构  
{  
    int x,y; // 坐标位置  
    int step; // 搜索步数统计器  
};
node st, en;

bool check(node nxt)
{
    if(!vis[nxt.x][nxt.y] && nxt.x>=0 && nxt.x<n && nxt.y>=0 && nxt.y<m && mp[nxt.x][nxt.y]!='1') return 1;
    else return 0;
}

void bfs(node st)
{
    queue<node> Q;
    node now,nxt;
    Q.push(st);
    vis[st.x][st.y] = 1;
    while(!Q.empty())
    {
        now = Q.front();
        if(now.x == en.x && now.y==en.y){
            cout << now.step;
            return;
        }
        for(int i=0;i<4;i++)
        {
            nxt.x = now.x + to[i][0];
            nxt.y = now.y + to[i][1];
            nxt.step = now.step + 1;
            if (check(nxt))
            {
                Q.push(nxt);
                vis[nxt.x][nxt.y] = 1;
            }
        }
        Q.pop();
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>mp[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[i][j] == 'S') st.x=i, st.y=j, st.step=0;
            if(mp[i][j] == 'E') en.x=i, en.y=j, en.step=0;
        }
    }
    memset(vis,0,sizeof(vis));
    bfs(st);
    return 0;
}
