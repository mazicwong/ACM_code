//hdu 3823
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
//题意：给出两个数字a，b。使a + x, b + x都是素数，并且它们之间没有素数。求出这样的最小的x。

/*
暴力打表,找出20000000以内的素数，求出相邻素数的差，存放在vector的数组中
*/


//学习：：把max函数换成?:能省一半内存。。。。
//学习：：把cin cout 换成scanf，能省一半时间。。。
//一开始，素数打表那里条件写成i < maxn 。。。错了好多次啊。。
const int maxn = 20000000 + 5;//在这里面素数的差才可能在150以内
bool pp[maxn];//筛选法找素数
int prime[maxn/2];//存放素数
vector <int>vec[155];
void isprime()
{
	memset(pp, 0, sizeof(pp));
	pp[1] = 1;
	for (int i = 2; i*i < maxn; i++)
	{
		if (!pp[i]) //0是素数
		{
			for (int j = i + i; j < maxn; j+=i)
			{
				pp[j] = 1;
			}
		}
	}
}
int main()
{
	isprime();

	//找素数个数，并把素数都放在数组prime[15000]中
	int times = 0;
	for (int i = 2; i < maxn; i++)
	{
		if (!pp[i])
		{
			prime[times++] = i;
		}
	}

	for (int i = 0; i < times-1; i++)
	{
		int tmp = prime[i + 1] - prime[i];
		if (tmp <= 150)
			vec[tmp].push_back(prime[i + 1]);
	}

	int t, cnt=0;
	int a, b;
	scanf("%d", &t);
	while (t--)
	{
		//cin >> a >> b;
		scanf("%d%d", &a, &b);
		int abss = abs(a - b);//两个数的差一直都不变
		int maxx = a > b ? a : b;//一开始的最大
		int res = 0;//加上x后的最大
		for (int i=0;i<vec[abss].size();i++)
		{
			if (vec[abss][i] >= maxx)
			{
				res = vec[abss][i]; //找到一个能满足的最小的就行了
				break;
			}
		}
		printf("Case %d: ", ++cnt);
		//printf(res ? "%d\n" : "-1\n", res - maxx);
		if (res == 0)
			puts("-1");
		else
			//cout << res - maxx << endl;
			printf("%d\n", res - maxx);
	}

	system("pause");
	return 0;
}