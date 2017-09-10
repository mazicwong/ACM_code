/*************************************************************************
	> File Name: hdu6205.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月11日 星期一 01时01分29秒
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

const int maxn = 1e6+5;
int a[maxn<<1];
int b[maxn<<1];

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
    inline void read(int &x) {  
        char ch;  
        while(blank(ch = nc()));  
        if(IOerror)return;  
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');  
    }  
#undef BUF_SIZE  
};  
using namespace fastIO;

int chiqu(int n)
{
    int s=1,t=1;
    int ans=0,len=0,sum=0;
    while(s<=n && t<=n)
    {
        if (sum>0) sum += (a[t]-b[t]), t++;
        if (t-s+1 >= len)
        {
            len = t-s+1;
            ans = s-1;
        }
        if (sum<=0) sum -= (a[s]-b[s]), s++;
    }
    return ans;
}

int main()
{
    freopen("in","r",stdin);
    int n;
    while(read(n),!fastIO::IOerror)
    {
        for (int i=1;i<=n;i++) read(a[i]),a[i+n]=a[i];
        for (int i=1;i<=n;i++) read(b[i]),b[i+n]=b[i];
        printf("%d\n",chiqu(2*n));
    }
    return 0;
}
