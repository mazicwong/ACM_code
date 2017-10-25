即字典树,给一些字符串,我们构造出来一颗树,相同前缀的串共用一些节点,在查询前缀后缀的时候很好用

一般有动态(指针)和静态(数组)两种实现方法,指针好理解点,但是在时间和空间上都不如数组好,原因是new的时候内存不连续,访问慢,而且指针本身的内存就是数组的两倍多,尽量用静态的;果用动态写法,交的时候用C++比G++好,



模板: 找一个字符串是多少个字符串的前缀(hdu1251)
(静态效率更好,动态指针很容易MLE)


/*
 * hdu1251 Trie模板题(静态)
 * 给一堆串组成的字典,
 * 然后给一些查询,问一个子串是多少个串的前缀
 * 注意字典和查询中间用空行分开(这里用gets判断第一个是不是'\0'就行了)
 * gets: 可以读取一个空行,每一行最后的'\n'会转换成'\0'
 */

#pragma comment(linker, "/STACK:102400000,102400000")
const int maxn = 1e6+5;//??总节点数,怎么搞
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



动态:
/*
 * hdu1251 Trie模板题(动态)
 * 给一堆串组成的字典,
 * 然后给一些查询,问一个子串是多少个串的前缀
 *
 * 注意输入字典和查询串中间用空行分开(这里用gets判断第一个是不是'\0'就行了)
 * gets: 可以读取一个空行,每一行最后的'\n'会转换成'\0'
 */

#pragma comment(linker, "/STACK:102400000,102400000")
struct Trie{
    int v;//节点属性,随题目改动,这里是有多少个串路过(即到该节点的串是多少个串的前缀)
    Trie *next[26];//儿子数,26个字母
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

//多组数据的Trie要delete_,不然MLE
void delete_(Trie *p)
{
    if (p==0)
        return;
    for (int i=0;i<26;i++)
        delete_(p->next[i]);
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
    delete_(root);
    return 0;
}

