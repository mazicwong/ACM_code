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

const int maxn = 1e6+5;//10层
int Trie[maxn][26];
int num[maxn]={0}; //节点属性值,根据题意来定,这里是以该串为前缀单词数
int tot = 1;//节点个数

void insert(char *str)
{
    int len = strlen(str);
    int p = 0;
    for (int i=0;i<len;i++)
    {
        int id = str[i]-'a';
        if (Trie[p][id]==0)
            Trie[p][id]=tot++;
        p=Trie[p][id];
        num[p]++;//节点属性值
    }
}

int query(char *str)
{
    int len = strlen(str);
    int p = 0;
    for (int i=0;i<len;i++)
    {
        int id = str[i]-'a';
        if (Trie[p][id]==0)
            return 0;
        p=Trie[p][id];
    }
    return num[p];
}

char str[11];
int main()
{
    freopen("in","r",stdin);
    tot=1;
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
