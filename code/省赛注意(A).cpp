#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <cctype>
#include <iomanip>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <functional>

using namespace std;
queue<char>que;
void output(int tt)
{
	for (int i = 0; i < tt; i++)
		printf(" ");
}
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		getchar(); //  \n
		char a;
		char b;
		while (!que.empty())
			que.pop();
		int cnt = 0;// { }个数
		while (1)
		{
			a = getchar();
			que.push(a);
			if (a == '{')
			{
				cnt++;
			}
			else if (a == '}')
			{
				cnt--;
			}
			if (cnt == 0)
				break;
		}
		//printf("\n %d \n", que.size());
		/*while (!que.empty())
		{
			cout << que.front();
			que.pop();
		}*/
		int indent = 0;
		while (1)
		{
			if (que.empty())
				break;
			b = a; //b存上一次的
			a = que.front();
			que.pop();
			if (a == '{')
			{
				output(indent);
				printf("{\n");
				indent += 2;
			}
			else if (a == ',')
			{
				printf(",\n");
			}
			else if (a == '}') //右括号跟字母 统一不帮换行
			{
				if (b == '{')
				{
					indent -= 2;
					output(indent);
					printf("}");
				}
				else
				{
					//output(indent);
					printf("\n");
					indent -= 2;
					output(indent);
					printf("}");
				}

			}
			else
			{
				if (b == ','||b=='{')
					output(indent);
				putchar(a);
			}
		}
		printf("\n");
	}

	return 0;
}