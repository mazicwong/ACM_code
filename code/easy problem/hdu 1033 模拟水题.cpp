/*
* hdu 1033
* author  : mazciwong
* creat on: 2016-1-19
*/

/*


*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 200;
char str[maxn];
int main()
{
	int x, y;
	while (scanf("%s", &str) != EOF)
	{
		int len = strlen(str);
		int x = 310, y = 420;
		int p = 1;//一开始x轴正向
		puts("300 420 moveto");
		puts("310 420 lineto");
		for (int i = 0; i < len; i++)
		{
			switch (p)
			{
			case 1://x轴正向
				if (str[i] == 'V') p = 2, y += 10;
				else p = -2, y -= 10;
				break;
			case 2://y轴正向
				if (str[i] == 'V') p = -1, x -= 10;
				else p = 1, x += 10;
				break;
			case -1://x轴负向
				if (str[i] == 'V') p = -2, y -= 10;
				else p = 2, y += 10;
				break;
			case -2:
				if (str[i] == 'V')p = 1, x += 10;
				else p = -1, x -= 10;
				break;
			}
			printf("%d %d lineto\n", x, y);
		}
		printf("stroke\nshowpage\n");
	}
	return 0;
}