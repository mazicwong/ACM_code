/*************************************************************************
	> File Name: hdu1671.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月28日 星期一 00时49分50秒
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
using namespace std;
/*
 * hdu1671 给n个串,问其中是否存在一个串是另一个串的前缀
 * 经典Trie求前缀问题
 *
 * 每次经过把权值加1,保存下所有字符串最后一个字符所在的节点
 * 查询时,遍历所有保存的字符串结尾的节点,如果有不是1的,说明该字符串是别的串的前缀
 */

//动态Trie模板
const int maxn = 1e4+5;
const int maxm = 10;
struct Trie{
    Trie *next[maxm];
    int v;//根据题意不同变化,这里是每个字符串路过该节点多少次(即相同前缀)
    Trie():v(0){memset(next,0,sizeof(next));}
};
Trie *root;    //根节点,指向所有串的第一个字母
Trie *b[maxn]; //存每个串最后一个字母所在节点
int cnt = 0;   //串的结尾字母的个数


void insert(char *str)
{
    int len = strlen(str);
    Trie *p = root;
    for (int i=0;i<len;i++)
    {
        int id = str[i]-'0';
        if (p->next[id]==0)
        {
            p->next[id]=new Trie;
        }
        p = p->next[id];
        p->v++;//经过,权值+1
    }
    b[cnt++]=p;
}

int query(int n)
{
    for (int i=0;i<cnt;i++)
    {
        if (b[i]->v!=1)//权值非1,是别的串的前缀
            return 1;
    }
    return 0;
}

//动态Trie要释放数组,不然MLE
void delete_(Trie *p)
{
    if (p==0) return;//递归要有一个return 
    for (int i=0;i<maxm;i++)
        delete_(p->next[i]);
    delete p;
}

int main()
{
    freopen("in","r",stdin);
    int t;cin>>t;
    while(t--)
    {
        char str[15];
        root = new Trie;
        cnt = 0;
        int n;scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%s",str);
            insert(str);
        }
        if (query(n)) puts("NO");//存在前缀
        else puts("YES");
        delete_(root);
    }
}

