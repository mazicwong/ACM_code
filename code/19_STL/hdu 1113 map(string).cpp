/*
����Ȥ��һ����,�����ֵ�
����һ�Ѳ�ѯ,ÿ����ѯ��һ�������ַ���,���ʸ��ַ���������ܷ����ֵ����ҵ�

˼·:���ֵ�ÿ�������ֵ�������,��ѯ��Ҳ��,
��map�����Ӧ��ϵ,key������ǰ��,
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