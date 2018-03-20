#include<iostream>  
#include<queue>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
struct node  
{  
    int x,y;  
    int time;  
    int pos;  
};  
int n,m,ex,ey,map[100][100];  
bool vis[100][100][4];  
int movex[4]={-1,0,1,0},movey[4]={0,1,0,-1};  
int GetPos(char *str)  
{  
    if(!strcmp(str,"north"))  
    return 0;  
    if(!strcmp(str,"east"))  
    return 1;  
    if(!strcmp(str,"south"))  
    return 2;  
    return 3;  
}  
bool CanGo(int x,int y)  
{  
    if(x<1||x>=n||y<1||y>=m)  
        return false;  
    if(map[x][y]||map[x+1][y]||map[x][y+1]||map[x+1][y+1])  
    return false;  
    return true;  
}  
int main()  
{  
    while(scanf("%d%d",&n,&m)&&(n||m))  
    {  
    for(int i=1;i<=n;i++)  
        for(int j=1;j<=m;j++)  
        scanf("%d",&map[i][j]);  
    node ita;  
    memset(vis,0,sizeof(vis));  
    scanf("%d%d",&ita.x,&ita.y);  
    scanf("%d%d",&ex,&ey);  
    char op[20];  
    scanf("%s",op);  
    ita.pos=GetPos(op);  
    ita.time=0;  
    queue<node> a;  
    a.push(ita);  
    vis[ita.x][ita.y][ita.pos]=1;  
    int ans=-1;  
    if(ita.x==ex&&ita.y==ey)  
    {  
        printf("0\n");  
        continue;  
    }  
    if(!CanGo(ex,ey))  
    {  
        printf("-1\n");  
        continue;  
    }  
    while(!a.empty())  
    {  
        node ita=a.front();  
        a.pop();  
        int itx=ita.x;  
        int ity=ita.y;  
        for(int i=1;i<=3;i++)  
        {  
        itx+=movex[ita.pos];  
        ity+=movey[ita.pos];  
        if(!CanGo(itx,ity))  
            break;  
        if(itx==ex&&ity==ey)  
        {  
            ans=ita.time+1;  
            break;  
        }  
        if(!vis[itx][ity][ita.pos])  
        {  
            node itb;  
            itb.x=itx;  
            itb.y=ity;  
            itb.time=ita.time+1;  
            itb.pos=ita.pos;  
            vis[itx][ity][itb.pos]=1;  
            a.push(itb);  
        }  
        }  
        for(int i=0;i<4;i++)  
        {  
        if(max(ita.pos,i)-min(ita.pos,i)==2)  
            continue;  
        if(vis[ita.x][ita.y][i])  
            continue;  
        node itb=ita;  
        itb.time=ita.time+1;  
        itb.pos=i;  
        vis[itb.x][itb.y][itb.pos]=1;  
        a.push(itb);  
        }  
        if(ans!=-1)  
        break;  
    }  
    if(ans!=-1)  
        printf("%d\n",ans);  
    else  
        printf("-1\n");  
    }  
    return 0;  
}  
