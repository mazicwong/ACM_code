#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <queue>
using namespace std;
int main()
{
	int t;
	cin >> t;
	priority_queue<int, vector<int>, greater<int> > pque;
	while (t--)
	{
		while (!pque.empty())
			pque.pop();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			pque.push(a);
		}
		pque.pop();
		printf("%d\n", pque.top());
	}
	return 0;
}