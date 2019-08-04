/*
* hdu 2431
* author  : mazciwong
* creat on: 2016-1-15
*/

/*
����, �Ƚ����뵽
���⣺
������һ��n*n������,�������2*n������,ʹ��ÿ��ÿ�ж�����ֻ��2������,���ж����ַŷ�.
˼·��
ÿһ��n*n�����̶����Էֳ�a*a��b*b������,����(a+b)=n��a>1,b>1,
���Կ���ֱ�Ӵ�ǰ��ĺϷ�����ƺ����.

*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <functional> //greater
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod = 1000007;
const int maxn = 500 + 5;
int n;
int ans[maxn];
void init()
{
	ans[0] = 1; ans[1] = 0;
	for (int i = 2; i < maxn; i++)
		for (int j = i; j < maxn; j++)
			ans[j] = (ans[j] + ans[j - i]) % mod;
}

void solve()
{
	printf("%d\n", ans[n]);
}
int main()
{
	init();
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		solve();
	}
	return 0;
}