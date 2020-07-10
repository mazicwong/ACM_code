/*************************************************************************
	> File Name: hdu2594.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月22日 星期五 17时07分32秒
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
 * hdu2594
 * given two string s1,s2
 * out a longest line that is a prefix of s1 and a suffix of s2
 */

const int maxn = 50000+5;
char str1[maxn<<1],str2[maxn];
char ss[maxn<<1];
int Next[maxn<<1];

void getNext(char *P)
{//Next从1开始,字符串从0开始
    int pp = strlen(P);
    Next[0]=-1;
    int k=-1,j=0;
    while(j<pp)
    {
        while(-1!=k && P[j]!=P[k])k=Next[k];
        j++;k++;
        Next[j]=k;
    }
}

int main()
{
    freopen("in","r",stdin);
    while(scanf("%s",str1)!=EOF)
    {
        scanf("%s",str2);
        int n=strlen(str1);
        int m=strlen(str2);
        for (int i=0;i<m;i++)
            str1[i+n]=str2[i];
        str1[n+m]='\0';
        getNext(str1);
        int maxlen = Next[n+m];
        /*
        cout << endl;
        for (int i=0;i<=n+m;i++)
            printf ("%d ",Next[i]);
        cout << endl;
            */
        if (maxlen==0)
        {
            printf("0\n");
            continue;
        }
        for (int i=0;i<maxlen && i<min(n,m);i++)
            printf("%c",str1[i]);
        int ans = min(maxlen,min(n,m));
        printf(" %d\n",ans);
    }
    return 0;
}
