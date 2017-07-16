/*
* hdu2421
* author  : mazciwong
* creat on: 2016-12-10
*/

/*
思路：积性函数--数论
http://www.acmerblog.com/hdu-2421-deciphering-password-3885.html#comments

*/


#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD = 10007;
const int _4MOD = 4 * MOD;
typedef long long ll;
typedef vector<pair<int, int> > Int_Pair;

void get_prime_table(int N, vector<int> &pt)
{
	vector<bool> ip;
	ip.resize(N + 1);
	fill(ip.begin(), ip.end(), true);
	int j, t=N-1;
	for (int i = 3; i <= N; i++)
	{
		int s = (int)sqrt(i);
		for (j = 2; j <= s; j++)
			if (i%j == 0) break;
		if (j <= s)
		{
			ip[i] = false;
			t--;
		}
	}
	pt.resize(t);
	t = 0;
	for (int i = 2; i <= N; i++)
		if (ip[i]) pt[t++] = i;
}

void get_prime_factor(int N, Int_Pair &f, const vector<int> &p)  // 得到的数放vecotr f里;  素数表P
{
	int plen = p.size();
	for (int i = 0; i < plen; i++)
	{
		int t = p[i];
		if (N%t == 0)
		{
			int n = 0;
			while (N%t == 0)
			{
				n++;
				N /= t;
			}
			f.push_back(make_pair(t, n)); //第一个是因子,第二个是指数
		}
		if (N == 1) break;
	}
	if (N > 1)
		f.push_back(make_pair(N, 1));
}

int main()
{
	vector<int> prime_table;
	get_prime_table(2000, prime_table);
	int a, b;
	int cnt = 1;
	int ans = 0;
	while (scanf("%d%d", &a, &b) != EOF)
	{
		Int_Pair ip;//初始化一个放数对的vector
		get_prime_factor(a, ip, prime_table);
		ans = 1;
		for (int i = 0, len = ip.size(); i < len; i++)
		{
			int n = (ip[i].second*(ll)b + 1) % _4MOD;
			ll tmp = ((n*n) % _4MOD)*(((n + 1)*(n + 1)) % _4MOD);
			tmp = (tmp%_4MOD) / 4;
			ans *= tmp;
			ans %= MOD;
		}
		printf("Case %d: %d\n", cnt++, ans);
	}
	return 0;
}