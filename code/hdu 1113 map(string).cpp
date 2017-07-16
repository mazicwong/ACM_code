/*
很有趣的一道题,给个字典
给出一堆查询,每个查询是一个乱序字符串,求问该字符串排序后能否在字典中找到

思路:把字典每个串按字典序排序,查询的也是,
用map保存对应关系,key是排序前的,
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
map<string, string>node;
int main()
{
	string str;
	while (cin >> str&&str != "XXXXXX")
	{
		string tmp = str;
		sort(str.begin(), str.end());
		node.insert(pair<string, string>(tmp, str));
	}
	while (cin >> str)
	{
		if (str == "XXXXXX")break;
		bool flag = true;
		map<string, string>::iterator it;
		sort(str.begin(), str.end());
		for (map<string, string>::iterator it = node.begin(); it != node.end(); it++)
		{
			if (it->second == str)
			{
				flag = false;
				cout << it->first << endl;
			}
		}
		if (flag) cout << "NOT A VALID WORD" << endl;
		cout << "******" << endl;

	}

	return 0;
}