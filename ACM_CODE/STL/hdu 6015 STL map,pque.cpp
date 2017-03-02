#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>	
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 5e4 + 5;
int main()
{
	int t;
	int n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		map < string, priority_queue<int> >mp;
		string str;
		int num;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> str >> num;
			mp[str].push(num);
		}
		int tt = mp.size();
		map < string, priority_queue<int> >::iterator it=mp.begin();
		for (; it != mp.end(); it++)
		{
			int cnt = 0;
			while (cnt < 2 &&!it->second.empty())
			{
				ans += it->second.top();
				it->second.pop();
				cnt++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}