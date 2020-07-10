/*
解题思路：
这个题目就是一个高斯消元的裸题，相当于开关问题和翻转问题，就是求一个矩阵能够影响的矩阵，

将每个格子被操作的次数看作变量，问题转化为一个nm*nm的模3线性方程组，
高斯消元即可，可能有多组解，任取一组即可（例如将所有自由变元值赋为0）,
注意题目给出的是初始状态，而方程组右端的值表示的是每个格子的改变值，
即是用3减去该格子的初始状态
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 1000 + 5;
int a[maxn][maxn];//增广矩阵
int x[maxn];//解集
bool free_x[maxn];//标记是否是不确定的变元

inline int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}
inline int lcm(int a, int b)
{
	return a / gcd(a, b)*b;
}

// 高斯消元法解方程组
//-2表示有浮点数解,但无整数解
//-1表示无解
//0表示唯一解
//大于0表示无穷解，并返回自由变元的个数
//有equ个方程，var个变元
//增广矩阵行数为equ,分别为0到equ-1,列数为var+1,分别为0到var.

int Gauss(int equ, int var, int mod)
{
	int i, j, k;
	int max_r;//当前这列绝对值最大的行.
	int col;//当前处理的列
	int ta, tb;
	int LCM;
	int temp;
	int free_x_num;
	int free_index;
	for (int i = 0; i <= var; i++)
	{
		x[i] = 0;
		free_x[i] = true;
	}
	//转换为阶梯阵.
	col = 0;//当前处理的列
	for (k = 0; k<equ&&col<var; k++, col++)
	{
		// 枚举当前处理的行.
		// 找到该col列元素绝对值最大的那行与第k行交换(为了在除法时减小误差)
		max_r = k;
		for (i = k + 1; i<equ; i++)
		{
			if (abs(a[i][col])>abs(a[max_r][col])) max_r = i;
		}
		if (max_r != k)
		{// 与第k行交换.
			for (j = k; j<var + 1; j++) swap(a[k][j], a[max_r][j]);
		}
		if (a[k][col] == 0)
		{// 说明该col列第k行以下全是0了,则处理当前行的下一列.
			k--;
			continue;
		}
		for (i = k + 1; i<equ; i++)
		{// 枚举要删去的行.
			if (a[i][col] != 0)
			{
				LCM = lcm(abs(a[i][col]), abs(a[k][col]));
				ta = LCM / abs(a[i][col]);
				tb = LCM / abs(a[k][col]);
				if (a[i][col] * a[k][col]<0)tb = -tb;//异号的情况是相加
				for (j = col; j<var + 1; j++)
				{
					a[i][j] = ((a[i][j] * ta - a[k][j] * tb) % mod + mod) % mod; //处理好取余
				}
			}
		}
	}
	//无解的情况
	for (i = k; i<equ; i++)
	{
		if (a[i][col] != 0) return -1;
	}
	// 无穷解的情况
	if (k<var)
	{
		//自由变元有var-k个,即不确定的变元至少有var-k个.
		for (i = k - 1; i >= 0; i--)
		{
			free_x_num = 0; // 用于判断该行中的不确定的变元的个数,如果超过1个,则无法求解,它们仍然为不确定的变元.
			for (j = 0; j<var; j++)
			{
				if (a[i][j] != 0 && free_x[j]) free_x_num++, free_index = j;
			}
			if (free_x_num>1) continue; // 无法求解出确定的变元.
										// 说明就只有一个不确定的变元free_index,那么可以求解出该变元,且该变元是确定的.
			temp = a[i][var];
			for (j = 0; j<var; j++)
			{
				if (a[i][j] != 0 && j != free_index) temp -= a[i][j] * x[j] % mod;
				temp = (temp%mod + mod) % mod;
			}
			x[free_index] = (temp / a[i][free_index]) % mod;//求出该变元.
			free_x[free_index] = 0;//该变元是确定的.
		}
		for (i = k; i<var; i++)x[i] = 0;
		for (i = k - 1; i >= 0; i--)
		{
			temp = a[i][var];
			for (j = i + 1; j<var; j++)
			{
				if (a[i][j] != 0) temp -= a[i][j] * x[j];
				temp = (temp%mod + mod) % mod;
			}
			while (temp%a[i][i] != 0) temp += mod;
			x[i] = (temp / a[i][i]) % mod;
		}
		return var - k; //自由变元有var-k个.
	}
	//唯一解的情况 
	for (i = var - 1; i >= 0; i--)
	{
		temp = a[i][var];
		for (j = i + 1; j<var; j++)
		{
			if (a[i][j] != 0) temp -= a[i][j] * x[j];
			temp = (temp%mod + mod) % mod;
		}
		while (temp%a[i][i] != 0) temp += mod;
		x[i] = (temp / a[i][i]) % mod;
	}
	return 0;

}
int T, n, m;
void init()
{
	memset(a, 0, sizeof(a));
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++)
		{
			int temp = i*m + j;
			a[temp][temp] = 2;
			if (i>0)a[temp - m][temp] = 1;
			if (i<n - 1)a[temp + m][temp] = 1;
			if (j>0)a[temp - 1][temp] = 1;
			if (j<m - 1)a[temp + 1][temp] = 1;
		}
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		init();
		for (int i = 0; i<n; i++)
			for (int j = 0; j<m; j++)
			{
				int temp;
				scanf("%d", &temp);
				a[i*m + j][n*m] = 3 - temp;
			}
		int num = Gauss(n*m, n*m, 3), ans = 0;
		for (int i = 0; i + num<n*m; i++)
			ans += x[i];
		printf("%d\n", ans);
		for (int i = 0; i + num<n*m; i++)
			if (x[i])
				while (x[i]--)
					printf("%d %d\n", i / m + 1, i%m + 1);
	}
	return 0;
}