/*************************************************************************
	> File Name: hdu1043.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月19日 星期三 18时05分22秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1e6+5; //最多是9!/2

int to[4][2]={{-1,0},{1,0},{0,-1},{0,1}}; //u,d,l,r (原点左上角)
char indexs[5]="durl"; //跟to要相反，因为反向搜索
int fac[]={1,1,2,6,24,120,720,5040,40320,362880};//康拖展开判重
//         0!1!2!3! 4! 5!  6!  7!   8!    9!
bool vis[maxn];
string path[maxn];//记录路径
int cantor(int s[]) //康托展开求该序列的哈希值
{
    int sum=0;
    for (int i=0;i<9;i++)
    {
        int num=0;
        for (int j=i+1;j<9;j++)
            if (s[j]<s[i])
                num++;
        sum+=(num*fac[9-i-1]);
    }
    return sum+1;
}
struct node{
    int s[9];
    int loc; //'0'的位置
    int status; //康托展开hash值
    string path; //路径
};
int aim=46234;//123456780的康托展开hash
queue<node> Q;
void bfs()
{
    while(!Q.empty()) Q.pop();
    memset(vis,0,sizeof(vis));
    node a,next;
    for (int i=0;i<8;i++)
        a.s[i]=i+1;
    a.s[8]=0; a.loc=8; a.status=aim; a.path="";
    Q.push(a);
    path[aim]="";
    while(!Q.empty())
    {
        a=Q.front();
        Q.pop();
        
        for (int i=0;i<4;i++)
        {
            int nx = a.loc/3 + to[i][0];
            int ny = a.loc%3 + to[i][1];
            if(nx<0 || nx>2 || ny<0 || ny>2)
                continue;
            next=a;
            next.loc=nx*3+ny;
            next.s[a.loc]=next.s[next.loc];
            next.s[next.loc]=0;
            next.status=cantor(next.s);
            if(!vis[next.status])
            {
                vis[next.status]=true;
                next.path=indexs[i]+next.path;
                Q.push(next);
                path[next.status]=next.path;
            }
        }
    }


}

int main()
{
    freopen("in","r",stdin);
    char str[50];
    node now;
    bfs();
    while(fgets(str,sizeof(str),stdin)!=NULL)
    {
        int cur=0;
        for (int i=0;i<40;i++)
        {
            if(str[i]>='1'&&str[i]<='9')
            {
                now.s[cur]=str[i]-'0';
                cur++;
            }
            else if (str[i]=='x')
            {
                now.s[cur]=0;
                now.loc=cur;
                cur++;
            }
        }
        now.status=cantor(now.s);
        if(vis[now.status])
            cout << path[now.status] << endl;
        else
            cout << "unsolvable" << endl;

    }
    return 0;
}
