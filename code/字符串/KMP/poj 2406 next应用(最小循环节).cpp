/*************************************************************************
	> File Name: poj2406.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月12日 星期六 00时59分49秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 1e6+5;
char P[maxn];
int nxt[maxn];
void getnxt(char *P,int *nxt)
{//nxt从1开始,字符串从0开始
    int pp = strlen(P);
    nxt[0]=-1;
    int k=-1,j=0;
    while(j<pp)
    {
        if (k==-1 || P[j]==P[k]) //P[k]前缀,P[j]后缀
        {
            j++;k++;
            nxt[j]=k;
        }
        else k=nxt[k];
    }
}
int main()
{
    freopen("in","r",stdin);
    while(cin>>P && P[0]!='.')
    {
        getnxt(P,nxt);
        int len = strlen(P);
        int tt = len-nxt[len];
        int ans = 1;
        if (len%tt == 0)
            ans = len/tt;
        printf("%d\n",ans);

    }
    
    return 0;
}
