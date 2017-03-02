/*
hdu 5038 简单排序

题意：有n个数字，带入10000 - (100 - ai) ^ 2公式得到n个数，
输出n个数中频率最大的数，如果有并列就按值从小到大都输出输出，
如果频率相同的数字是全部的n个数，就输出Bad。


题解：统计数字个数和频率，排序后输出。
*/

#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e4 + 5;
int cnt[maxn];//每个数出现的次数
int main()
{
	int t;
	int n;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++)
	{
		scanf("%d", &n);
		int s_cnt = 0;  //共有多少种数
		int max_s = 0;  //给出的数的最大值
		int min_s = maxn;  //给出的数的最小值
		int max_cnt = 0;  //出现最多的次数
		memset(cnt, 0, sizeof(cnt));
		int w;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &w);
			int s = 10000 - (100 - w)*(100 - w);
			if (s > max_s) max_s = s;
			if (s < min_s) min_s = s;
			if (!cnt[s]) s_cnt++;
			cnt[s]++;
			if (cnt[s] > max_cnt) max_cnt = cnt[s];
		}
		printf("Case #%d:\n", cas);
		if (max_cnt*s_cnt == n && s_cnt > 1)  //没有小于最大频率的数,就是不存在
			puts("Bad Mushroom");
		else
		{
			int flag = 0;
			for (int i = min_s; i <= max_s; i++)
			{
				if (cnt[i] == max_cnt)
				{
					printf(flag ? " %d" : "%d", i);
					flag = 1;
				}
			}
			puts("");
		}
	}
	return 0;
}