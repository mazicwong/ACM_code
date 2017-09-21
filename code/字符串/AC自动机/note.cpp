http://paste.ubuntu.com/25573425/

单模匹配算法: 一个单词,一个字符串  KMP
KMP状态转移图:线性字符串+失配边

多模匹配算法: 多个单词,一段字符串  AC自动机
AC自动机状态转移图:Trie+失配边


一共3步
1.建Trie树
2.在Trie树上建立失配指针,成为AC自动机
3.自动机上匹配字符串



对模板的修改主要在于属性值v[],
然后下面四步都是比较固定的.
ac.init();
ac.insert(p);   //插入子串(单词)
ac.query(p);    //查找子串是否出现在字典树中
ac.find(T);     //母串跑一遍匹配看有多少个单词
ac.ans;         //匹配母串的单词数



/************比kuangbin块4倍的模板**********/
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
/************比kuangbin块4倍的模板**********/








***
hdu2222  公认AC自动机模板题

题意:找到有多少个单词在字典中出现

思路:所有单词建立Trie,然后母串跑一边AC自动机

PS:找到一个比kuangbin大神还块4倍的模板,放在上面了




***
hdu6208 青岛网络赛第三题...

题意: 给n个字符串,问是否存在一个,使得其他n-1个串都是他的子串

思路: 将所有串建立trie树,拿最长的串进行匹配,如果匹配出n个子串,则成立
如果有不止一个最长串,且他们不相同,则不可能成立;

PS: 这里的AC自动机很裸...但本题真正尝试过程在这里....
1.用string+sync           各种TLE
2.改用char ss[]           刚好卡过去..2800ms
3.加了个fastIO输入挂...   2400ms就过了
 
另外,这题也可以用n次KMP跑出来;
还有,据说n次strstr更快...学习了.



***
