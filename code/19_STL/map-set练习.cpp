#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;
/*
map���⣺���ʴ�Ƶͳ�Ƴ���
����������ʣ�ÿ�����ʣ�һ�У�������20�ַ���û�п� �� �����ִ����Ӷൽ�������Щ���ʼ�����ִ����� ���ִ�����ͬ�ģ��ֵ���ǰ����ǰ��
INPUT��
this
is
ok
this
plus
that
is
plus
plus

���������
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
struct Rule {  //����ʱ��Ӵ�С,ʱ����ͬ��������˳����
	bool operator()(const Word & w1, const Word & w2) {
		if (w1.times != w2.times)
			return w1.times > w2.times;
		else
			return w1.wd < w2.wd;
	}
};
/*
˼·:�ȶ���������ݽ���ͳ��,��map�õ�ÿ�����ʶ�Ӧ�Ĵ���
Ȼ����set�Ե��ʵĴ�������ĸ��˳���������
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
		st.insert(tmp);//������к�ֱ�Ӱ����Զ����Rule����
	}
	for (set<Word, Rule>::iterator it = st.begin(); it != st.end(); it++)
	{
		cout << it->wd << " " << it->times << endl;
	}
	return 0;
}