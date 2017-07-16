/*************************************************************************
> File Name: a.cpp
> Author: mazicwong
> Mail: mazicwong@gmail.com
> Created Time: 2017年06月17日 星期六 22时18分46秒
************************************************************************/
/*
给出一个hh:mm的情况表示小时和分钟,然后每次mm递增一个,60进位,
问什么时候hh跟mm形成一个回文串

WA了,05:51的情况,变成输出69,其实就是06:60的时候出来了,不成立,重判下就好了
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	int h, m;
	char str[6];
	cin >> str;
	scanf("%d:%d", &h, &m);
	int cnt = 0;
	while (1)
	{
		if (str[3]>'5')
		{
			str[1]++;
			str[3] = '0';
			continue;
		}
		else if (str[4]>'9')
		{
			str[3]++;
			str[4] = '0';
			continue;
		}
		else if (str[0] == '2' && str[1] == '4')
		{
			str[0] = '0';
			str[1] = '0';
			continue;
		}
		else if (str[1]>'9')
		{
			str[0]++;
			str[1] = '0';
			continue;
		}
		if (str[0] == str[4] && str[1] == str[3])
			break;
		cnt++;
		str[4]++;

	}
	cout << cnt << endl;
	return 0;
}