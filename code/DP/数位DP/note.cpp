
数位dp: 求小于等于N的某类数字个数,或者是区间[L,R]中某类数字个数
    求出在给定区间[A,B]内，符合条件P(i)的数i的个数.
eg: [1000,9999]中包含64的个数
特点: 与数大小无关,与组成有关


LL dfs(int len,int S,int up,int z)
{
	if(len==0)
	{
		if(S==15)return 1;
	    else return 0;
	}
	if(!up&&dp[len][S]!=-1)return dp[len][S];
	LL res=0;
	for(int i=0;i<=3;i++)
	{
		if(i==0&&z)continue;
		if(judge1(S)&&i==0)continue;
		if(judge3(S)&&i==2)continue; 
		int nowS=S|(1<<i);
		res+=dfs(len-1,nowS,up&&i==3,0);
		res%=MOD;
	}
	if(!up)dp[len][S]=res,dp[len][S]%=MOD;
	return res;
}

//模板
int dfs(int len, int s, bool e)   //长度,状态,上限
{
    if (len==-1) return s==target_s;
    if (!e && ~f[len][s]) return f[len][s];  //非0就直接返回
    int res = 0;
    int u = e?num[len]:9;
    for (int d = first?1:0; d <= u; ++d)
        res += dfs(len-1, new_s(s, d), e&&d==u);
    return e?res:f[len][s]=res;
}

其中：
f为记忆化数组；
len为当前处理串的第len位（权重表示法，也即后面剩下len+1位待填数）；
s为之前数字的状态（如果要求后面的数满足什么状态，也可以再记一个目标状态t之类，for的时候枚举下t）；
e表示之前的数是否是上界的前缀（即后面的数能否任意填）。
for循环枚举数字时，要注意是否能枚举0，以及0对于状态的影响，有的题目前导0和中间的0是等价的，但有的不是，对于后者可以在dfs时再加一个状态变量z，表示前面是否全部是前导0，也可以看是否是首位，然后外面统计时候枚举一下位数。It depends.

于是关键就在怎么设计状态。当然做多了之后状态一眼就可以瞄出来。


ccf 2013-12-4
