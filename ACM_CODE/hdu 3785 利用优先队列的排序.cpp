#include <iostream>
#include <queue>
using namespace std;
void search(int n, int m)
{
	priority_queue<int> prio;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		prio.push(tmp);
	}
	m = min(n, m);
	for (int i = 0; i < m ; i++)
	{
		printf(i == m - 1 ? "%d\n" : "%d ", prio.top());
		prio.pop();
	}


}
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF, n || m) //人数n , 富翁数m
	{
		search(n, m);
	}
	return 0;
}