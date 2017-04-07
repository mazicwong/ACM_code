/*
http://www.cnblogs.com/kuangbin/archive/2012/10/02/2710606.html

走飞行棋,计算完成游戏的期望
形成一个有向无环图。按照公式递推就可以了。
dp[i]表示i点跳到目标状态的期望步数

*/

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;//最多可以走到n,所以要这样
double dp[maxn];
vector <int>vec[maxn];
bool used[maxn];
int main()
{
	int n, m;
	int u, v;


	return 0;
}