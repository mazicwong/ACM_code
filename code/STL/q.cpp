/*************************************************************************
	> File Name: q.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月21日 星期六 19时05分45秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int maxn = 1e7+5;

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
/*
void used()
{
    while(read(n),!fastIO::IOerror)
    {
        readint(T);
        for (int i=1;i<=n;i++)
            readint(a[i]);
        char str[maxn];
        read(str);
    }
}
*/

typedef long long ll;

template <class T>
inline void scan_d(T &ret) 
{
        char c; 
        ret = 0;
        while ((c = getchar()) < '0' || c > '9');
        while (c >= '0' && c <= '9')
        { 
                ret = ret * 10 + (c - '0'), c = getchar();
            }

}

template <class T>
inline bool ssss(T &ret) {
    char c; int sgn;
    if(c=getchar(),c==EOF) return 0; //EOF
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;

}


 inline int rrread()
  {
       int x=0,f=1;char ch=getchar();
     while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
      while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
     return x*f;
  
 }
int main()
{
    freopen("in1","r",stdin);
    //freopen("in1","w",stdout);
    //std::ios::sync_with_stdio(false); //cin.tie(0);
    int i;
    double st;
    st=clock();
    while(maxn--)
    read(i);
    //readint(i);
    printf("%.3lf\n",double(clock()-st)/CLOCKS_PER_SEC);
    
    return 0;
}
