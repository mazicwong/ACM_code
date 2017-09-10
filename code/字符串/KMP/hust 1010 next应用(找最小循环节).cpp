/*************************************************************************
	> File Name: hust1010.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月11日 星期五 15时58分13秒
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
void getnxt(char *P)
{//nxt从1开始,字符串从0开始
    int pp = strlen(P);
    nxt[0]=-1;
    int k=-1,j=0;
    while(j<pp)
    {
        if (k==-1 || P[j]==P[k]) //P[k]前缀,P[j]后缀
        {
            j++;k++;
            /*
             * //优化版,出现P[j]=P[nxt[j]]时进行递归,k=nxt[k]=nxt[nxt[k]]
             * if (P[j]!=P[k]) nxtval[j]=k;
             * else nxt[j]=nxtval[k];
             */
            nxt[j]=k;
        }
        else k=nxt[k];
    }
}

int main()
{
    freopen("in","r",stdin);
    while(scanf("%s",P)!=EOF)
    {
        getnxt(P);
        int len = strlen(P);
        printf("%d\n",len-nxt[len]);
    }
    return 0;
}
