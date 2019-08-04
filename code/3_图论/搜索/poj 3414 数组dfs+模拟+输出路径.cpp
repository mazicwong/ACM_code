/*************************************************************************
	> File Name: poj3414.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月18日 星期二 16时21分26秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 100+5;
int aa,bb,ee;
int vis[maxn][maxn];
bool flag; //能否抵达
int ans;  //总步数
struct node{
    int k1,k2; //两杯水的状态
    int op;  //操作
    int step; //记录步数
    int pre; //记录前一步下标
}q[maxn*maxn]; //队列
int id[maxn*maxn]; //记录最终操作在队列中的编号
int lastIndex; //最后一个的编号

void bfs()
{
    node a,next;
    int head=0,tail=0;
    q[tail].k1=q[tail].k2=0;
    q[tail].op=q[tail].step=q[tail].pre=0;
    tail++;
    while(head<tail) //拿数组当队列用，队列的输出路径有点麻烦
    {
        a = q[head]; //取队首
        head++; //弹出
        if (a.k1==ee || a.k2==ee) //返回
        {
            flag = 1;
            ans = a.step;
            lastIndex = head-1; //最后一步也要记录
        }
        for (int i=1;i<=6;i++) //6个操作
        {
            switch(i) 
            {
                case 1: //fill(1)
                    next.k1=aa;
                    next.k2=a.k2;
                    break;
                case 2: //fill(2)
                    next.k1=a.k1;
                    next.k2=bb;
                    break;
                case 3: //drop(1)
                    next.k1=0;
                    next.k2=a.k2;
                    break;
                case 4: //drop(2)
                    next.k1=a.k1;
                    next.k2=0;
                    break;
                case 5: //pour(1,2)
                    if(a.k1+a.k2<=bb)
                    {
                        next.k1=0;
                        next.k2=a.k1+a.k2;
                    }
                    else
                    {
                        next.k1=a.k1-(bb-a.k2);
                        next.k2=bb;
                    }
                    break;
                case 6: //pour(2,1)
                    if (a.k1+a.k2<=aa)
                    {
                        next.k1=a.k1+a.k2;
                        next.k2=0;
                    }
                    else
                    {
                        next.k1=aa;
                        next.k2=a.k2-(aa-a.k1);
                    }
                    break;
            }
            next.op=i;
            if(!vis[next.k1][next.k2])
            {
                vis[next.k1][next.k2]=1;
                next.step = a.step+1;
                next.pre=head-1;
                q[tail].k1=next.k1; q[tail].k2=next.k2;
                q[tail].op=next.op; q[tail].step=next.step; q[tail].pre=next.pre;
                tail++;
                if (next.k1==ee || next.k2==ee)
                {
                    flag = 1;
                    ans = next.step;
                    lastIndex = tail-1;
                    return;
                }
            }
        }
    }
}

int main()
{
    freopen("in","r",stdin);
    while(scanf("%d%d%d",&aa,&bb,&ee)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        vis[0][0]=1;
        flag = 0;
        ans = 0;
        bfs();
        if (!flag)
            puts("impossible\n");
        else
        {
            printf("%d\n",ans);
            id[ans] = lastIndex;
            for (int i=ans-1;i>=1;i--)
                id[i] = q[id[i+1]].pre;
            for (int i=1;i<=ans;i++)
            {
                switch(q[id[i]].op)
                {
                    case 1: printf("FILL(1)\n"); break;
                    case 2: printf("FILL(2)\n"); break;
                    case 3: printf("DROP(1)\n"); break;
                    case 4: printf("DROP(2)\n"); break;
                    case 5: printf("POUR(1,2)\n"); break;
                    case 6: printf("POUR(2,1)\n"); break;
                }
            }
        }
    }
    return 0;
}
