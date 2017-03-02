#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
substr(begin,length)
要考虑开头有5的  556
要考虑结尾有5的
vec.end()是最后的下一位,所以输出的时候在比较迭代器应该注意
*/
int main()
{
	string str;
	while (cin >> str)
	{
		vector <string> vec;
		int begin = 0;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == '5')
			{
				if (begin == j)//开头是5
				{
					begin = j + 1;
					continue;
				}
				vec.push_back(str.substr(begin, j-begin));
				begin = j+1;
			}
			else if (j == (str.size() - 1))//结尾是5
			{
				vec.push_back(str.substr(begin, j - begin + 1));
			}
		}

		vector<int> num;
		for (auto & w : vec)
		{
			int sum = 0;
			string ss = w;
			int i = 0;
			while (ss[i])
			{
				sum = sum * 10 + (ss[i] - '0');//(ss[i]-'0')不要用(int)ss[i]
				i++;
			}
			num.push_back(sum);
		}
		sort(num.begin(), num.end());

		//本来想用for (auto &w :num) 但是不知道怎么取最后一个元素来换行...等以后知道再改吧..(应该是不可以的)
		for (vector<int>::iterator it = num.begin(); it != num.end(); it++)
		{
			if (it == num.end()-1)//记得num.end()是指向最后一个元素的下一个..
				printf("%d\n", *it);
			else
				printf("%d ", *it);
		}
	}
	return 0;
}