/*************************************************************************
	> File Name: poj 3278.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月17日 星期一 18时35分10秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1e5+5;
int n,k;
bool vis[maxn];
struct node{
    int cur;
    int step;
};
int bfs()
{
    node a,next;
    queue<node> Q;
    a.cur=n, a.step=0;
    vis[a.cur]=1;
    Q.push(a);
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        for (int i=0;i<3;i++)
        {
            if (i==0)
            {
                next.cur=a.cur+1;
                next.step=a.step+1;
            }
            else if (i==1)
            {
                next.cur=a.cur-1;
                next.step=a.step+1;
            }
            else if (i==2)
            {
                next.cur=(a.cur<<1);
                next.step=a.step+1;
            }

            if (next.cur<0 || next.cur>=maxn) //排除出界情况(可以呼略的剪枝)
                continue;
            if (vis[next.cur])
                continue;
            if (next.cur==k)
                return next.step;
            vis[next.cur]=1;
            Q.push(next);
        }
    }
    return -1; //?????
}

int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    while(cin>>n>>k)
    {
        memset(vis,0,sizeof(vis));
        if (n>=k)
            cout << n-k << endl;
        else
            cout << bfs() << endl;
    }
    return 0;
}
