/*
5127

�ǹ���������  ��p  ��q
�� ������ѧ  ϲ����x   ϲ����y

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
/*
vector��list������(���Կ�����������������)
(����)  ������
��Ҫ���������ɾ����ʱ����list���ܶ࣬
���������Ĳ���Ҳ��û��ֱ�Ӱ�����ֵ���ģ����Ծ�����Һܶ࣬��vector��listҲ���
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
-1 �ó���
1  �Ž�ȥ
0  �����  (�������Ҫ���)
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
vector��list������(���Կ�����������������)
(����)  ������
��Ҫ���������ɾ����ʱ����list���ܶ࣬
���������Ĳ���Ҳ��û��ֱ�Ӱ�����ֵ���ģ����Ծ�����Һܶ࣬��vector��listҲ���
*/

//listʵ��
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
		// -1 �ó���
		// 1  �Ž�ȥ
		// 0  �����  (�������Ҫ���)
		
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
						it = lis.erase(it);//��ʵ����ĵ�������������Ҳû�ã�Ҳ����ֱ��vec.erase()
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
