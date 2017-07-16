/*
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
const int maxn = 1e5 + 5;
int num[maxn];
int main()
{
	num[1] = 1;
	for (int i = 2; i < maxn; i++)
		num[i] = num[i - 1] + i;
	string str;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> str;
		int len = str.size();
		for (int i = 0; i < len; i++)
		{
			 
		}

	}


	system("pause");
	return 0;
}
*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	while (1)
	{
	int t;
	scanf("%d", &t);
	int h, min;
	if (t == 12)
	{
		scanf("%d:%d", &h, &min);
		if (min >= 60)
		{
			min -= 60;
			h += 1;
		}
		if (h > 12)
			h %= 10;
	}
	else if (t == 24)
	{
		scanf("%d:%d", &h, &min);
		if (min >= 60)
		{
			min %= 10;
		}
		if (h >= 24)
		{
			h %= 10;
		}
	}
	if (h < 10)
		printf("0%d:", h);
	else
		printf("%d:", h);
	if (min < 10)
		printf("0%d", min);
	else
		printf("%d", min);
	}

	system("pause");
	return 0;
}



/*
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;
int main()
{
	
	system("pause");
	return 0;
}*/