/*
hdu 4287 ¼òµ¥×ÖµäÊ÷+hash1Ó³Éä
http://blog.csdn.net/mxway/article/details/9205101

*/
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
using namespace std;

const int maxn = 5000 + 5;
int cnt, result[maxn];
char word[10], s[10];
int hash1[128];

struct TrieNode {
	int no;
	TrieNode *next[10];
}node[maxn * 6];
TrieNode *root = &node[0];

void init()
{
	hash1['a'] = hash1['b'] = hash1['c'] = 2;
	hash1['d'] = hash1['e'] = hash1['f'] = 3;
	hash1['g'] = hash1['h'] = hash1['i'] = 4;
	hash1['j'] = hash1['k'] = hash1['l'] = 5;
	hash1['m'] = hash1['n'] = hash1['o'] = 6;
	hash1['p'] = hash1['q'] = hash1['r'] = hash1['s'] = 7;
	hash1['t'] = hash1['u'] = hash1['v'] = 8;
	hash1['w'] = hash1['x'] = hash1['y'] = hash1['z'] = 9;
}

void initRoot()
{
	for (int i = 0; i < 10; i++)
		root->next[i] = NULL;
}

//½¨Á¢×ÖµäÊ÷
void insert(char str[], int num)
{
	TrieNode *p = root;
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (p->next[str[i] - '0'] == NULL)
		{
			p->next[str[i] - '0'] = &node[cnt];
			for (int j = 0; j < 10; j++)
				node[cnt].next[j] = NULL;
			node[cnt].no = -1;
			cnt++;
		}
		p = p->next[str[i] - '0'];
	}
	p->no = num;
}

void query(char str[])
{
	int len = strlen(str);
	TrieNode *p = root;
	for (int i = 0; i < len; i++)
	{
		p = p->next[hash1[str[i]]];
		if (p == NULL)
			break;
	}
	if (p == NULL) return;
	else
		if (p->no != -1)
			result[p->no]++;
}
int main()
{
	int t, n, m;
	scanf("%d", &t);
	init();
	while (t--)
	{
		cnt = 1;
		initRoot();
		memset(result, 0, sizeof(result));
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", &word);
			insert(word, i);
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%s", &s);
			query(s);
		}
		for (int i = 0; i < n; i++)
			printf("%d\n", result[i]);
	}
	return 0;
}