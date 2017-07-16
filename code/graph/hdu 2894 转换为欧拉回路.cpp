/*
hdu 2894 欧拉回路
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
/*
转换成欧拉回路
eg:00作为点,000.001作为边,每条边表示一个数,共2^n个数
http://blog.csdn.net/a709743744/article/details/51457790


*/
const int maxn = 1 << 15 + 5;
int k;
int p;
int d[maxn];
bool vis[maxn];

void dfs(int u)
{
	int to1 = (u << 1)&((1 << k) - 1);//to1 to2就是去掉二进制数的首位然后在末位分别加上0和1  
	int to2 = to1 + 1;// 也就是模拟在k个接地部分旋转的情况 旋转一格 首位消失 添上末位 末位是0或者是1
	if (!vis[to1]) //不能重复出现,用vis标记
	{
		vis[to1] = true;
		dfs(to1);
		d[++p] = 0;
	}
	if (!vis[to2])//先搜0的之前的0无法达成的话 在搜1 这样就能实现字典序最小  
	{//因为是dfs的关系 所以采用栈结构(等下逆序输出)
		vis[to2] = true;
		dfs(to2);
		d[++p] = 1;
	}
}

int main()
{
	while (scanf("%d", &k) != EOF)
	{
		memset(vis, 0, sizeof(vis));
		p = 0;
		dfs(0);
		printf("%d ", 1 << k);
		for (int i = 1; i < k; i++) printf("0");
		for (int i = p; i >= k; i--) printf("%d", d[i]);//逆序输出栈中的数
		puts("");
	}
	return 0;
}