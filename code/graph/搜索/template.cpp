/* 
 * dfs
 */  
const int maxn=100;  
bool vis[maxn][maxn]; //访问标记
int mp[maxn][maxn];   //坐标范围
int to[4][2]={{0,1},{0,-1},{1,0},{-1,0}}; //方向向量,(x,y)周围的四个方向

bool CheckEdge(int x,int y) // 边界条件和约束条件的判断  
{  
    if(!vis[x][y] && x>=0 && x<=n && y>=0 && y<=m) // 满足条件  
        return 1;
    else // 与约束条件冲突  
        return 0;  
}  
  
void dfs(int x,int y)  
{  
    vis[x][y]=1; // 标记该节点被访问过  
    if(mp[x][y]==G) // 出现目标态G
    {
        ...... // 做相应处理  
        return;
    }
    for(int k=0;k<4;k++)
    {  
        int nx = x+to[k][0];
        int ny = y+to[k][1];
        if (CheckEdge(nx,ny))
        {
            dfs(nx,ny);
        }
    }  
    return; // 没有下层搜索节点，回溯  
}

int main()  
{  
    ......
    return 0;  
}  





/*
 * bfs
 * 5步+循环(越界+返回+回溯)
 */
const int maxn=100;  
bool vis[maxn][maxn]; // 访问标记  
int to[4][2]={{0,1},{0,-1},{1,0},{-1,0}}; // 方向向量,(x,y)周围的四个方向  
  
struct node   //BFS队列中的状态数据结构  
{  
    int x,y;  //坐标位置  
    int step; //搜索步数统计器  
}a[maxn];
  
boolCheckState(node s) // 约束条件检验(访问+越界)
{  
    if(!vis[s.x][s.y] && ...) // 满足条件
        return 1;  
    else // 约束条件冲突  
    return 0;  
}  

int bfs(node st)
{  
    queue<node> Q; // BFS 队列  
    node now,next; // 定义2 个状态，当前和下一个  
    st.step=0; // 计数器清零  
    Q.push(st); // 入队     
    vis[st.x][st.y]=1; // 访问标记  
    while(!Q.empty())  
    {
        now=Q.front(); // 取队首元素进行扩展  
        if(now==G) // 出现目标态，此时为step的最小值，可以退出即可  
        {
            ...... // 做相关处理
            return now.step;
        }
        for(int i=0;i<4;i++)
        {
            next.x = now.x+to[i][0]; // 按照规则生成   下一个状态  
            next.y = now.y+to[i][1];  
            next.step = now.step+1; // 计数器加1  
            if(CheckState(next)) // 如果状态满足约束条件则入队
            {
                Q.push(next);  
                vis[next.x][next.y]=1; //访问标记
            }
        }
        Q.pop(); // 队首元素出队  
    }
    return 0;
}
int main()  
{  
	......  
	return 0;  
}  



