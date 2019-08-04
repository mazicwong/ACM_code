/*
hdu 4135 
http://www.cnblogs.com/jiangjing/archive/2013/06/03/3115470.html
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
n��m���,m��k���(�·�,����,Ь��)
����p������, 
������ж�����ƥ�䷽��

˼·1:������һ���ó���,����Ь��,�ֱ����ÿ��Ь�Ӷ�Ӧ���Դ�����·��Ϳ���,��;��Ǵ�
˼·2:�ݳ�,��ͻ�������,�·����ӳ�+����Ь�ӳ�-�ظ�
�ܵľ��ǹ��ж����������ȥ�����ظ���

��:
��ͻ1 : A
��ͻ2 : B
�ظ�  : O
�� : n*m*k - (A*k + B*n - O)

�ο�:��ս������ƾ��� P 295

*/

const int maxn = 1000 + 5;
int n, m, k;
int p;
int a[maxn];//a[i]=j,i���Ӻ�j�·���ͻ
int b[maxn];//b[i]=j,i���Ӻ�jЬ�ӳ�ͻ
int A, B, O;

int main()
{
	while (scanf("%d%d%d", &n, &m, &k) != EOF)
	{
		if (!n && !m && !k)	break;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		A = B = O = 0;//��ͻ1,��ͻ2,�ظ�
		scanf("%d", &p);
		char str1[10], str2[10];
		int x, y;
		while (p--)
		{
			scanf("%s%d%s%d", str1, &x, str2, &y);
			if (strcmp(str1, "clothes") == 0) //����y���·�x��ͻ
				A++, a[y]++;
			else if (strcmp(str1, "pants") == 0) //����x��Ь��y��ͻ
				B++, b[x]++;
		}
		//�ص���
		for (int i = 1; i <= m; i++)
		{
			if (a[i] != 0)
				O += a[i] * b[i];//Ь��i���������ص��ĸ���  
		}
		int sum = n*m*k - (A*k + B*n - O);
		printf("%d\n", sum);
	}
	return 0;
}