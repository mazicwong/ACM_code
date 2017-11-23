/*************************************************************************
	> File Name: q.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月30日 星期三 00时39分35秒
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


#include <bits/stdc++.h>
using namespace std;
vector<int> g[200010];
int n, arr[200010], dp[200010][2], fa[200010];
queue<int> Q;
void bfs() {
	Q.push(1);
	dp[1][0] = arr[1]; dp[1][1] = 0;
	while (!Q.empty()) {
		int w = Q.front(); Q.pop();
        for (int i=0;i<g[w].size();i++)
		//for (auto t: g[w]) 
        {
            int t = g[w][i];
			if (t == fa[w]) continue;
			fa[t] = w;
			dp[t][0] = __gcd(dp[w][0], arr[t]);
			dp[t][1] = max(dp[w][0], dp[w][1] ? __gcd(dp[w][1], arr[t]) : arr[t]);
			Q.push(t);
		}
	}
}
int main(){
    freopen("in","r",stdin);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	int u, v;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v); g[v].push_back(u);
	}
	bfs();
	for (int i = 1; i <= n; i++)
		cout << max(dp[i][0], dp[i][1]) << (i == n ? '\n' : ' ');
	return 0;
}
