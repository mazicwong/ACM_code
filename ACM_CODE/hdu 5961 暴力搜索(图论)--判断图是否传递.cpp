#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
using namespace std;
/*
5961
http://blog.csdn.net/qq_33402621/article/details/53047812
竞赛图 ,基图为n阶完全图Kn
图G是传递的,等价于没有出现三条边的环?
给出邻接矩阵

思路:
a链接到b,b链接到c，则a连上c，因此从a开始dfs一定不会有距离>2的节点，
所以对所有节点都bfs一下就好了，

错误:
把判断相等写成赋值,找了很久错,以后都写成'Q'==maqq[i][j+1]这种形式了!!
*/

const int maxn = 2020;
int mapp[maxn][maxn];
int maqq[maxn][maxn];
vector<int> pp[maxn];//每个点可以到达的其他点的个数
vector<int> qq[maxn];//向量数组写法

int dfs_GP(int u)  //对GP进行暴力搜索
{
	int len = pp[u].size();
	int llen;
	for (int i = 0; i < len; i++)  //u可到的所有点
	{
		int v = pp[u][i];  //把向量当可变长数组用
		llen = pp[v].size();
		for (int j = 0; j < llen; j++)  //v可到的所有点
		{
			int k = pp[v][j];
			if (mapp[u][k] != 1)  //u可到v,v可到k,如果u不可到k,则出问题,在这里用题目定义直接暴力搜索
				return true;
		}
	}
	return false;
}
bool dfs_GQ(int u)
{
	int len = qq[u].size();
	int llen;
	for (int i = 0; i < len; i++)
	{
		int v = qq[u][i];
		llen = qq[v].size();
		for (int j = 0; j < llen; j++)
		{
			int k = qq[v][j];
			if (maqq[u][k] != 1)
				return true;
		}
	}
	return false;
}

int main()
{
	int t, n;
	scanf("%d", &t);
	char str[maxn];
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i <= n; i++)//初始化向量
		{
			pp[i].clear();
			qq[i].clear();
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str);
			for (int j = 0; j < n; j++)
			{
				mapp[i][j+1] = maqq[i][j+1] = 0;//地图初始化
				if (str[j] == 'P')
				{
					mapp[i][j + 1] = 1;
					pp[i].push_back(j + 1);
				}
				else if (str[j] == 'Q') //不要把判断相等写成赋值
				{
					maqq[i][j + 1] = 1;
					qq[i].push_back(j + 1);
				}
			}
		}
		int GP = 0;
		int GQ = 0;
		for (int i=1;i<=n;i++)
		{
			if (dfs_GP(i))
			{
				GP = 1; break;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (dfs_GQ(i))
			{
				GQ = 1; break;
			}
		}
		printf(GP||GQ ? "N\n" : "T\n");
	}
	return 0;
}