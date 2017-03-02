#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
/*
给出该子网最大可能连接进来的主机个数
问怎么设置这台主机的子网掩码,才能让主机获得该子网的正确网络号部分

解释样例.10个主机需要4个位来表示,这四个位全都是0,放在最后面,作为主机号
剩下的32-4=28位都是1,放在最前面,作为网络号

所以应该先用log求出指数,然后再配
+2是因为全0和全1的不能用
*/
int main()
{
	int n;
	int str[33];
	while (scanf("%d", &n)!=EOF)//记得加EOF,不然Output Limit Exceeded
	{
		n += 2;//因为全0和全1是不能用的;
		memset(str, 0, sizeof(str));
		int cnt = 0;
		while (n)	 cnt++, n = n >> 1;//cnt是0的个数
		for (int i = 1; i <= 32 - cnt; i++) str[i] = 1;//剩下的都放1
		int sum = 0;
		for (int i = 1; i <= 32; i++)
		{
			if (!(i % 8))
			{
				sum = sum * 2 + str[i];
				printf("%d", sum);
				sum = 0;
				if (i != 32) printf(".");
			}
			else
				sum = sum * 2 + str[i];
		}
		puts("");
	}
	//system("pause");
	return 0;
}