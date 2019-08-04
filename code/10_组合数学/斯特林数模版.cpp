/******************˹���ֹ�ʽ*************************/
/*
��n!��λ��
˹���ֹ�ʽ��Stirling'sapproximation����һ������ȡn�Ľ׳˵Ľ���ֵ����ѧ��ʽ
λ��Ϊ: log10(2 * pi*n) / 2 + n*log10(n / e) + 1
*/
ans = (int)((0.5*log(2.0*PI*n) + 1.0*n*log(n / e)) / log(10.0)) + 1;//int����ȫ��Ҫ������,��Ȼ������


/******************��һ��Stirling��*************************/
//eg: hdu 3625
//������һ��Stirling��s(p, k)�������ǰ�p�������ų�k���ǿ�ѭ�����еķ�������
//�ǵ���main�������1~k������еĻ��������,������Ϊ���ֻ�������ʱ,Ҫ���Խ׳���
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


/*****************�ڶ���˹������**************************/
/*
�ڶ���Stirling���ǰѰ���n��Ԫ�صļ��ϻ���Ϊ����k���ǿ��Ӽ�(���򼯺�)�ķ�������Ŀ��
���󼯺ϵĻ��ֿ����

���ƹ�ʽΪ��
S(n, k) = 0(n<k || k = 0),
	S(n, n) = S(n, 1) = 1,
	S(n, k) = S(n - 1, k - 1) + kS(n - 1, k).

dp[i][j]�����ǰi�����ֳ�j��ķ�������
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


/*****************������**************************/
/*
bell(n)�ǰ���n��Ԫ�صļ��Ͽ��Ի���Ϊ���ٸ���ͬ�ķǿ��Ӽ�
bell����stirling���Ĺ�ϵ:  ÿ������������"�ڶ���Stirling��"�ĺ͡�

B(n) = Sum(1,n) S(n,k).


B(0) = 1, B(1) = 1, B(2) = 2, B(3) = 5,
B(4) = 15, B(5) = 52, B(6) = 203,...

���ƹ�ʽΪ��
	B(0) = 1,
	B(n+1) = Sum(0,n) C(n,k)B(k). n = 1,2,...
	���У�Sum(0,n)��ʾ��k��0��n��ͣ�C(n,k) = n!/[k!(n-k)!]

	f(n)=sigma(S(n,m))
	f(i)=sigma(C(i-1,k-1)*f(i-k))
*/
void GetBell() //�󱴶���
{
	for (int i = 1; i<maxn; i++)
	{
		bell[i] = 0;
		for (int j = 0; j <= i; j++)
			bell[i] = (bell[i] + dp[i][j]) % MOD;
	}
}


/*****************n��ƻ����m�����ӿ����п���**************************/
//n��ƻ����m�����ӿ����пյ�����
//dp[n][m] = dp[m][m]   (n<m)
//dp[n][m] = dp[n][m-1]+dp[n-m][m]  (n<=m) ��һ�����̣�ȫ����(ÿ������һ��)
const int maxn = 15;
int dp[maxn][maxn]; //dp[n][m]: n��ƻ������m��������

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
