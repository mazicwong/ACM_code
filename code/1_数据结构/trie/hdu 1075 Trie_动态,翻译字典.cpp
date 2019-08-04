/*************************************************************************
	> File Name: hdu1075.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月28日 星期一 05时23分05秒
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

const int maxn = 11;
const int maxx = 3000+5;

struct Trie{
    char *v;
    Trie *next[26];
    Trie()
    {
        v=NULL;
        memset(next,0,sizeof(next));
    }
};
Trie *root;

void insert(char *raw,char *str1)
{
    Trie *p = root;
    int len = strlen(raw);
    //cout << endl << raw << "  " << str1 << endl;
    for (int i=0;i<len;i++)
    {
        int id = raw[i]-'a';
        if (p->next[id] == NULL)
            p->next[id] = new(Trie);
        p = p->next[id];
    }
    p->v = new char[11];
    strcpy(p->v,str1);
}
void query(char *str)
{
    Trie *p = root;
    int len = strlen(str);
    for (int i=0;i<len;i++)
    {
        int id = str[i]-'a';
        if (p->next[id] == NULL)
        {
            printf("%s",str);
            return;
        }
        p = p->next[id];
    }
    if (p->v!=NULL)
        printf("%s",p->v);
    else printf("%s",str);
}

void delete_(Trie *p)
{
    if (p==NULL)
        return;
    for (int i=0;i<maxn;i++)
        delete_(p->next[i]);
    delete(p);    
}

char ss[maxx];
int main()
{
    freopen("in","r",stdin);
    ios_base::sync_with_stdio(0);

    root = new Trie;
    char str[maxn],str2[maxn];
    scanf("%s",str);//start
    while(scanf("%s",str))
    {
        if (strcmp(str,"END")==0)
            break;
        scanf("%s",str2);
        //cout << endl << str << "  " << str2 << endl;
        insert(str2,str);
    }
    scanf("%s",str);//start
    getchar();

    while(1)
    {
        fgets(ss,sizeof(ss),stdin);//gets不读取换行,fgets会读取
        //cout << "ss:" << ss <<"  len:"<< strlen(ss)<<endl;
        //gets(ss);
        if (strcmp(ss,"END\n")==0)
            break;
        if (strcmp(ss,"END")==0)
            break;
        int len = strlen(ss);

        char tt[maxx];
        int idx = 0;
        for (int i=0;i<len;i++)
        {
            if (isalpha(ss[i]))
                tt[idx++]=ss[i];
            else
            {
                tt[idx]=0;
                query(tt);
                printf("%c",ss[i]);
                idx = 0;
            }
        }

        /*string a="";
        for (int i=0;i<len;i++)
        {
            if (isalpha(ss[i]))
                a+=ss[i];
            else
            {
                char tt[maxx];
                strcpy(tt,a.c_str());
                query(tt);
                printf("%c",a[i]);
                a="";
            }
        }*/
        //cout <<endl;
    }
    delete_(root);
    return 0;
}
