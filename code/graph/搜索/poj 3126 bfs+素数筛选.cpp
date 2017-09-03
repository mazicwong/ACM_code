/*************************************************************************
	> File Name: poj3126.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月18日 星期二 11时14分43秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 1e4+5;
int n;
int ss,ee;
bool prime[maxn];
bool vis[maxn];
struct node{
    int x;
    int step;
};

void isPrime()
{
    memset(prime,1,sizeof(prime));
    prime[0]=prime[1]=0;
    for (int i=2;i*i<maxn;i++)
        if (prime[i])
            for (int j=i*i;j<maxn;j+=i)
                prime[j] = 0;
}

int bfs()
{
    node a,next;
    queue<node> Q;
    a.x=ss, a.step=0;
    Q.push(a);
    vis[ss]=1;
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        for (int i=1;i<=1000;i*=10) //每次4个数
        {
            for (int j=0;j<10;j++) //每个数共有10种变化
            {
                if (i==1000 && j==0)
                    continue; //边界
                next.x = a.x%i + j*i + a.x/(i*10)*(i*10);
                next.step = a.step + 1;
                if (next.x == ee)
                    return next.step; //搜到，返回
                if (prime[next.x])
                {
                    if (vis[next.x])
                        continue; //回溯
                    vis[next.x]=1;
                    Q.push(next);
                }
            }
        }
    }
    return -1;
}


int main()
{
    freopen("in","r",stdin);
    isPrime();
    cin >> n;
    while(n--)
    {
        memset(vis,0,sizeof(vis));
        cin >> ss >> ee;
        if (ss == ee)
            cout << "0" << endl;
        else
            cout << bfs() << endl;
    }
    return 0;
}
