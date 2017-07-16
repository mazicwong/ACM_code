#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>
#include <map>
using namespace std;
/*
计蒜客2017第二题  https://www.jisuanke.com/contest/726/38334

poj 3461 KMP模版题
*/

const int maxn = 1e6 + 5;
typedef long long ll;
ll n, a, b, l, r;
char w[maxn];
char str[maxn];

//w子串   t母串
int Next[maxn];
void getnext(int lenstr)
{
	int i = 0, j = -1;
	Next[i] = -1;
	while (i < lenstr)
	{
		if (j == -1 || str[i] == str[j])
			Next[++i] = ++j;
		else j = Next[j];
	}
}


ll kmp(int pos, int lenstr, int lenw)
{
	ll i = pos, j = 0, ans = 0;
	while (i<lenw)
	{
		if (w[i] == str[j] || j == -1) ++i, ++j;
		else j = Next[j];
		if (j == lenstr)
		{
			ans++;
			j = Next[j - 1];
			i--;
		}
	}
	return ans;
}


int main()
{
	cin >> n >> a >> b >> l >> r;
	ll tmp = b;
	for (int i = 0; i < n; i++)
	{
		if (tmp<l || tmp>r)
		{
			if (tmp % 2 == 0)
			{//G
				w[i] = 'G';
			}
			else
			{//C
				w[i] = 'C';
			}
		}
		else
		{
			if (tmp % 2 == 0)
			{
				w[i] = 'A';
			}
			else
			{
				w[i] = 'T';
			}
		}
		tmp = (tmp + a) % n;
	}
	/*for (int i = 0; i < n; i++)
		cout << w[i];
	cout << endl;*/
	cin >> str;
	//cout <<endl<< str << endl;
	int lenstr = strlen(str);
	int lenw = strlen(w);
	getnext(lenstr);
	cout << kmp(0,lenstr,lenw);//pos,子串,母串

	return 0;
}