/*************************************************************************
	> File Name: 3.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月25日 星期五 01时10分06秒
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
const int maxn = 1e5+5;
bool vis[maxn];

typedef pair<int,int> PII;
PII a[maxn];
int raw[maxn];

priority_queue<int, vector<int>, greater<int> > Q[maxn];
int main()
{
    freopen("in3","r",stdin);
    int n;cin>>n;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&raw[i]);
        a[i].first=raw[i];
        a[i].second=i;
    }
    sort(a,a+n);

    memset(vis,0,sizeof(vis));

    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if (vis[i]) continue;
        int cur = i;

        do
        {
            Q[cnt].push(a[cur].second);
            cur = a[cur].second;
            vis[cur]=1;
        }while(a[i].first != a[cur].first);

        if (i!=cur) Q[cnt].push(a[cur].second);
       
        cnt++;
    }

    cout << cnt << endl;
    for (int i=0;i<cnt;i++)
    {
        cout << Q[i].size();
        //printf("%d",Q.size());
        while(!Q[i].empty())
        {
            printf(" %d",Q[i].top()+1);
            Q[i].pop();
        }
        puts("");
    }
    return 0;
}
