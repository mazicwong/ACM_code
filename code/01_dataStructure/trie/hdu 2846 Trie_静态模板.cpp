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
 * 这题用动态模板死活MLE,在网上拉了六七份代码都过不了,只能用静态数组的写法了.
 *
 * hdu2846 给n个串,建立字典树,然后问某个串是多少个串的子串
 * Trie求前缀重复问题(处理好字典树)
 *
 * 因为查询的子串可能在树中间,这时就要引入后缀的思想，
 * 把样本字符串的所有后缀都输入字典树，
 * 从而待查找的字符串，肯定是这些后缀的一个前缀，最后只需返回后缀数目即可。
 *
 * 注意:会有一种情况,abab这种串,后缀会重复计两次,所以再加上一个num,
 * 仅当这个后缀在查询的串中没有,才会+1,避免重复
 * 
 *
 * 每次经过把权值加1
 * 查询时,走到最后一个节点,然后该点权值就是经过他的串的数,即为答案
 */

/*
//动态Trie模板 MLE
const int maxn = 22;
const int maxm = 26;
struct Trie{
    Trie *next[maxm];
    int num;
    int v;     //点权,根据题意不同变化,这里是每个字符串路过该节点多少次(即相同前缀)
    Trie()
    {
        v=0;
        num=0;
        memset(next,0,sizeof(next));
    }
};
Trie *root;    //根节点,指向所有串的第一个字母

void insert(char *str,int num0)
{
    int len = strlen(str);
    Trie *p = root;
    for (int i=0;i<len;i++)
    {
        int id = str[i]-'a';//要注意这里是数字还是字母..
        if (p->next[id]==0)
        {
            p->next[id]=new Trie;
        }
        p = p->next[id];
        if (p->num!=num0) //相同串的后缀没建立过
            p->v++;//路过,权值加1
        p->num=num0;
    }
}

int query(char *str)
{
    int len = strlen(str);
    Trie *p = root;
    for (int i=0;i<len;i++)
    {
        int id = str[i]-'a';
        if (p->next[id]==0)
            return 0;//串不存在
        p = p->next[id];
    }
    return p->v;
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
    char str[maxn];
    root = new Trie;//Trie树根
    
    int n;scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",str);
        int len = strlen(str);
        for (int j=0;j<len;j++)
            insert(str+j,i);
    }

    int q;scanf("%d",&q);
    while(q--)
    {
        scanf("%s",str);
        printf("%d\n",query(str));
    }
    delete_(root);
    return 0;
}
*/


//Trie静态模板
//http://blog.csdn.net/qq_36345036/article/details/77184574
const int maxn = 3e5+5;//1e4*26
const int maxm = 26;
int Trie[maxn][maxm];//每个点是否有路过
int cnt[maxn];//记录经过该前缀串的次数
int id[maxn];//标记,同一个串的后缀不要计重复
int top=0;
int root;
int ans;

void init()
{
    top=0;
    memset(Trie,0,sizeof(Trie));
    memset(cnt,0,sizeof(cnt));
    memset(id,0,sizeof(id));
    root = top++;
}

void insert(char *str,int x)
{
    int len = strlen(str);
    int p = root;
    for (int i=0;i<len;i++)
    {
        int idx = str[i]-'a';
        if (Trie[p][idx]==0) Trie[p][idx]=top++;
        p = Trie[p][idx];
        if (id[p]!=x)
            cnt[p]++;
        id[p]=x;
    }
}

//询问就直接走到叶子节点再看前缀个数,
//如果过程中不能走了,说明不存在,直接返回0就好了
int query(char *str)
{
    int len = strlen(str);
    int p = root;
    for (int i=0;i<len;i++)
    {
        int idx = str[i]-'a';
        if (Trie[p][idx]==0) return 0;
        p = Trie[p][idx];
    }
    return cnt[p];
}

int main()
{
    freopen("in","r",stdin);
    int n;scanf("%d",&n);
    init();
    char str[23];
    for (int i=1;i<=n;i++)
    {
        scanf("%s",str);
        int len = strlen(str);
        for (int j=0;j<len;j++)
        {
            insert(str+j,i);
        }
    }
    int q;scanf("%d",&q);
    while(q--)
    {
        scanf("%s",str);
        printf("%d\n",query(str));
    }
    return 0;
}
