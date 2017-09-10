/*************************************************************************
	> File Name: hdu1711.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月09日 星期三 20时42分12秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1e6+5;
const int maxm = 1e4+5;

int T[maxn],P[maxm];
int nxt[maxm];
int n,m;

void getnxt()
{
    nxt[0]=-1;
    int k=-1,j=0;
    while(j<m-1)
    {
        if (k==-1 || P[j]==P[k]) //P[k]前缀,P[j]后缀
        {
            j++;k++;
            //优化,出现P[j]=P[nxt[j]]时进行递归,k=nxt[k]=nxt[nxt[k]]
            if (P[j]!=P[k]) nxt[j]=k;
            else nxt[j]=nxt[k];
        }
        else k=nxt[k];
    }
}

int kmp()
{
    int i=0,j=0;
    while(i<n && j<m)
    {
        if (j==-1 || T[i]==P[j])
        {
            i++;
            j++;
        }
        else
        {
            j=nxt[j];
        }
    }
    if (j==m) return i-j;
    else return -1;
}
/******************************KMP**************************/

int main()
{
    freopen("in","r",stdin);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for (int i=0;i<n;i++)
            scanf("%d",&T[i]);
        for (int i=0;i<m;i++)
            scanf("%d",&P[i]);
        getnxt();
        int ans = kmp();
        if (ans!=-1) ans++;
            printf("%d\n",ans);
    }
    return 0;
}
