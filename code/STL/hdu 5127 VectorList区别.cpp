/*
5127

糖果两个属性  甜p  酸q
狗 两个数学  喜欢甜x   喜欢酸y

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
/*
vector和list的区别(可以看作数组和链表的区别)
(数组)  （链表）
需要大量插入和删除的时候，用list会快很多，
而且这道题的查找也是没有直接按索引值来的，所以就算查找很多，用vector跟list也差不多
*/
typedef long long ll;
typedef pair<ll,ll> pii;
vector<pii> vec;
int main()
{
    freopen("in","r",stdin);
	int n;
	while (scanf("%d", &n) && n)
	{
		int t, x, y;
		vec.clear();
/*
t
-1 拿出来
1  放进去
0  求最大  (在这里就要输出)
*/
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d", &t, &x, &y);

			vector<pii>::iterator it;
			if (t == -1)
			{
				pii tmp = pii(x, y);
                for (int k=0;k<vec.size();k++)
                {
                    if (vec[k]==tmp)
                    {
                        vec.erase(remove(vec.begin(),vec.end(),vec[k]),vec.end());
                        break;
                    }
                }
                /*
				for (it = vec.begin(); it != vec.end(); it++)
				{
					if (*it == tmp)
					{
						it = vec.erase(it);
						break;
					}
				}*/
			}
			else if (t == 1)
			{
				vec.push_back(pii(x, y));
			}
			else if (t==0)
			{
				ll maxx = 0;
				int flag = 1;
				for (it = vec.begin(); it != vec.end(); it++)
				{
					if (flag)
					{
						maxx = it->first*x + it->second*y;
						flag = 0;
					}
					else
						maxx = max(maxx, it->first*x + it->second*y);
				}
				printf("%I64d\n", maxx);
			}
		}//for i...n
	}//while
	return 0;
}




/*
vector和list的区别(可以看作数组和链表的区别)
(数组)  （链表）
需要大量插入和删除的时候，用list会快很多，
而且这道题的查找也是没有直接按索引值来的，所以就算查找很多，用vector跟list也差不多
*/

//list实现
/*
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

typedef long long ll;
list <pair<ll, ll>> lis;
int main()
{
	int n;
	while (scanf("%d", &n) && n)
	{
		int t, x, y;
		lis.clear();
		// t
		// -1 拿出来
		// 1  放进去
		// 0  求最大  (在这里就要输出)
		
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d", &t, &x, &y);
			list<pair<ll, ll>>::iterator it;
			if (t == -1)
			{
				pair<ll, ll> t = pair<ll, ll>(x, y);
				for (it = lis.begin(); it != lis.end(); it++)
				{
					if (*it == t)
					{
						it = lis.erase(it);//其实这里的迭代器保留下来也没用，也可以直接vec.erase()
						break;
					}
				}
			}
			else if (t == 1)
			{
				lis.push_back(pair<ll, ll>(x, y));
			}
			else if (!t)
			{
				ll maxx = 0;
				int flag = 1;
				for (it = lis.begin(); it != lis.end(); it++)
				{
					if (flag)
					{
						maxx = it->first*x + it->second*y;
						flag = 0;
					}
					else
						maxx = max(maxx, it->first*x + it->second*y);
				}
				printf("%I64d\n", maxx);
			}
		}//for i...n
	}//while
	return 0;
}
*/
