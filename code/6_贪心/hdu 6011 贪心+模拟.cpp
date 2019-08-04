#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <functional>
#include <queue>
using namespace std;




//A
const int maxn = 26 + 5;
typedef long long ll;
int n;

map<int, int> mp;//val.wei
priority_queue<int> pque;

/*
3
0 1
0 2
1 1
һ��ʼ�����˿��Դ�������val��Ϊ0��������

1
3
-1 1
2 1
3 1
�������ݳ���,-1Ҳ����ȡ

��ȷ����:����ĸ�Ӵ�С �Ӻ���ǰ��,��������𰸱���ֹͣ
*/

void solve()
{
	int ans = 0;
	int cnt = 0;
	int sum = 0;
	int all = 0;
	while (1)
	{
		if (pque.empty()) break;
		int val = pque.top();  //�����ȡ
		pque.pop();

		/* ������ֱ���ù�ʽ��ĳ�ģ��
		int ahead = cnt + 1;
		cnt += mp[val];
		ans += val * mp[val] * (ahead + cnt) / 2;
		*/

		while (mp[val]--)
		{
			sum += val;  //�Ӵ�С�����ĺ���sum
			all += sum;  //�ܵĺ���all ... ÿ�μ�sum,����Ͱ�����֮ǰ��Ҫ�ظ���Ԫ��


						 //����,�ᵼ��pqueû��վͼ�����
			if (ans >= all)
			{
				printf("%d\n", ans);
				return;
			}
			else
				ans = all;

			//ans = max(ans, all); ��ʱ..
		}
	}
	printf("%d\n", ans);
}

int main()
{
	int t;
	int val, weigh;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		mp.clear();
		while (!pque.empty())pque.pop();
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &val, &weigh);
			if (mp[val] == 0)
				pque.push(val);
			mp[val] += weigh;
		}
		solve();
	}
	return 0;
}