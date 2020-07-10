/*
* poj 2431
* author  : mazciwong
* creat on: 2016-1-15
*/

/*
����վ,���ȶ���
*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <functional> //greater
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 10000 + 5;
int n;  //����վ��
int l, p; //����,��������
struct point {
	int x;
	int v;
}s[maxn];//��վ�ص������
bool cmp(point s1, point s2)
{
	return s1.x < s2.x;
}
void solve()
{
	//�����յ��յ�Ҳ������վ
	s[n].x = l; 
	s[n].v = 0;
	n++;
	//�������С������
	sort(s, s + n, cmp);
	priority_queue<int> pque;  //ֵ����ȡ����

	//ans:���ʹ���, pos:���ڵ�λ��, tank:�������
	int ans = 0, pos = 0, tank = p;

	for (int i = 0; i < n; i++)
	{
		//����Ҫǰ���ľ���
		int d = s[i].x - pos;


		//���ͼӵ�����
		while (tank - d < 0)
		{
			if (pque.empty())
			{
				puts("-1");
				return;
			}
			tank += pque.top();
			pque.pop();
			ans++;
		}
		tank -= d;
		pos = s[i].x;
		pque.push(s[i].v);
	}
	printf("%d\n", ans);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &s[i].x, &s[i].v);
	scanf("%d%d", &l, &p);
	for (int i = 0; i < n; i++)
		s[i].x = l - s[i].x;
	solve();
	return 0;
}