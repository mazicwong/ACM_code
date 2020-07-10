/*************************************************************************
	> File Name: poj3087.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月18日 星期二 13时13分56秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 100 + 5;

int n;//number of chips in each stack
string ee;
struct node{
    string x;
    int step;
};
map<string,int> vis;

string trans(string s1,string s2)
{
    string s12 = "";
    for (int i=0;i<n;i++)
    {
        s12 += s2[i];
        s12 += s1[i];
    }
    return s12;
}

int bfs(string s1,string s2)
{
    node a,next;
    queue<node> Q;
    string s12 = trans(s1,s2);
    a.x=s12, a.step=1;
    vis[a.x]=1;
    Q.push(a);

    if (s12 == ee)
        return 1;
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        s1 = a.x.substr(0,n);
        s2 = a.x.substr(n,2*n);
        next.x = trans(s1,s2);
        next.step = a.step+1;
        if(next.x==ee)
            return next.step;
        if(vis[next.x])
            return -1;  //不是回溯了，这里直接退出。因为不可能找到答案了
        vis[next.x] = 1;
        Q.push(next);
    }
    return -1;
}

int main()
{
    freopen("in","r",stdin);
    int T;
    cin >> T;
    string s1,s2;
    int cas = 1;
    while(T--)
    {
        vis.clear();
        cin >> n;
        cin >> s1 >> s2 >> ee;
        int ans = bfs(s1,s2);
        cout << cas++ << ' ' << ans << endl;
    }
    return 0;
}
