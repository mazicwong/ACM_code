/*
* poj 1182
* author  : mazciwong
* creat on: 2016-1-18
*/

/*
��A,B,C����,���鼯���
���鼯��ά�� "����ͬһ��"�����ݽṹ
��Ϊ�����м�,����N��Ԫ��ÿ�������Էֵ�������ȥ
����������Ĳ��鼯��������,�������ǻ��ֿ�,����ͬʱ����
ÿ�����ֿ������ǵȼ���,һ������������������


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
//maxn�����Ľڵ���,init�е�n���õ���



//���鼯��ʼ��
void init(int n) 
{
	//������rank��¼���ĸ߶Ⱥ�·��ѹ�������Ż�
	for (int i = 0; i < n; i++)
	{
		fa[i] = i;
		depth[i] = 0;
	}
}

//���鼯��ѯ
int find(int x)
{
	if (x == fa[x])
		return x;
	else
		return fa[x] = find(fa[x]);
}

//���鼯�ϲ�
void unite(int x, int y)  
{
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (depth[x] < depth[y]) //x������,��xָ��y
		fa[x] = y;
	else if(depth[x]>depth[y])
		fa[y] = x;
	else //һ���ߵĻ�,˭ָ��˭������,�ǵø߶ȼ�һ
	{
		fa[y] = x;
		depth[x]++;
	}
}

//�ж��Ƿ�����ͬһ������
bool same(int x, int y)
{
	return find(x) == find(y);
}

/*
n��Ԫ��,ÿ��Ԫ�ض��ܷ���A.B.C��,��3n�ֶ�Ӧ��
�ò��鼯������,��һ��Ļ�ͬʱ����,�൱�ڵȼۻ��ֿ�
*/
void solve()
{
	int ans = 0;
	for (int i = 0; i < k; i++)
	{
		scanf("%d%d%d", &d, &x, &y);
		x--, y--;//�����Ǵ�1-n��ɴ�0-(n-1),�������

		//��Ŀ������ĵڶ��ִ���
		if (x < 0 || x >= n || y < 0 || y >= n)
		{
			ans++;
			continue;
		}

		//������ѭ������,Ȼ�󲢲鼯����
		if (d == 1) //x,yͬһ��
		{
			//�Ͳ��ܸ���������ͬ����
			if (same(x, y + n) || same(x, y + 2 * n))
				ans++;
			else
			{ //Ҫ������д����Ϊ��������һ������,x��A,y��A,��ô��x��B,yһ����B
				unite(x, y);
				unite(x + n, y + n);
				unite(x + 2 * n, y + 2 * n);
			}
		}
		else //x��y
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
	init(n * 3);//��3*n����Զ���ʼ������
	solve();
	return 0;
}