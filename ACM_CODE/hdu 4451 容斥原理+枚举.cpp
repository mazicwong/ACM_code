/*
hdu 4135 
http://www.cnblogs.com/jiangjing/archive/2013/06/03/3115470.html
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
/*
n和m配对,m和k配对(衣服,裤子,鞋子)
给出p个限制, 
问最后有多少种匹配方案

思路1:把其中一个拿出来,例如鞋子,分别求出每个鞋子对应可以搭配的衣服和裤子,求和就是答案
思路2:容斥,冲突的情况是,衣服裤子冲+裤子鞋子冲-重复
总的就是共有多少种情况减去上面重复的

设:
冲突1 : A
冲突2 : B
重复  : O
共 : n*m*k - (A*k + B*n - O)

参考:挑战程序设计竞赛 P 295

*/

const int maxn = 1000 + 5;
int n, m, k;
int p;
int a[maxn];//a[i]=j,i裤子和j衣服冲突
int b[maxn];//b[i]=j,i裤子和j鞋子冲突
int A, B, O;

int main()
{
	while (scanf("%d%d%d", &n, &m, &k) != EOF)
	{
		if (!n && !m && !k)	break;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		A = B = O = 0;//冲突1,冲突2,重复
		scanf("%d", &p);
		char str1[10], str2[10];
		int x, y;
		while (p--)
		{
			scanf("%s%d%s%d", str1, &x, str2, &y);
			if (strcmp(str1, "clothes") == 0) //裤子y和衣服x冲突
				A++, a[y]++;
			else if (strcmp(str1, "pants") == 0) //裤子x和鞋子y冲突
				B++, b[x]++;
		}
		//重叠数
		for (int i = 1; i <= m; i++)
		{
			if (a[i] != 0)
				O += a[i] * b[i];//鞋子i所产生的重叠的个数  
		}
		int sum = n*m*k - (A*k + B*n - O);
		printf("%d\n", sum);
	}
	return 0;
}