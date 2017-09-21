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
 * hdu2222 找所有单词在文章中出现多少个
 */

const int maxn = 500000+5;//50*10000
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
    void insert(char *p)
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
    void find(char *T)
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
    char str[1000000+5];
    char ss[100];
    int n;
    int t;cin>>t;
    while(t--)
    {
        ac.init();
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s",ss);
            ac.insert(ss);       //将所有模板串建立Trie树
        }
        scanf("%s",str);
        ac.find(str);            //
        printf("%d\n",ac.ans);   //单词出现个数;
    }
    return 0;
}
