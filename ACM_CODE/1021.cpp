/*
* hdu 1021
* author  : mazciwong
* creat on: 2016-12-31
*/

/*
  打表,每四位一个循环
*/


#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if ((n - 2) % 4 == 0)
			puts("yes");
		else puts("no");
	}
	return 0;
}