http://blog.csdn.net/lgdblue/article/details/15809893

hdu 1525 SG函数根据每一步找必胜态，简单博弈
hdu 1848 SG函数入门(dfs模版)
hdu 3032 SG打表找规律(记忆化搜索打表)--可以一堆分成两堆的Nim
hdu 2176 裸Nim+给出第一次的取法
hdu 5795 简单Nim


解题关键:寻找必败态

常用术语：P态代表Previous（先手必败），N态代表Next（先手必胜）。
上一次move的人有必胜策略的局面是P - position，也就是“先手必败”，
现在move的人有必胜策略的局面是N - position，也就是“先手可保证必胜”。


一、巴什博弈


二、威佐夫博奕


三、Fibonacci博弈


四、尼姆博弈


五、公平组合博弈（Impartial Combinatori Games）




//http ://www.cnblogs.com/frog112111/p/3199780.html

SG函数模版1
hdu 1848
//f[]：可以取走的石子个数
//sg[]:0~maxn的SG函数值
//hash[]:mex{}
int f[maxn], sg[maxn], hash[maxn];
void getSG(int n)
{//求n以内的SG数组
	int i, j;
	memset(sg, 0, sizeof(sg));
	for (i = 1; i <= n; i++)
	{
		memset(hash, 0, sizeof(hash));
		// 对于属于g(x)后继的数置1  
		for (j = 1; f[j] <= i; j++)
			hash[sg[i - f[j]]] = 1;
		// 找到最小不属于该集合的数  
		for (int j = 0; j <= n; j++)    //求mex{}中未出现的最小的非负整数
		{
			if (hash[j] == 0)
			{
				sg[i] = j;
				break;
			}
		}
	}
}




SG函数模版2(dfs)
hdu 1536
//注意 f数组要按从小到大排序 SG函数要初始化为-1 对于每个集合只需初始化1遍
//n是集合f的大小 f[i]是定义的每次可以取多少个石子的数组

int f[maxn];//可以取走的石子个数
int sg[maxn];//0~maxn的SG函数值
int n;
int SG_dfs(int x)
{
	if (sg[x] != -1)
		return sg[x];
	bool vis[maxm];
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)
	{
		if (x >= f[i])
		{
			SG_dfs(x - f[i]);
			vis[sg[x - f[i]]] = 1;
		}
	}
	for (int i = 0;; i++)
		if (!vis[i])
			return sg[x] = i;
}