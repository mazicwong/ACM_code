/*
hdu 2894 ŷ����·
*/
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
/*
ת����ŷ����·
eg:00��Ϊ��,000.001��Ϊ��,ÿ���߱�ʾһ����,��2^n����
http://blog.csdn.net/a709743744/article/details/51457790


*/
const int maxn = 1 << 15 + 5;
int k;
int p;
int d[maxn];
bool vis[maxn];

void dfs(int u)
{
	int to1 = (u << 1)&((1 << k) - 1);//to1 to2����ȥ��������������λȻ����ĩλ�ֱ����0��1  
	int to2 = to1 + 1;// Ҳ����ģ����k���ӵز�����ת����� ��תһ�� ��λ��ʧ ����ĩλ ĩλ��0������1
	if (!vis[to1]) //�����ظ�����,��vis���
	{
		vis[to1] = true;
		dfs(to1);
		d[++p] = 0;
	}
	if (!vis[to2])//����0��֮ǰ��0�޷���ɵĻ� ����1 ��������ʵ���ֵ�����С  
	{//��Ϊ��dfs�Ĺ�ϵ ���Բ���ջ�ṹ(�����������)
		vis[to2] = true;
		dfs(to2);
		d[++p] = 1;
	}
}

int main()
{
	while (scanf("%d", &k) != EOF)
	{
		memset(vis, 0, sizeof(vis));
		p = 0;
		dfs(0);
		printf("%d ", 1 << k);
		for (int i = 1; i < k; i++) printf("0");
		for (int i = p; i >= k; i--) printf("%d", d[i]);//�������ջ�е���
		puts("");
	}
	return 0;
}