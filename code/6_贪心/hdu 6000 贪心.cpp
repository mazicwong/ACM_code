#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>  
using namespace std;
typedef long long ll;
/*
 http://blog.csdn.net/qq_32944513/article/details/53967554
 L���·���N��ϴ�»���M����ˮ��
 ����Сʱ��
 ̰�ģ���Сϴ��ʱ��+�����ˮʱ��

 */

const int maxn = 1e6 + 5;
const int maxm = 1e5 + 5;
int L, N, M;
ll ans;
ll d[maxn], a[maxm], b[maxm];
struct node {
	ll cot;
	int id;
	bool operator <(const node &a)const
	{
		return a.cot < cot;
	}
};

node V, U;
void solve(priority_queue<node> &Q1, priority_queue<node> &Q2)
{
	ll time;
	for (int i = 1; i <= L; i++)
	{//ϴ�·�---����Сʱ�俪ʼѡ
	//ϴ��һ���·���ϴ�»��������·Ż�ȥ����Ϊ���ܲ���
		V = Q1.top(); Q1.pop();
		time = V.cot;
		U.cot = V.cot + a[V.id], U.id = V.id;
		Q1.push(U);
		d[i] = time;
	}
	for (int i = L; i >= 1; i--)
	{//��ˮ
		V = Q2.top(), Q2.pop();
		time = V.cot;
		U.cot = V.cot + b[V.id], U.id = V.id;
		Q2.push(U);
		ans = max(ans, time + d[i]);
	}

}
int main()
{
	int t;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++)
	{
		priority_queue<node>Q1, Q2;
		scanf("%d%d%d", &L, &N, &M);
		for (int i = 1; i <= N; i++)
		{
			scanf("%I64d", &a[i]);
			U.cot = a[i];
			U.id = i;
			Q1.push(U);
		}
		for (int i = 1; i <= M; i++)
		{
			scanf("%I64d", &b[i]);
			U.cot = b[i];
			U.id = i;
			Q2.push(U);
		}
		ans = -1;
		solve(Q1,Q2);
		printf("Case #%d: %I64d\n", cas, ans);
	}
	return 0;
}