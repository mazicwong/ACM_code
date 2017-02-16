/*
* poj 1182
* author  : mazciwong
* creat on: 2016-1-18
*/

/*
按A,B,C分类,并查集解决
并查集是维护 "属于同一组"的数据结构
因为有真有假,所有N个元素每个都可以分到三组中去
所以设出来的并查集有三个根,这三个是划分块,不能同时成立
每个划分块里面是等价类,一个成立则其他都成立


*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 150000 + 5;
int n, k;
int d, x, y;
int fa[maxn];
int depth[maxn];
//maxn是最多的节点数,init中的n是用到的



//并查集初始化
void init(int n) 
{
	//包括用rank记录树的高度和路径压缩两种优化
	for (int i = 0; i < n; i++)
	{
		fa[i] = i;
		depth[i] = 0;
	}
}

//并查集查询
int find(int x)
{
	if (x == fa[x])
		return x;
	else
		return fa[x] = find(fa[x]);
}

//并查集合并
void unite(int x, int y)  
{
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (depth[x] < depth[y]) //x根更短,则x指向y
		fa[x] = y;
	else if(depth[x]>depth[y])
		fa[y] = x;
	else //一样高的话,谁指向谁都可以,记得高度加一
	{
		fa[y] = x;
		depth[x]++;
	}
}

//判断是否属于同一个集合
bool same(int x, int y)
{
	return find(x) == find(y);
}

/*
n个元素,每个元素都能放入A.B.C中,则共3n种对应法
用并查集来分组,在一组的话同时成立,相当于等价划分块
*/
void solve()
{
	int ans = 0;
	for (int i = 0; i < k; i++)
	{
		scanf("%d%d%d", &d, &x, &y);
		x--, y--;//把他们从1-n变成从0-(n-1),方便计算

		//题目里给出的第二种错误
		if (x < 0 || x >= n || y < 0 || y >= n)
		{
			ans++;
			continue;
		}

		//下面是循环读入,然后并查集处理
		if (d == 1) //x,y同一类
		{
			//就不能跟另外两个同类了
			if (same(x, y + n) || same(x, y + 2 * n))
				ans++;
			else
			{ //要三个都写是因为后面两个一定成立,x在A,y在A,那么当x在B,y一定在B
				unite(x, y);
				unite(x + n, y + n);
				unite(x + 2 * n, y + 2 * n);
			}
		}
		else //x吃y
		{
			if (same(x, y) || same(x, y + 2 * n))
				ans++;
			else
			{
				unite(x, y + n);
				unite(x + n, y + 2 * n);
				unite(x + 2 * n, y);
			}
		}
	}
	printf("%d\n", ans);
}
int main()
{
	scanf("%d%d", &n, &k);
	init(n * 3);//把3*n种配对都初始化出来
	solve();
	return 0;
}