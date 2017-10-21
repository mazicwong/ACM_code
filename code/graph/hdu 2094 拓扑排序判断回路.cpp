#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
using namespace std;
const int maxn = 2000 + 5;
/*用拓扑排序判断回路*/
void solve(int n)
{
	map<string, int> mp; //每个点都给一个标号
	string name;
	int a, b;
	int in[maxn] = { 0 };
	int m = 0;
	while (n--)
	{
		cin >> name;
		if (mp[name] == 0)
		{
			m++;
			mp[name] = m;
		}
		cin >> name;
		if (mp[name] == 0)
		{
			m++;
			b = m;
			mp[name] = m;
		}
		else b = mp[name];
		in[b]++;
	}
	int cnt = 0;
	for (int i = 1; i <= m; i++)
		if (in[i] == 0)cnt++; //如果有入度为0的点，说明不存在回路
	printf("%s\n", cnt == 1 ? "Yes" : "No");
}

int main()
{
	int n;
	while (scanf("%d", &n) && n)
		solve(n);
	return 0;
}