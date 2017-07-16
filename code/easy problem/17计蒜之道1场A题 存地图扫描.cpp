#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
using namespace std;

/*
https://www.jisuanke.com/contest/726
*/

const int maxn = 13;
int qq[maxn][maxn];
int pp[maxn][maxn];

int main()
{
	int n, m;
	cin >> n >> m;
	int x, y;
	memset(qq, 0, sizeof(qq));
	memset(pp, 0, sizeof(pp));
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		qq[x + 3][y + 3] = 1;
		pp[x + 3][3 + y] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
	}
	int ans = 0;

	for (int i = -3; i <= 3; i++)
	{//column
		if (abs(i) == 3)
		{
			if (qq[i + 3][3-3] == 1 && qq[i + 3][3+0] == 1 && qq[i + 3][3+3] == 1)
				ans++;
		}
		else if (abs(i) == 2)
		{
			if (qq[i + 3][3-2] == 1 && qq[i + 3][3+0] == 1 && qq[i + 3][3+2] == 1)
				ans++;
		}
		else if (abs(i) == 1)
		{
			if (qq[i + 3][3-1] == 1 && qq[i + 3][3+0] == 1 && qq[i + 3][3+1] == 1)
				ans++;
		}
		else if (abs(i) == 0)
		{
			if (qq[i + 3][3+1] == 1 && qq[i + 3][3+2] == 1 && qq[i + 3][3+3] == 1)
				ans++;
			if (qq[i + 3][3-1] == 1 && qq[i + 3][3-2] == 1 && qq[i + 3][3-3] == 1)
				ans++;
		}
	}
	for (int j = -3; j <= 3; j++)
	{//raw
		if (abs(j) == 3)
		{
			if (pp[3 - 3][j + 3] == 1 && pp[3+0][j + 3] == 1 && pp[3+3][j + 3] == 1)
				ans++;
		}
		else if (abs(j) == 2)
		{
			if (pp[3-2][j+ 3] == 1 && pp[3+0][j + 3] == 1 && pp[3+2][j + 3] == 1)
				ans++;
		}
		else if (abs(j) == 1)
		{
			if (pp[3-1][j + 3] == 1 && pp[3+0][j + 3] == 1 && pp[3+1][j + 3] == 1)
				ans++;
		}
		else if (abs(j) == 0)
		{
			if (pp[3+1][j + 3] == 1 && pp[3+2][j + 3] == 1 && pp[3+3][j + 3] == 1)
				ans++;
			if (pp[3-1][j + 3] == 1 && pp[3-2][j + 3] == 1 && pp[3-3][j + 3] == 1)
				ans++;
		}
	}
	cout << ans;
	return 0;
}