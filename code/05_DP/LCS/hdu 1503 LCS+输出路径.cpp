#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
/*
Problem type ��permutation group with the combining of LCS
*/

/*
���⣺LCS,���������������������Ӵ���Ȼ�������
(��ʵ���ǣ������a����Ȼ��b���м���LCS����������������Ҫ��¼dpʱ���·��)
����������һ��LCS��Ȼ���¼��·������LCS·������ĵ��������������ֱ���һ�£�
	Ȼ��û�б���ǹ���λ�÷ֱ�������������ǹ���λ�ã�
	��ô��ʾ�Ǹ�λ������ͬ���ַ������λ��ֻҪ���һ�Ρ�

*/
const int maxn = 100 + 5;
char str1[maxn], str2[maxn];
int dp[maxn][maxn];
bool path[maxn][maxn];
bool flag1[maxn], flag2[maxn];//if marked,then it is the overlap one

//����·��
void dfs(int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (path[i][j])
	{
		dfs(i - 1, j - 1);//�ظ����ֵĹ����Ӵ�
		flag1[i] = flag2[j] = true;
	}
	else if (dp[i - 1][j] > dp[i][j - 1])//��ͬ�Ļ������Ӵ����
		dfs(i - 1, j);
	else dfs(i, j - 1);
}

void output(int len1, int len2)
{
	int i = 1, j = 1;
	while (i <= len1 || j <= len2) {
		while (!flag1[i] && i <= len1)
			printf("%c", str1[i++]);
		while (!flag2[j] && j <= len2)
			printf("%c", str2[j++]);
		if (flag1[i])
		{
			printf("%c", str1[i]);
			i++, j++;
		}
	}
	puts("");
}

int main()
{
	while (scanf("%s%s", str1 + 1,str2+1) != EOF)
	{
		int len1 = strlen(str1 + 1), len2 = strlen(str2 + 1);
		memset(path, false, sizeof(path));
		memset(dp, 0, sizeof(dp));
		memset(flag1, false, sizeof(flag1));
		memset(flag2, false, sizeof(flag2));
		for (int i = 1; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++)
			{
				if (str1[i] == str2[j])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
					path[i][j] = true;
				}
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		dfs(len1, len2);
		output(len1, len2);
	}
	return 0;
}