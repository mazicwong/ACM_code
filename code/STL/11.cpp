---
title: 输入挂
date: 2017-09-11 00:21:41
tags:
---


测试: hdu6208 青岛网络赛第三题的AC自动机,3000ms
- AC自动机:
- 1.用`string+sync`            各种TLE
- 2.改用`char ss[]`            刚好卡过去..2800ms
- 3.加了个`fastIO`输入挂...    2400ms就过了



```cpp
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


//how to use
while(read(n),!fastIO::IOerror)
{
    readint(T);
    for (int i=1;i<=n;i++)
        readint(a[i]);
    char str[maxn];
    read(str);
}
```


/**********another***********/

```cpp
inline ll read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
```

/**********another***********/
```cpp
std::ios::sync_with_stdio(false);
cin.tie(0);
```




/**********test***********/
```cpp
#include <ctime>
int main()
{
    double start = clock();
    // do sth;
    printf("%.3lf\n",double(clock()-start)/CLOCKS_PRE_SEC);
}
```


const int maxn = 1e7+5;

//1.302s
while(maxn--) cin>>i;

//0.858
while(maxn--) scanf("%d",&i);

//0.497
std::ios::sync_with_stdio(false);
while(maxn--) cin>>i;

//0.461
std::ios::sync_with_stdio(false); cin.tie(0);
while(maxn--) cin>>i;

