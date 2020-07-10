/*************************************************************************
	> File Name: hdu1671.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月28日 星期一 02时21分29秒
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
const int maxn = 1e4+5;
const int maxm = 10;

int main()
{
    
    return 0;
}



#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e4+5;//节点数
const int maxm = 10;//每个节点字母数
char tel[maxn][maxm];
int Trie[maxn*10][maxm];
bool end[maxn*10];//存每个串最后一个字母所在节点
bool flag;
int cnt;

void init()  //清空Trie
{
    cnt = 1;
    memset(trie, 0, sizeof(trie));
    memset(end, 0, sizeof(end));
}

void insert(char *str)
{
    int r = 0, i = 0, j;
    while(str[i])
    {
        if(end[r]) flag = false;  //遇到其它号码的结束标记
        j = str[i++]-'0';
        if(!trie[r][j])
            trie[r][j] = cnt++;
        r = trie[r][j];
    }
    for(int i = 0; i < 10; ++i)  //插入完成的节点还有孩子节点
        if(trie[r][i]) flag = false;
    end[r] = true;
}

int main()
{
    freopen("in","r",stdin);
    int T;cin>>T;
    while(T--)
    {
		int n;
        init();
        scanf("%d", &n);
        flag = true;
        for(int i = 0; i < n; ++i)
        {
            scanf("%s", tel[i]);
            insert(tel[i]);
        }
        puts(flag ? "YES" : "NO");
    }

    return 0;
}




//1671 解法一:静态模版--给个字典判断有无前缀
/*
题目意思很清楚：就是判断输入的电话号码中是否有号码是其他号码的前缀，很显然要用到字典树。根据分析可知:
如果字符串Xn=X1X2....Xn是字符串Ym=Y1Y2....Ym的前缀，有在插入的时候有两种情况:Xn在Yn之前插入，Xn在Yn之后插入。
1)如果Xn在Yn之前插入，那么在插入Yn的时候必然经过Xn的路径，此时可以根据判断在这条路径上是否已经有结点被标记已经构成完成的字符串序列来判断是否存在Yn的前缀；
2)如果Xn在Yn之后插入，那么插入完成之后当前指针指向的结点的next数组中的元素必定不全为NULL。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=100000+5;//字典树最大节点数目 10000*10=100000 
const int MAX=10;
struct Trie{
    int ch[maxn][MAX];//ch[i][j]==k表示第i个节点的j个儿子是节点k 
    //最大有maxn个节点,每个节点都有10个儿子,所以可以用成二维数组 
    int value[maxn];//value[i]==x表示第i个节点的权值为x 
    //如果是字符串的尾节点,这个位置就设置为1,否则全都设置为0 
    //非单词节点设为0,单词节点设为1
    int sz;//字典数一共有sz个节点,从0到sz-1进行标号
    
    //进行初始化
    void init()
    {
        sz=1;
        value[0]=0;
        memset(ch[0],0,sizeof(ch[0]));//ch是0表示没有儿子 
    }
    bool insert(char *str)
    {
        bool flag=true;
        int n=strlen(str);
        int u=0;//每次都从第0个节点开始??
        for (int i=0;i<n;i++)
        {
            int id=str[i]-'0';//id总是用来表示当前的字符
            if (ch[u][id]==0) //还没经过 
            {
                ch[u][id]=sz;
                value[sz]=0;
                memset(ch[sz],0,sizeof(ch[sz]));
                sz++;
            }
            u=ch[u][id];//把第u个节点的第j个儿子的节点ch[u][id]赋给u.....有点绕...好好理解
/*判断1 */ 
            if (value[u]>0) //在该字符串的每一个字符都判断一下,如果大于0说明前面已经存在当前插入串str的前缀了 
                flag=false;
        }
        value[u]=1;//只在每个字符串的最后一个数置权值为1
        if (flag) //如果前面没有自己的前缀,还要判断自己是不是别人的前面 
        {
/*判断2 */
            for (int i=0;i<MAX;i++)//判断该节点的所有儿子 
            {
                if (ch[u][i]!=0)//存在包含该串的长串
                {
                    flag=false;
                    break;
                }
            }
        }
        return flag;
    }
};
Trie trie;
char str[20];
int main()
{
    int t;
    scanf("%d",&t);
    int n;
    while (t--)
    {
        scanf("%d",&n);
        trie.init();
        bool flag=true;
        for (int i=0;i<n;i++)
        {
            scanf("%s",str);
            if (flag) //所以前面已经判断到有出现了,就不用继续执行了,可以省点时间 
                flag=trie.insert(str);
        }
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
