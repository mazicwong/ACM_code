#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
/*
hdu 3342
题意:就是用拓扑排序求有没有构成环

思路:
拓扑排序----要求:无环有向图----topologic模版题
就是直接进行拓扑排序即可，统计拓扑排序完成时能
记录的入度为0的节点的个数，若个数等于节点个数则说明无环，
否则是有环的。


拓扑排序算法:
构造邻接矩阵
1.找入度为0的顶点,入栈(删除)
2.把该顶点指向的所有边删除,维护入度数组
3.重复1.2知道没有顶点

错误:


*/
//点的序列是从0到n-1 , 跟1285不一样,那个是从1到n ,要注意这一点

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) && (n || m))
	{
		
	}


	return 0;
}