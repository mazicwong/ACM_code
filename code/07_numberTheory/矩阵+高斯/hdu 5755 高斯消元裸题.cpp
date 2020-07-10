/*
����˼·��
�����Ŀ����һ����˹��Ԫ�����⣬�൱�ڿ�������ͷ�ת���⣬������һ�������ܹ�Ӱ��ľ���

��ÿ�����ӱ������Ĵ�����������������ת��Ϊһ��nm*nm��ģ3���Է����飬
��˹��Ԫ���ɣ������ж���⣬��ȡһ�鼴�ɣ����罫�������ɱ�Ԫֵ��Ϊ0��,
ע����Ŀ�������ǳ�ʼ״̬�����������Ҷ˵�ֵ��ʾ����ÿ�����ӵĸı�ֵ��
������3��ȥ�ø��ӵĳ�ʼ״̬
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 1000 + 5;
int a[maxn][maxn];//�������
int x[maxn];//�⼯
bool free_x[maxn];//����Ƿ��ǲ�ȷ���ı�Ԫ

inline int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}
inline int lcm(int a, int b)
{
	return a / gcd(a, b)*b;
}

// ��˹��Ԫ���ⷽ����
//-2��ʾ�и�������,����������
//-1��ʾ�޽�
//0��ʾΨһ��
//����0��ʾ����⣬���������ɱ�Ԫ�ĸ���
//��equ�����̣�var����Ԫ
//�����������Ϊequ,�ֱ�Ϊ0��equ-1,����Ϊvar+1,�ֱ�Ϊ0��var.

int Gauss(int equ, int var, int mod)
{
	int i, j, k;
	int max_r;//��ǰ���о���ֵ������.
	int col;//��ǰ�������
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
	//ת��Ϊ������.
	col = 0;//��ǰ�������
	for (k = 0; k<equ&&col<var; k++, col++)
	{
		// ö�ٵ�ǰ�������.
		// �ҵ���col��Ԫ�ؾ���ֵ�����������k�н���(Ϊ���ڳ���ʱ��С���)
		max_r = k;
		for (i = k + 1; i<equ; i++)
		{
			if (abs(a[i][col])>abs(a[max_r][col])) max_r = i;
		}
		if (max_r != k)
		{// ���k�н���.
			for (j = k; j<var + 1; j++) swap(a[k][j], a[max_r][j]);
		}
		if (a[k][col] == 0)
		{// ˵����col�е�k������ȫ��0��,����ǰ�е���һ��.
			k--;
			continue;
		}
		for (i = k + 1; i<equ; i++)
		{// ö��Ҫɾȥ����.
			if (a[i][col] != 0)
			{
				LCM = lcm(abs(a[i][col]), abs(a[k][col]));
				ta = LCM / abs(a[i][col]);
				tb = LCM / abs(a[k][col]);
				if (a[i][col] * a[k][col]<0)tb = -tb;//��ŵ���������
				for (j = col; j<var + 1; j++)
				{
					a[i][j] = ((a[i][j] * ta - a[k][j] * tb) % mod + mod) % mod; //�����ȡ��
				}
			}
		}
	}
	//�޽�����
	for (i = k; i<equ; i++)
	{
		if (a[i][col] != 0) return -1;
	}
	// ���������
	if (k<var)
	{
		//���ɱ�Ԫ��var-k��,����ȷ���ı�Ԫ������var-k��.
		for (i = k - 1; i >= 0; i--)
		{
			free_x_num = 0; // �����жϸ����еĲ�ȷ���ı�Ԫ�ĸ���,�������1��,���޷����,������ȻΪ��ȷ���ı�Ԫ.
			for (j = 0; j<var; j++)
			{
				if (a[i][j] != 0 && free_x[j]) free_x_num++, free_index = j;
			}
			if (free_x_num>1) continue; // �޷�����ȷ���ı�Ԫ.
										// ˵����ֻ��һ����ȷ���ı�Ԫfree_index,��ô���������ñ�Ԫ,�Ҹñ�Ԫ��ȷ����.
			temp = a[i][var];
			for (j = 0; j<var; j++)
			{
				if (a[i][j] != 0 && j != free_index) temp -= a[i][j] * x[j] % mod;
				temp = (temp%mod + mod) % mod;
			}
			x[free_index] = (temp / a[i][free_index]) % mod;//����ñ�Ԫ.
			free_x[free_index] = 0;//�ñ�Ԫ��ȷ����.
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
		return var - k; //���ɱ�Ԫ��var-k��.
	}
	//Ψһ������ 
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