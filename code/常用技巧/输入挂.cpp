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

//use
while(read(n),!fastIO::IOerror)
{
    readint(T);
    for (int i=1;i<=n;i++)
        readint(a[i]);
    char str[maxn];
    read(str);
}


//////////another////////////

inline ll read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
