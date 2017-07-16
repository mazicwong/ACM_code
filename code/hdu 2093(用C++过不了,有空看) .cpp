
//2093 排序
//下面一个很C++的做法...还没通过
/*
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;
int score[13];
int n, m;
struct student {
	string name;
	int num;
	int scores;
};
struct Rule {
	bool operator()(const student & w1, const student & w2)
	{
		if (w1.num != w2.num)
			return w1.num > w2.num;
		else
			return w1.scores < w2.scores;
	}
};
int split(string str)
{
	string::iterator it;
	int sum = 0;
	if (str.find("(")==string::npos)  //没有罚时
	{
		for (it = str.begin(); it != str.end(); it++)
		{
			sum = sum * 10 + (*it - '0');
		}
	}
	else  //罚时
	{
		for (it = str.begin(); it != str.end(); it++)
		{
			if (*it != '(')
			{
				sum = sum * 10 + (*it - '0');
			}
			else
			{
				it++;
				int num = 0;
				while (*it != ')')
				{
					num = num * 10 + *it - '0';
				}
				sum -= num*m;
			}
		}
	}
	return sum;
}
int split_fine(string str)
{
	int sum = 0;
	for (int i = 0; i < str.size(); i++)
	{
		sum = sum * 10 + (str[i] - '0');
	}
	return sum*m;
}
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	map<string, int> mp;
	map<string, int>mpp;
	set<student, Rule>st;
	scanf("%d%d", &n, &m);
	string str, ss;
	while (scanf("%s", str) != EOF)
	{
		printf("0000\n", str);
		int sum = 0;
		int cnt = n;
		for (int i = 0; i < n; i++) //题数
		{
			cin >> ss;//C++不兼容C,所以string只能用cin,cout
			cout << ss;
			if (ss[0] == '0')
			{
				cnt--;
				continue;
			}
			else if (ss[0] == '-')  //负数
			{
				sum -= split_fine(ss.substr(1, str.size() - 1));//传递从1开始的数
			}
			else  //正数
			{
				sum += split(ss);
			}
		}
		mp[str] = sum;
		mpp[str] = cnt;
	}
	student tmp;
	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		tmp.name = it->first;
		tmp.num = mpp[tmp.name];
		tmp.scores = it->second;
		st.insert(tmp);
	}

	//printf("adsfasdfa6s5dfa6sdf56");
	
	for (set<student, Rule>::iterator it = st.begin(); it != st.end(); it++)
	{
		printf("%-10s %2d %4d\n", it->name, it->num, it->scores);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

*/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
struct Node {
	char name[10];
	int num;
	int time;
}stu[1000];
bool cmp(const Node& a, const Node& b)
{
	if (a.num != b.num)
		return a.num > b.num;
	else if (a.time != b.time)
		return a.time < b.time;
	else
		return a.name < b.name;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int i = 0;
	while (scanf("%s", stu[i].name) != EOF)
	{
		stu[i].num = 0;
		stu[i].time = 0;
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			if (a > 0)
			{
				stu[i].num++;
				stu[i].time += a;
				if (getchar() == '(')
				{
					cin >> a;
					stu[i].time += a*m;
					getchar();
				}
			}
		}
		i++;
	}
	sort(stu, stu + i, cmp);
	for (int k = 0; k < i; k++)
	{
		printf("%-10s %2d %4d\n", stu[k].name, stu[k].num, stu[k].time);
	}
	return 0;
}