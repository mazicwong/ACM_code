/*************************************************************************
	> File Name: poj2752.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月12日 星期六 01时27分01秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 4e5+5;
char P[maxn];
int nxt[maxn];
void getnxt()
{
    int k=-1,j=0;
    nxt[0]=-1;
    int pp=strlen(P);
    while(j<pp)
    {
        if(k==-1 || P[k]==P[j])
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
    while(scanf("%s",P)!=EOF)
    {
        int len = strlen(P);
        getnxt();
        int ans[maxn];
        int cnt = 0;
        ans[cnt++]=len;

        int tmp=nxt[len];
        while(tmp!=0 && tmp!=-1)
        {
            ans[cnt++]=tmp;
            tmp=nxt[tmp];
        }
        sort(ans,ans+cnt);
        for (int i=0;i<cnt;i++)
            printf(i==cnt-1?"%d\n":"%d ",ans[i]);
    }
    return 0;
}
