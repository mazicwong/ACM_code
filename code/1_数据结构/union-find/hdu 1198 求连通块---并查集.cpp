/*
* hdu 1198
* author  : mazciwong
* creat on: 2016-1-19
*/

/*
	����ͨ��,ֱ���ò��鼯���

*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 50 + 5;
int mp[maxn][maxn];
int fa[maxn*maxn];

int find(int x)
{
	if (-1 == fa[x])
		return x;
	else
		return fa[x] = find(fa[x]);
}

int unite(int x, int y)
{
	x = find(x), y = find(y);
	if (x != y)  //����һ��������,��x�Ƶ�y
	{
		fa[x] = y;
		return 1;
	}
	return 0;
}

//ԭ��11�����ε����----��������
int con[11][4] = {
	{1,0,1,0},//A
	{1,0,0,1},//B
	{0,1,1,0},//C  
	{0,1,0,1},//D  
	{1,1,0,0},//E  
	{0,0,1,1},//F  
	{1,0,1,1},//G  
	{1,1,1,0},//H  
	{0,1,1,1},//I  
	{1,1,0,1},//J  
	{1,1,1,1} //K  
};

//���������ƶ�ʱ,x��y������
int dir_x[] = { -1,1,0,0 };
int dir_y[] = { 0,0,-1,1 };

int main()
{
	int m, n;
	while (scanf("%d%d", &n, &m) != EOF&&n >= 0 && m >= 0)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				char ch;
				scanf(" %c", &ch);
				mp[i][j] = ch - 'A';
			}
		}
		memset(fa, -1, sizeof(fa));
		int ans = n*m;//�ʼ��ͨ��������

		//��������,�ϲ���ͨ����
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < m; y++)
			{
				int id = x*m + y;//һ��ʼ���ӱ��
				//�ĸ�����һ����û��ͨ
				for (int dir = 0; dir < 4; dir++)//�ж�dir�����Ǹ���ͨ��ͨ
				{
					int nx = x + dir_x[dir];
					int ny = y + dir_y[dir];
					int ndir = dir % 2==0 ? dir + 1 : dir - 1;//dir���෴����
					if (nx >= 0 && nx < n&&ny >= 0 && ny < m)
					{
						int nid = nx*m + ny;//dir������ӵı��
						if (con[mp[x][y]][dir] == 1 && con[mp[nx][ny]][ndir] == 1) //�����ͨ
							ans -= unite(id, nid);
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}