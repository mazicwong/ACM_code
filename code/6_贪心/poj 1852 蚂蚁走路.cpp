/*
* poj 1852
* author  : mazciwong
* creat on: 2016-1-14
*/

/*
������·,ȫ����ʱ�������ʱ��
*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
int x[maxn];
int l, n;
void solve()
{
	//���
	int minT = 0;
	for (int i = 0; i < n; i++)
		minT = max(minT, min(x[i], l - x[i]));

	//�
	int maxT = 0;
	for (int i = 0; i < n; i++)
		maxT = max(maxT, max(x[i], l - x[i]));

	printf("%d %d\n", minT, maxT);
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &l, &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &x[i]);
		solve();
	}
	return 0;
}
