/*
hdu 4452 求n因子和+进制转换
http://blog.csdn.net/u013480600/article/details/18327165

*/
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
/*


*/

const int maxn = 55;
const int WEAST = 0, EAST = 1, NORTH = 2, SOUTH = 3;//四个方向
int dx[] = { 0,0,-1,1 };//dx[WEAST]为0时往西走
int dy[] = { -1,1,0,0 };
int inv[] = { EAST,WEAST,SOUTH,NORTH };//inv表示反方向
int turn_left[] = { SOUTH,NORTH,WEAST,EAST };
int n;

//c,s,t,初始方向,速度,左转周期
//x.y.当前位置
int c[2], s[2], t[2], x[2], y[2];
int k;//k秒后

void solve()
{
	for (int time = 1; time <= k; time++)
	{//模拟每一个时刻的变化
		for (int i = 0; i < 2; i++) 
		{//两只兔子
			for (int j = 1; j <= s[i]; j++)
			{
				x[i] += dx[c[i]];
				y[i] += dy[c[i]];
				if (x[i]<1 || x[i]>n)//越界
				{
					c[i] = inv[c[i]];
					if (x[i] < 1)	x[i] = 2;
					else x[i] = n - 1;
				}
				else if (y[i]<1 || y[i]>n)//越界 
				{
					c[i] = inv[c[i]];
					if (y[i]<1)y[i] = 2;
					else y[i] = n - 1;
				}
			}
		}
		if (x[0] == x[1] && y[0] == y[1])//相遇
			swap(c[1], c[0]);
		//周期左转
		else if(time%t[0] == 0 || time%t[1] == 0)
		{
			if (time%t[0] == 0)c[0] = turn_left[c[0]];
			if (time%t[1] == 0)c[1] = turn_left[c[1]];
		}
		/*为什么下面这样不行
		if (time%t[0] == 0) c[0] = turn_left[c[0]];
		if (time%t[1] == 0) c[1] = turn_left[c[1]];*/
	}
	printf("%d %d\n%d %d\n", x[0], y[0], x[1], y[1]);
}

int main()
{
	while (scanf("%d%*c", &n) != EOF&&n)
	{
		x[0] = y[0] = 1;
		x[1] = y[1] = n;
		char dir;
		for (int i = 0; i < 2; i++)
		{
			scanf("%c%d%d%*c", &dir, &s[i], &t[i]);
			switch (dir) //处理初始方向
			{
			case'W':c[i] = 0; break;
			case'E':c[i] = 1; break;
			case'N':c[i] = 2; break;
			case'S':c[i] = 3; break;
			}
		}
		scanf("%d", &k);
		solve();
	}

	return 0;
}