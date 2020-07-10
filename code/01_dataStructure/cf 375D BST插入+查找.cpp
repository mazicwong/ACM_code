#include<iostream>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
/*
binary search tree

题意： 二叉搜索树，不用旋转，强插，输出除了第一个点之外所有点的父亲值
可以用C++的STL的set和map来当平衡树。

思路：找到X，把之前插入的放入set,用upper_bound找到l<x<r
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
		{//upper_bound的结果没在最后也没有左子树，就是插入这里
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