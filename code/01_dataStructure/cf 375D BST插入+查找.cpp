#include<iostream>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
/*
binary search tree

���⣺ ������������������ת��ǿ�壬������˵�һ����֮�����е�ĸ���ֵ
������C++��STL��set��map����ƽ������

˼·���ҵ�X����֮ǰ����ķ���set,��upper_bound�ҵ�l<x<r
*/

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	set<int>numbers;
	map<int, int>left;
	map<int, int>right;
	int n, v;
	cin >> n >> v;
	numbers.insert(v);
	for (int i = 0; i < n - 1; i++)
	{
		cin >> v;
		auto it = numbers.upper_bound(v);
		int res;
		if (it != numbers.end() && left.count(*it) == 0)
		{//upper_bound�Ľ��û�����Ҳû�������������ǲ�������
			left[*it] = v;
			res = *it;
		}
		else
		{
			it--;
			right[*it] = v;
			res = *it;
		}
		numbers.insert(v);
		cout << res;
		if (i != n - 2)
			cout << ' ';
	}
	return 0;
}