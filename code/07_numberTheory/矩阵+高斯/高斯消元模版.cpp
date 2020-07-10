#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
//http://www.cnblogs.com/kuangbin/archive/2012/09/01/2667044.html
const int maxn = 50;

int a[maxn][maxn];//�������
int x[maxn];//�⼯
bool free_x[maxn];//����Ƿ��ǲ�ȷ���ı�Ԫ

inline int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

inline int lcm(int a, int b)
{
	return a / gcd(a, b)*b;//�ȳ���˷����
}
// ��˹��Ԫ���ⷽ����(Gauss-Jordan elimination).(-2��ʾ�и������⣬���������⣬
//-1��ʾ�޽⣬0��ʾΨһ�⣬����0��ʾ����⣬���������ɱ�Ԫ�ĸ���)
//��equ�����̣�var����Ԫ�������������Ϊequ,�ֱ�Ϊ0��equ-1,����Ϊvar+1,�ֱ�Ϊ0��var.

int Gauss(int equ, int vat)
{
	int i, j, k;
	int max_r;// ��ǰ���о���ֵ������.
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
	col = 0; // ��ǰ�������
	for (k = 0; k < equ && col < var; k++, col++)
	{// ö�ٵ�ǰ�������.
	// �ҵ���col��Ԫ�ؾ���ֵ�����������k�н���.(Ϊ���ڳ���ʱ��С���)
		max_r = k;
		for (i = k + 1; i < equ; i++)//�������з���max_r��
		{
			if (abs(a[i][col])>abs(a[max_r][col]))
				max_r = i;
		}
		if (max_r != k) // ���k�н���.
		{
			for (j = k; j<var + 1; j++)
				swap(a[k][j], a[max_r][j]);
		}
		if (a[k][col] == 0)// ˵����col�е�k������ȫ��0�ˣ�����ǰ�е���һ��.
		{
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
					a[i][j] = a[i][j] * ta - a[k][j] * tb;
				}
			}
		}
	}

	// 1. �޽�����: ������������д���(0, 0, ..., a)��������(a != 0).
	for (i = k; i < equ; i++)
	{ // �����������˵�����Ҫ�ж���Щ�����ɱ�Ԫ����ô�����б任�еĽ����ͻ�Ӱ�죬��Ҫ��¼����.
		if (a[i][col] != 0) return -1;
	}
	// 2. ���������: ��var * (var + 1)���������г���(0, 0, ..., 0)�������У���˵��û���γ��ϸ����������.
	// �ҳ��ֵ�������Ϊ���ɱ�Ԫ�ĸ���.
	if (k < var)
	{
		// ���ȣ����ɱ�Ԫ��var - k��������ȷ���ı�Ԫ������var - k��.
		for (i = k - 1; i >= 0; i--)
		{
			// ��i��һ��������(0, 0, ..., 0)���������Ϊ�����������ڵ�k�е���equ��.
			// ͬ������i��һ��������(0, 0, ..., a), a != 0��������������޽��.
			free_x_num = 0; // �����жϸ����еĲ�ȷ���ı�Ԫ�ĸ������������1�������޷���⣬������ȻΪ��ȷ���ı�Ԫ.
			for (j = 0; j < var; j++)
			{
				if (a[i][j] != 0 && free_x[j]) free_x_num++, free_index = j;
			}
			if (free_x_num > 1) continue; // �޷�����ȷ���ı�Ԫ.
										  // ˵����ֻ��һ����ȷ���ı�Ԫfree_index����ô���������ñ�Ԫ���Ҹñ�Ԫ��ȷ����.
			temp = a[i][var];
			for (j = 0; j < var; j++)
			{
				if (a[i][j] != 0 && j != free_index) temp -= a[i][j] * x[j];
			}
			x[free_index] = temp / a[i][free_index]; // ����ñ�Ԫ.
			free_x[free_index] = 0; // �ñ�Ԫ��ȷ����.
		}
		return var - k; // ���ɱ�Ԫ��var - k��.
	}
	// 3. Ψһ������: ��var * (var + 1)�����������γ��ϸ����������.
	// �����Xn-1, Xn-2 ... X0.
	for (i = var - 1; i >= 0; i--)
	{
		temp = a[i][var];
		for (j = i + 1; j < var; j++)
		{
			if (a[i][j] != 0) temp -= a[i][j] * x[j];
		}
		if (temp % a[i][i] != 0) return -2; // ˵���и������⣬����������.
		x[i] = temp / a[i][i];
	}
	return 0;
}

int main()
{
	int equ, var;
	while (scnaf("%d %d", &equ, &var) != EOF)
	{
		memset(a, 0, szieof(a));
		for (int i = 0; i < equ; i++)
			for (int j = 0; j < var + 1; j++)
				scanf("%d", &a[i][j]);
		int free_num = Gauss(equ, var);
		if (free_num == -1) printf("�޽�!\n"); 
		else if (free_num == -2) printf("�и������⣬��������!\n");
		else if (free_num > 0)
		{
			printf("������! ���ɱ�Ԫ����Ϊ%d\n", free_num);
			for (i = 0; i < var; i++)
			{
				if (free_x[i]) printf("x%d �ǲ�ȷ����\n", i + 1);
				else printf("x%d: %d\n", i + 1, x[i]);
			}
		}
		else
		{
			for (i = 0; i < var; i++)
				printf("x%d: %d\n", i + 1, x[i]);
		}
		puts("");
	}
	return 0;
}