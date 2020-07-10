/*************************************************************************
	> File Name: hdu1251.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月28日 星期一 13时57分50秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
/*
 * hdu1251 Trie模板题(动态)
 * 给一堆串组成的字典,
 * 然后给一些查询,问一个子串是多少个串的前缀
 * 注意字典和查询中间用空行分开(这里用gets判断第一个是不是'\0'就行了)
 * gets: 可以读取一个空行,每一行最后的'\n'会转换成'\0'
 */

struct Trie{
    int v;
    Trie *next[26];
    Trie()
    {
        v = 0;
        memset(next,0,sizeof(next));
    }
};
Trie *root;//根节点指针

void insert(char *str)
{
    int len = strlen(str);
    Trie *p = root;
    for (int i=0;i<len;i++)
    {
        int id = str[i]-'a';
        if (p->next[id]==NULL)
            p->next[id] = new Trie;
        p = p->next[id];
        p->v++;
    }
}

int query(char *str)
{
    int len = strlen(str);
    Trie *p = root;
    for (int i=0;i<len;i++)
    {
        int id = str[i]-'a';
        if (p->next[id]==NULL)
            return 0;
        p = p->next[id];
    }
    return p->v;
}

void delete_(Trie *p)
{
    if (p==0)
        return;
    for (int i=0;i<26;i++)
    {
        delete_(p->next[i]);
    }
    delete p;
}

const int maxn = 11;
char str[maxn];
int main()
{
    freopen("in","r",stdin);
    root = new Trie;
    while(gets(str) && str[0]!='\0')
    {
        insert(str);
    }
    while(scanf("%s",str)!=EOF)
    {
        printf("%d\n",query(str));
    }
    return 0;
}
