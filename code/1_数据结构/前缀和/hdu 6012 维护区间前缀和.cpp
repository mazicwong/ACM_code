#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
/*
����:
��һЩ���䷶Χ,�������������в�ͬ��ֵ,Ҫ��һ����ʹ����ֵ���,������ֵ

//http://blog.csdn.net/mengxiang000000/article/details/54650271���͵úܺ�

��ȡ�ĵ����������˵���Ҷ˵��ұ�0.5�ĵ�,�������԰������еĴ�����,
�Ȱ�������������,ֱ��ȡ������----�˵�OR�˵�����1�ĵ�
��Ȼ������Ҫ�����п���ѡ�ĵ���ɢ��.
��ѡ������,��������c�ĺ�,���Ǵ�ʱ�����ƶ�,����ô�仯
ÿ�δﵽһ������X����˵�,�𰸼���a-c,

*/
typedef long long ll;
const int maxn = 50000*2 + 5;//ÿ�������������˵�,�ǵ�Ҫ����
int t, n;
struct node {
	int x;//����
	int del;//�仯ֵ
}qq[maxn];
int cmp(node a, node b)
{
	return a.x < b.x;
}
int l, r, a, b, c;//����,����,С��
ll sum = 0;
int cnt = 0;

void solve()
{
	int now = 1;
	ll ans = sum;
	sort(qq + 1, qq + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++)  //��������λ��
	{
		while (now <= cnt && qq[now].x == qq[i].x)
			sum += qq[now++].del;
		ans = max(ans, sum);
	}
	printf("%I64d\n", ans);
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		sum = 0;
		cnt = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d%d%d", &l, &r, &a, &b, &c);
			l *= 2; r *= 2;
			sum += c;  //������ĺ�
			qq[++cnt].x = l;  qq[cnt].del = -c + a;
			qq[++cnt].x = r+1;  qq[cnt].del = -a + b;
		}
		solve();
	}
	return 0;
}