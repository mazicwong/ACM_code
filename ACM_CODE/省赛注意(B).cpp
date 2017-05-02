#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <cctype>
#include <iomanip>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <functional>

using namespace std;
const int maxn = 5000 + 5;
char a[maxn];
char b[maxn];
//priority_queue <char>pque;
vector<char>vec;
map<char,int>mp;
map<char, int>mpb;
/*
因为只有abc三种情况,记得判断剩下来的数是不是只存在三种中的一种
*/
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		char x;
		mp['a'] = mp['b'] = mp['c'] = 0;
		mpb['a'] = mpb['b'] = mpb['c'] = 0;
		vec.clear();

		getchar();
		for (int i = 0; i < n; i++)
		{
			x = getchar();
			mp[x]++;
			vec.push_back(x);
		}
		getchar();
		scanf("%s", b);
		for (int i = 0; i < n; i++)
			mpb[b[i]]++;

		//对a排序
		sort(vec.begin(), vec.end());
		//按照b的,改变a的,使得字典序最小且对应位置不同
		for (int i = 0; i < n; i++)
		{
			vector<char>::iterator it = vec.begin();
			while (1)
			{
				mp[*it]--;
				mpb[b[i]]--;
				if (it == vec.end()-1) //这里debug了很久...vec.end()是指向最后一个元素的下一位...所以判断末尾时候用vec.end()-1
				{
					printf("%c", *it);
					vec.erase(it);
					break;
				}
				else if ((mp['a'] == 0 && mp['b'] == 0 && mp['c'] == mpb['c']) ||
					(mp['b'] == 0 && mp['c'] == 0 && mp['a'] == mpb['a']) ||
					(mp['a'] == 0 && mp['c'] == 0 && mp['b'] == mpb['b']) ||
					*it == b[i]
					)
				{
					mp[*it]++;
					mpb[b[i]]++;
					it++;
				}
				else
				{
					printf("%c", *it);
					vec.erase(it);
					break;
				}
			}
		}
		puts("");
	}
	return 0;
}