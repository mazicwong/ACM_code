/*************************************************************************
	> File Name: hdu3746.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月10日 星期四 07时24分06秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
char P[maxn];
int nxt[maxn];

void getnxt()
{//nxt从1开始,字符串从0开始
    int pp = strlen(P);
    nxt[0]=-1;
    int k=-1,j=0;
    while(j<pp)
    {
        while(-1!=k && P[j]!=P[k])k=nxt[k];//不是首次且不匹配,更新P串位置
        j++;k++;
        nxt[j]=k;
    }
}

int main()
{
    freopen("in","r",stdin);
    int t;
    cin >> t;
    while(t--)
    {
        scanf("%s",P);
        getnxt();
        int len = strlen(P);
        if (nxt[len]==0)
        {
            printf("%d\n",len);
            continue;
        }
        int t = len-nxt[len];//最小循环节
        if (len%t==0) puts("0");//此时最小周期为len/t
        else printf("%d\n",t-len%t);
    }
    return 0;
}
