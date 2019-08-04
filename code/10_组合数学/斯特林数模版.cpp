/******************斯特林公式*************************/
/*
求n!的位数
斯特林公式（Stirling'sapproximation）是一条用来取n的阶乘的近似值的数学公式
位数为: log10(2 * pi*n) / 2 + n*log10(n / e) + 1
*/
ans = (int)((0.5*log(2.0*PI*n) + 1.0*n*log(n / e)) / log(10.0)) + 1;//int后面全都要加括号,不然过不了


/******************第一类Stirling数*************************/
//eg: hdu 3625
//定理：第一类Stirling数s(p, k)计数的是把p个对象排成k个非空循环排列的方法数。
//记得在main中如果从1~k算出所有的环的情况数,当划分为各种环无区别时,要除以阶乘数
void init()
{
	for (int i = 1; i < maxn; i++)
	{
		fac[i] = fac[i - 1] * i;
		dp[i][0] = 0, dp[i][i] = 1;
		for (int j = 1; j < i; j++)
			dp[i][j] = dp[i - 1][j - 1] + (i - 1)*dp[i - 1][j];
	}
}


/*****************第二类斯特林数**************************/
/*
第二类Stirling数是把包含n个元素的集合划分为正好k个非空子集(无序集合)的方法的数目。
即求集合的划分块个数

递推公式为：
S(n, k) = 0(n<k || k = 0),
	S(n, n) = S(n, 1) = 1,
	S(n, k) = S(n - 1, k - 1) + kS(n - 1, k).

dp[i][j]代表把前i个，分成j组的方法数。
*/
void init()
{
	for (int i = 1; i < maxn; i++)
		dp[i][0] = 0, dp[i][1] = 1;
	for (int i = 2; i < maxn; i++)
	{
		for (int j = 1; j < maxn; j++)
		{
			if (i == j)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j - 1] + j*dp[i - 1][j];
		}
	}
}


/*****************贝尔数**************************/
/*
bell(n)是包含n个元素的集合可以划分为多少个不同的非空子集
bell数和stirling数的关系:  每个贝尔数都是"第二类Stirling数"的和。

B(n) = Sum(1,n) S(n,k).


B(0) = 1, B(1) = 1, B(2) = 2, B(3) = 5,
B(4) = 15, B(5) = 52, B(6) = 203,...

递推公式为，
	B(0) = 1,
	B(n+1) = Sum(0,n) C(n,k)B(k). n = 1,2,...
	其中，Sum(0,n)表示对k从0到n求和，C(n,k) = n!/[k!(n-k)!]

	f(n)=sigma(S(n,m))
	f(i)=sigma(C(i-1,k-1)*f(i-k))
*/
void GetBell() //求贝尔数
{
	for (int i = 1; i<maxn; i++)
	{
		bell[i] = 0;
		for (int j = 0; j <= i; j++)
			bell[i] = (bell[i] + dp[i][j]) % MOD;
	}
}


/*****************n个苹果放m个盘子可以有空盘**************************/
//n个苹果放m个盘子可以有空的盘子
//dp[n][m] = dp[m][m]   (n<m)
//dp[n][m] = dp[n][m-1]+dp[n-m][m]  (n<=m) 有一个空盘，全都满(每个拿走一个)
const int maxn = 15;
int dp[maxn][maxn]; //dp[n][m]: n个苹果放在m个盘子里

int dfs(int n,int m)
{
    if(n==0 || m==1) return 1;
    if(n<m) return dfs(n,n);
    else return dfs(n,m-1)+dfs(n-m,m);
}

int main()
{
    int m,n;
    cin>>n>>m;
    cout << dfs(n,m);
    return 0;
}
