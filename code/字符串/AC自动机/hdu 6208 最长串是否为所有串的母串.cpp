/*************************************************************************
	> File Name: hdu2222.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月21日 星期四 01时25分29秒
    http://blog.csdn.net/u012350533/article/details/18097301
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
 * AC自动机:
 * 1.用string+sync           各种TLE
 * 2.改用char ss[]           刚好卡过去..2800ms
 * 3.加了个fastIO输入挂...   2400ms就过了
 *
 * hdu 6208
 * 题意: 给n个字符串,问是否存在一个,使得其他n-1个串都是他的子串
 *
 * 思路: 将所有串建立trie树,拿最长的串进行匹配,如果匹配出n个子串,则成立
 * 如果有不止一个最长串,且他们不相同,则不可能成立;
 */

namespace fastIO  
{
    #define BUF_SIZE 100000  
    //fread -> read
    bool IOerror = 0;  
    inline char nc() {  
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;  
        if(p1 == pend) {  
            p1 = buf;  
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);  
            if(pend == p1) {  
                IOerror = 1;return -1;  
            }  
        }  
        return *p1++;  
    }  
    inline bool blank(char ch) {  
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';  
    }  
    inline int read(char x[]) {  
        char ch;  
        while(blank(ch = nc()));  
        if(IOerror)  
            return 0;  
        int k = 0;  
        for(x[k++] = ch; (ch = nc())&&(!blank(ch))&&(ch != EOF); x[k++] = ch);  
        x[k]='\0';  
        return k;  
    }
    inline void readint(int &x) {  
        char ch;  
        while(blank(ch = nc()));  
        if(IOerror)return;  
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');  
    }  
#undef BUF_SIZE  
};  
using namespace fastIO;  



const int maxn = 100000+5;//50*10000
struct AC_auto{
    int chd[maxn][26]; //trie
    int v[maxn];       //节点属性值
    int f[maxn];       //失配指针
    int last[maxn],tot,ans;
    void init()
    {
        tot=1;ans=0;
        memset(v,0,sizeof(v));
        memset(f,0,sizeof(f));
        memset(chd[0],0,sizeof(chd[0]));
    }
    void insert(const char *p)
    {
        int now=0;
        for(;*p;p++)
        {
            int id=*p-'a';
            if(chd[now][id]==0)
            {
                memset(chd[tot],0,sizeof(chd[tot]));
                chd[now][id]=tot++;
            }
            now=chd[now][id];
        }
        v[now]++; //标记结束的地方
    }
    bool query(char *p)
    {
        int now=0;
        for(;*p;p++)
        {
            int id=*p-'a';
            if (chd[now][id]==0) break;
            now=chd[now][id];
        }
        return v[now]&&(!(*p)); //走到末尾
    }
    int getFail()
    {
        queue<int> Q;
        f[0]=0;
        for(int c=0;c<26;c++)
        {
            int u=chd[0][c];
            if (u)
            {
                f[u]=0; Q.push(u); last[u]=0;
            }
        }
        while(!Q.empty())
        {
            int r=Q.front(); Q.pop();
            for(int c=0;c<26;c++)
            {
                int u=chd[r][c];
                if (!u) {chd[r][c]=chd[f[r]][c]; continue;}
                Q.push(u);
                int vv=f[r];
                while(vv && !chd[vv][c]) vv=f[vv];
                f[u]=chd[vv][c];
                last[u]=v[f[u]] ? f[u] : last[f[u]];
            }
        }
    }
    void solve(int j)
    {
        if (!j) return;
        if (v[j])
        {
            ans+=v[j];
            v[j]=0;
        }
        solve(last[j]);
    }
    void find(const char *T)
    {
        int len=strlen(T);
        int now=0;
        getFail();
        for (int i=0;i<len;i++)
        {
            int id=T[i]-'a';
            now=chd[now][id];
            if (v[now]) solve(now);
            else if(last[now]) solve(last[now]);
        }
    }
}ac;

int main()
{
    freopen("in","r",stdin);
    //std::ios_base::sync_with_stdio(false);std::cin.tie(0);
    int n;
    char ss[maxn];
    char maxss[maxn];
    //string ss;
    //string maxss;
    int t;cin>>t;
    while(t--)
    {
        ac.init();
        int maxcnt=0;
        int maxlen=0;
        //cin>>n;
        readint(n);
        for (int k=0;k<n;k++)
        {
            //cin>>ss;
            //scanf("%s",ss);
            //ss = read();
            read(ss);
            //ac.insert(ss.c_str());       //将所有模板串建立Trie树
            ac.insert(ss);       //将所有模板串建立Trie树
            //if (maxlen<ss.size())
            if (maxlen<strlen(ss))
            {
                //maxlen=ss.size();
                //maxss=ss;
                maxlen=strlen(ss);
                strcpy(maxss,ss);
                maxcnt=1;
            }
            //else if (maxlen==ss.size())
            else if (maxlen==strlen(ss))
            {
                //if (maxss!=ss)
                if (strcmp(maxss,ss)!=0)
                    maxcnt++;
            }
            //else if (maxlen>ss.size())
            else if (maxlen>strlen(ss))
            {
                ;
            }
        }
        if (maxcnt>1)
        {
            cout << "No\n";
            continue;
        }
        //ac.find(maxss.c_str());            //
        ac.find(maxss);            //
        if (ac.ans==n)
            cout << maxss << "\n";
        else cout << "No\n";
    }
    return 0;
}
