
/*
��i�ſο���ǰҪ��riʱ��,��i�ſ������ڿ�ʼ��eiʱ�䷢��,����liСʱ
�ܷ�ͨ�����п���
����̰��,Ҫ���Ե�ʱ�������ϰʱ��,Խǰ�ľͲ���Խǰ
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 1e5 + 5;
struct MAZIC {
	int r, e, l;
}mazic[maxn];
int cmp(MAZIC a, MAZIC b)
{
	return a.e < b.e;
}
int main()
{
	int t;
	cin >> t;
	int n;
	int r, e, l;
	for (int cas = 1; cas <= t; cas++)
	{
		scanf("%d", &n);
		bool flag = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d%d%d", &mazic[i].r, &mazic[i].e, &mazic[i].l);
		sort(mazic + 1, mazic + n + 1, cmp);
		for (int i = 1; i <= n; i++)
		{
			if (mazic[i].r > mazic[i].e)
			{
				flag = true; break;
			}
			mazic[i + 1].r += mazic[i].r + mazic[i].l;//�¸���ʼ��ʱ��������Ŀ�ʼʱ��ӳ���ʱ��
		}
		if (mazic[n].r > mazic[n].e)
			flag = true;
		if (flag)
			printf("Case #%d: NO\n", cas);
		else
			printf("Case #%d: YES\n", cas);
	}
	return 0;
}