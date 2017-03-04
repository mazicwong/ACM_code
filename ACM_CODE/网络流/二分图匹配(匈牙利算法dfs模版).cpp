#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
/*
二部图当且仅当没有奇圈
求二部图的最大匹配用匈牙利算法:
http://blomap.csdn.net/liwen_7/article/details/7797652
*/

//对应的点都是从1...n
//在main中处理好memset(map,0)跟map[a][b]=1就行
int uu, vv;//两边数目
bool map[maxn][maxn];//匹配情况
int pri[maxn];
bool vis[maxn];//检查某轮pri[v]是否已经被vis了
bool SearchPath(int u)
{
	for (int v = 1; v <= vv; v++)
	{
		if (map[u][v] && !vis[v])
		{
			vis[v] = true;
			if (pri[v] == -1 || SearchPath(pri[v]))
			{
				pri[v] = u;
				return true;
			}
		}
	}
	return false;
}
int MaxMatch()
{//匈牙利算法,返回二分图最大匹配数
	int ans = 0;
	memset(pri, -1, sizeof(pri));
	for (int u = 1; u <= uu; u++)
	{
		memset(vis, false, sizeof(vis));
		if (SearchPath(u))
			ans++;
	}
	return ans;
}