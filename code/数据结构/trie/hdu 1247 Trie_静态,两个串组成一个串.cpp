/*************************************************************************
	> File Name: hdu1247.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月28日 星期一 23时04分19秒
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

const int maxn = 5e4+5;
int Trie[maxn][26];//
int num[maxn];
int tot=1;


void insert(char *str)
{
    int len = strlen(str);
    int p = 0;
    for (int i=0;i<len;i++)
    {
        int id = str[i]-'a';
        if (Trie[p][id]==0)
            Trie[p][id]=tot++;
        p = Trie[p][id];
    }
    num[p]=1;//字符串结尾
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
        p = Trie[p][id];
    }
    if (num[p]) return 1;
    else return 0;
}

char str[50001][20];

int main()
{
    freopen("in","r",stdin);

    int cnt=0;
    while(scanf("%s",str[cnt])!=EOF)
    {
        insert(str[cnt]);
        cnt++;
    }
    char a[20],b[20];
    for (int i=0;i<cnt;i++)
    {
        int len = strlen(str[i]);
        for (int j=0;j<len;j++)
        {
            memset(a,'\0',sizeof(a));
            memset(b,'\0',sizeof(b));
            strncpy(a,str[i],j);
            strncpy(b,str[i]+j,len-j);
            if (query(a) && query(b))
            {
                printf("%s\n",str[i]);
                break;
            }
        }
    }
    return 0;
}
