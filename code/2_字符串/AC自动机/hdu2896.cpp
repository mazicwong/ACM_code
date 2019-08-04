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
    void insert(char *p,int cnt)  //传入子串&编号
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
        v[now]=cnt; //标记结束的地方
    }
    bool query(char *p)    //利用节点属性值查询子串(单词)是否出现
    {
        int now=0;
        for(;*p;p++)
        {
            int id=*p-'a';
            if (chd[now][id]==0) break;
            now=chd[now][id];
        }
        return v[now]&&(!(*p));
    }
    //求Trie失配数组f[] & last[]; 套路来的,不用修改
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
    void solve(int j,int cnt)
    {
        if (!j) return;
        if (v[j])
        {
            if (ans==0)
                printf("web %d:",cnt);  ////
            ans+=v[j];
            printf(" %d",v[j]);         ////
            //v[j]=0;
        }
        solve(last[j],cnt);
    }
    void find(char *T,int cnt) //找母串(文章)中子串(单词)出现次数
    {
        int len=strlen(T);
        int now=0;
        getFail();
        for (int i=0;i<len;i++)
        {
            int id=T[i]-'a';
            now=chd[now][id];
            if (v[now]) solve(now,cnt);
            else if(last[now]) solve(last[now],cnt);
        }
    }
}ac;

int main()
{
    freopen("in","r",stdin);
    char str[1000+5];
    char ss[200+5];
    int n;cin>>n;
    ac.init();
    for (int i=1;i<=n;i++)
    {
        scanf("%s",ss);
        ac.insert(ss,i);       //将所有模板串建立Trie树
    }
    int m;cin>>m;
    int total=0;
    for (int i=1;i<=m;i++)
    {
        scanf("%s",str);
        ac.find(str,i);            //
        cout << "\n tt ";
        /*
        if (ac.ans)
        {
            ac.ans=0;
            total++;
            puts("");
        }*/
    }
    printf("total: %d",total);
    return 0;
}
