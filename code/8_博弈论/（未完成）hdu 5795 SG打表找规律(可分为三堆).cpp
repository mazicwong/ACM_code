#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1e4 + 5;
int sg[maxn], vis[maxn];
void init()
{
	sg[0] = 0, sg[1] = 1;
	for (int i = 2; i <= 1000; i++)
	{
		memset(vis, 0, sizeof(vis));
		for (int j = 1; j < i; j++)
			vis[sg[j] ^ sg[i - j]] = 1;//拆分
		for (int j = 0; j < i; j++)
			vis[sg[j]] = 1;//取石子
		for (int j = 0;; j++)
			if (!vis[j])
			{
				sg[i] = j;
				break;
			}
	}
	for (int i = 1; i <= 30; i++)
		cout << sg[i] << endl;
}
int main()
{
	init();
}