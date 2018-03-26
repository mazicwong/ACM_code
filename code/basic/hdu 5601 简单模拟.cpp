#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
/*
n*m矩阵,关掉所有灯,每次路过灯的状态会转化
每次从左上角走到一个1,然后返回到左上角,每次消除一个1
*/
int main()
{
	int t;
	int n, m;
	int qq;
	cin >> t;
	while(t--)
	{
		int cnt = n + m - 1;//最初要过格子一共n+m-1个,相当与去这n+m-1个再返回
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &qq);
				if (qq) cnt++; //要过这格一次,所以cnt++
			}
		}
		printf("%s\n", cnt & 1 ? "NO" : "YES");
	}
}
