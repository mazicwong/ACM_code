#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <time.h>
using namespace std;

const int maxn = 1e6+5;
int Trie[maxn][26];
int num[maxn] = {0};
int tot=1;

void insert(char *str)
{
    int len = strlen(str);
    int p = 0;
    for(int i=0;i<len;i++)
    {
        int id = str[i]-'a';
        if(Trie[p][id] == 0)
            Trie[p][id] = tot++;
        p = Trie[p][id];
        num[p]++;
    }
}

int query(char *str)
{
    int len = strlen(str);
    int p = 0;
    for(int i=0;i<len;i++)
    {
        int id = str[i]-'a';
        if(num[Trie[p][id]] == 1)
            return i+1;
        p = Trie[p][id];
    }
    return len;
}

char str[1005][21];

int main()
{
    tot=1;
    int cnt=0;
    while(scanf("%s",str[cnt]) != EOF)
    {
        insert(str[cnt]);
        cnt++;
    }
    for(int i=0;i<cnt;i++)
    {
        int fi = query(str[i]);
        cout << str[i] << ' ';
        for(int j=0;j<fi;j++) cout << str[i][j];
        cout << endl;
    }
    return 0;
}
