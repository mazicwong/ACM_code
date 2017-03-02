/*
2086 可怕的推导过程...
*/

/*
因为：Ai=(Ai-1+Ai+1)/2 - Ci,
A1=(A0  +A2  )/2 - C1;
A2=(A1  +  A3)/2 - C2 , ...
=>    A1+A2 = (A0+A2+A1+A3)/2 - (C1+C2)
=>    A1+A2 =  A0+A3 - 2(C1+C2)
同理可得：
A1+A1 =  A0+A2 - 2(C1)
A1+A2 =  A0+A3 - 2(C1+C2)
A1+A3 =  A0+A4 - 2(C1+C2+C3)
A1+A4 =  A0+A5 - 2(C1+C2+C3+C4)
...
A1+An = A0+An+1 - 2(C1+C2+...+Cn)
----------------------------------------------------- 左右求和
(n+1)A1+(A2+A3+...+An) = nA0 +(A2+A3+...+An) + An+1 - 2(nC1+(n-1)C2+...+2Cn-1+Cn)

=>   (n+1)A1 = nA0 + An+1 - 2(nC1+(n-1)C2+...+2Cn-1+Cn)

=>   A1 = [nA0 + An+1 - 2(nC1+(n-1)C2+...+2Cn-1+Cn)]/(n+1)
*/

#include <iostream>

using namespace std;
int main()
{
	int n;
	double sum;
	double a, b;
	double x;
	while (scanf("%d", &n) != EOF)
	{
		int tmp = n;
		scanf("%lf%lf", &a, &b);
		sum = tmp*a + b;
		for (int i = 0; i < n; i++)
		{
			scanf("%lf", &x);
			sum -= 2 * (tmp*x);
			tmp--;
		}
		sum /= (n + 1);
		printf("%.2lf\n", sum);
	}
	return 0;
}