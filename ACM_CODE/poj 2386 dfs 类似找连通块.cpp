/*
* poj 2386
* author  : mazciwong
* creat on: 2016-1-14
*/

/*
找连通块,通过DFS将周围的W换成.

*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 100 + 5;
char field[maxn][maxn];
int n, m;

void dfs(int x, int y)
{
	field[x][y] = '.';//遍历过就定成.

	//遍历8个方向
	for (int dx = -1; dx <= 1; dx++)
	{
		for (int dy = -1; dy <= 1; dy++)
		{
			int nx = x + dx, ny = y + dy;
			if (nx >= 0 && nx < n&&ny >= 0&&ny < m&&field[nx][ny] == 'W')
				dfs(nx, ny);
		}
	}
}
void solve()
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (field[i][j] == 'W')
			{
				dfs(i, j);
				res++;
			}
		}
	}
	printf("%d\n", res);
}
int main()
{
	scanf("%d%d%*c", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%c", &field[i][j]);
		getchar();
	}
	solve();
	return 0;
}