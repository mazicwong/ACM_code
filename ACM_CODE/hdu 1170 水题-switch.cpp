#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int t;
	scanf("%d%*c", &t);
	while (t--)
	{
		char x;
		int a, b;
		scanf("%c%d%d%*c", &x, &a, &b);
		switch (x)
		{
		case '+':
			printf("%d\n", a + b);
			break;
		case '-':
			printf("%d\n", a - b);
			break;
		case '*':
			printf("%d\n", a*b);
			break;
		case '/':
			double ans = (double)a / (double)b;
			if ((int)ans - ans == 0)
				printf("%.0lf\n", ans);
			else
				printf("%.2lf\n", ans);
		}
	}
	return 0;
}