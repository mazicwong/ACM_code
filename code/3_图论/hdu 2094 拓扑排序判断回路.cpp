#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
using namespace std;
const int maxn = 2000 + 5;
/*�����������жϻ�·*/
void solve(int n)
{
	map<string, int> mp; //ÿ���㶼��һ�����
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
		if (in[i] == 0)cnt++; //��������Ϊ0�ĵ㣬˵�������ڻ�·
	printf("%s\n", cnt == 1 ? "Yes" : "No");
}

int main()
{
	int n;
	while (scanf("%d", &n) && n)
		solve(n);
	return 0;
}