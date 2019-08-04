/*************************************************************************
	> File Name: hdu1686.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月10日 星期四 01时56分49秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1e4+5;
const int maxm = 1e6+5;
char P[maxn],T[maxm];
int nxt[maxn];
//问模式串P在母串T中出现的次数,KMP可以解决

void getnxt()
{//nxt从1开始,字符串从0开始
    int pp = strlen(P);
    nxt[0]=-1;
    int k=-1,j=0;
    while(j<pp)
    {
        if (k==-1 || P[j]==P[k]) //P[k]前缀,P[j]后缀
        {
            j++;k++;
            //优化,出现P[j]=P[nxt[j]]时进行递归,k=nxt[k]=nxt[nxt[k]]
            if (P[j]!=P[k]) nxt[j]=k;//没优化是直接这个
            else nxt[j]=nxt[k];
        }
        else k=nxt[k];
    }
}

int kmp_count()
{
    int ans = 0;
    int tt=strlen(T),pp=strlen(P);
    int i=0,j=0;
    while(i<tt)
    {
        while(j!=-1 && T[i]!=P[j]) j=nxt[j];
        i++;j++;
        if (j>=pp)
        {
            ans++;
            j=nxt[j];
        }
    }
    return ans;
}
/******************************KMP**************************/

int main()
{
    freopen("in","r",stdin);
    int t;
    cin >> t;
    while(t--)
    {
        scanf("%s%s",P,T);
        getnxt();
        printf("%d\n",kmp_count());
    }
    
    return 0;
}
