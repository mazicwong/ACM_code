//http://blog.csdn.net/u013480600/article/details/44646517
#include <cstdio>  
#include <cstring>  
#include <cstdlib>  
#include <string>  
#include <iostream>  
#include <algorithm>  
#include <sstream>  
#include <math.h>  
#include <queue>  
#include <stack>  
#include <vector>  
#include <deque>  
#include <set>  
#include <map>  
#include <time.h>;

/*************************MP模板****************************/
char T[1000];//待匹配串  
char P[100];//模板串  

			//失配指针,记住这里f要比P多一位  
			//因为P到m-1即可,但是f还要计算出m的失配指针  
int f[101];

void find(char *T, char *P, int *f) //找到所有匹配点  
{
	int n = strlen(T), m = strlen(P);
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		while (j && T[i] != P[j]) j = f[j];
		if (T[i] == P[j]) j++;
		if (j == m) printf("%d\n", i - m + 1);//就算j到m了，也用f[m]继续匹配  
	}
}
void getFail(char *P, int *f) //f是fail失配数组
{
	int m = strlen(P);
	f[0] = f[1] = 0;
	for (int i = 1; i < m; i++)//虽然字符串是0到m-1，但是要求出f[m]的值  
	{
		int j = f[i];
		while (j && P[i] != P[j]) j = f[j];
		f[i + 1] = P[i] == P[j] ? j + 1 : 0;
	}
}
/*************************MP模板****************************/

http://blog.csdn.net/u013480600/article/details/44646517
http://blog.csdn.net/u013480600/article/details/22929489
http://acm.hdu.edu.cn/showproblem.php?pid=2594
http://blog.csdn.net/libin56842/article/category/1433736
http://blog.csdn.net/xingyeyongheng/article/details/9285989