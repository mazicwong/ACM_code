/*************************************************************************
	> File Name: e.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月21日 星期六 10时29分39秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;
//给一个无向图,问大小为S的团有多少个,团就是完全图
//100个点,暴搜就行

const int maxn = 103;
int mp[maxn][maxn];
int n,m,s;
vector <int> G[maxn];
int ans=0;

void dfs(int u,int *tmp,int size)
{
    if (size==s)
    {
        ans++;
        return;
    }
    bool flag=true;
    for (int i=0;i<G[u].size();i++) //所有可能加入团的点
    {
        int v=G[u][i];
        flag=true;
        for (int j=1;j<=size;j++) //判段一个点是否可以加入团,此时团内的点都是小于i的,这里的点都是大于i的
        {
            if (mp[v][tmp[j]]==0)
            {
                flag=false;
                break;
            }
        }
        if (flag) //加入团
        {
            size++;
            tmp[size]=v;
            dfs(v,tmp,size);
            tmp[size]=0;
            size--;
        }
    }

}

int main()
{
    //freopen("in","r",stdin);
    int t;cin>>t;
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&s);
        memset(mp,0,sizeof(mp));
        for (int i=1;i<=n;i++) G[i].clear();
        int u,v;
        for (int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            mp[u][v]=mp[v][u]=1;
            if (u>v) swap(u,v);//按从小到大建图(不这样也可以,只要单向就行)
            G[u].push_back(v);//建成单向的,向团中加入点才不会有重复
        }
        ans=0;
        for (int i=1;i<=n;i++) //对每个点作为一个团搜索
        {
            int size=1;
            int tmp[maxn]; //暂时用的图,表示团中有多少个点
            tmp[1]=i;
            dfs(i,tmp,size);
        }
        cout << ans << endl;
    }
    return 0;
}
