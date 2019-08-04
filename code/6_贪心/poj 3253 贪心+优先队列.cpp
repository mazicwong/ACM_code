/*
* poj 3253
* author  : mazciwong
* creat on: 2016-1-15
*/

/*
̰��,�������ö����������������
ÿ��ȡ��С�������������ټӵ�ԭ������,
�������ȶ��п��԰�����С��O(n) ת����O(log n)
*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <functional> //greater
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 20000 + 5;
int l[maxn];
int n;

void solve()
{
	ll ans = 0;

	//���ȶ����ǴӴ�ʼȡ��,����д���Դ�С��ʼȡ����,���ö����ݽṹ
	priority_queue<int, vector<int>, greater<int> > pque;
	for (int i = 0; i < n; i++)
		pque.push(l[i]);

	//һֱѭ����ֻ��һ�� �� �����ʼ���ǿ�ľ����
	while (pque.size() > 1)
	{
		int l1 = pque.top();
		pque.pop();
		int l2 = pque.top();
		pque.pop();

		ans += l1 + l2;
		pque.push(l1 + l2);
	}
	printf("%lld\n", ans);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &l[i]);
	solve();
	return 0;
}