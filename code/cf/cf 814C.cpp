#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;

const int maxn = 1500 + 5;
char str[maxn];
int m;
int d[maxn];
int dp[maxn];
int record[30][maxn];
char c;
int cnt[30];
int main()
{
	freopen("in.txt", "r", stdin);
	int n;
	int q;
	cin >> n;
	cin >> str;
	cin >> q;
	memset(cnt, 0, sizeof(cnt));
	memset(record, 0, sizeof(record));
	for (int i = 0; i < n; i++)
	{
		cnt[str[i] - 'a']++;
		for (int j = 0; j < 26; j++)
		{
			record[j][i] = cnt[j];
		}
	}
	for (int k = 0; k < q; k++)
	{
		cin >> m >> c;
		int ccnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == c)
			{
				d[ccnt++] = i;
			}
		}
		//cout << d[0] <<' '<< d[1] << endl;
		cout << record[c - 'a'][0] << ' ' << record[c - 'a'][1] << ' ';

		cout << record[c - 'a'][2] << ' ' << record[c - 'a'][3] << ' ' << endl;
		int ans = -1;
		for (int i = 0; i < ccnt; i++)
		{
			if (d[i] + m < n)
			{
				int dd = 0;
				while(record[c - 'a'][d[i] + m] - record[c - 'a'][d[i]] < record [c-'a'][d[i+1]+m]-record[c-'a'][d[i]] )
					dd = 
			}
				ans = max(ans, record[c - 'a'][d[i] + m] - record[c - 'a'][d[i]]+1+m);
			else
				ans = max(ans, record[c - 'a'][d[ccnt - 1]] - record[c - 'a'][d[ccnt - 1] - m]);
		}
		cout << ans << endl;

	}


	return 0;
}