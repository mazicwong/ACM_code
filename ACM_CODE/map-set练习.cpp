#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;
/*
map例题：单词词频统计程序
输入大量单词，每个单词，一行，不超过20字符，没有空 格。 按出现次数从多到少输出这些单词及其出现次数。 出现次数相同的，字典序靠前的在前面
INPUT：
this
is
ok
this
plus
that
is
plus
plus

输出样例：
plus 3
is 2
this 2
ok 1
that 1
*/
struct Word {
	int times;
	string wd;
};
struct Rule {  //按照时间从大到小,时间相同则按照名字顺序来
	bool operator()(const Word & w1, const Word & w2) {
		if (w1.times != w2.times)
			return w1.times > w2.times;
		else
			return w1.wd < w2.wd;
	}
};
/*
思路:先对输入的数据进行统计,用map得到每个单词对应的次数
然后用set对单词的次数和字母表顺序进行排序
http://www.icourse163.org/learn/PKU-1001553023?tid=1001762001#/learn/content
*/
int main()
{
	string str;
	set<Word, Rule> st;
	map<string, int>mp;
	while (cin >> str)
		mp[str]++;
	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		Word tmp;
		tmp.wd = it->first;
		tmp.times = it->second;
		st.insert(tmp);//插入进行后直接按照自定义的Rule排序
	}
	for (set<Word, Rule>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout << it->wd << " " << it->times << endl;
	}
	return 0;
}