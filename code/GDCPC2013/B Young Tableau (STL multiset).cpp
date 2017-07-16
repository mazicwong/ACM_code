#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <set>
using namespace std;
typedef long long ll;
/*

题意:
限定m*n大小的数列，给定K个数，然后对数列可以进行Insert（a），Remove（a），Find（a）操作，
执行Insert如果超出数列容量，则把数列中最大的数丢弃，然后插入；Find操作则输出是否存在a即可

give :
	t m n (test case , row , column)
	K (矩阵里有多少个数)
	Q (Q次操作)
	接下来Q行  C,v (C是操作,v是数)

思路:STL的set处理
*/

/*
数据
1
3 4
8
1 2 8 5 3 4 6 6
10
I 7
I 10
R 6
F 6
I 9
I 11
I 12
F 15
I 100
F 100
*/

/*
需要注意的点是,multiset.erase()会把同元素的所有个数删掉,所以如果想删掉3,但是里面可能有多于一个
应该用:
int x =3;
multiset<int>::iterator pos = s.find(x);
s.erase(pos);
*/
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	multiset<int> s;
	int t, m, n;
	scanf("%d", &t);
	while (t--)
	{
		s.clear();
		scanf("%d%d", &m, &n);
		int k,a;
		scanf("%d", &k);
		for (int i = 0; i < k; i++)
		{
			scanf("%d", &a);
			s.insert(a);
		}
		int q;
		char b;
		int val;
		scanf("%d%*c", &q);
		while (q--)
		{
			scanf("%c%d%*c", &b, &val);
			if (b == 'I')
			{
				s.insert(val);
				if (s.size() > n*m)
				{
					multiset<int>::iterator pos = s.end();
					pos--;
					s.erase(pos);
				}
			}
			else if (b == 'R')
			{//不能直接s.erase(val); ==>>会删掉不止一个
				multiset<int>::iterator pos = s.find(val);
				if (pos!=s.end())
					s.erase(pos);
			}
			else
			{
				if (s.count(val) != 0)
					puts("Bingo");
				else
					puts("Opps");
			}
		}
	}
	return 0;
}