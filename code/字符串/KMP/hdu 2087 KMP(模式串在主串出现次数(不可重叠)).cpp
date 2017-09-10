/*************************************************************************
	> File Name: hdu2087.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月10日 星期四 05时53分10秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1e3+5;
char P[maxn],T[maxn];
int nxt[maxn];
void getnxt()
{//nxt从1开始,字符串从0开始
    int pp = strlen(P);
    nxt[0]=-1;
    int k=-1,j=0;
    while(j<pp-1)
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
int kmp()
{//返回模式串P在主串T中首次出现的位置,从0开始
    int tt=strlen(T),pp=strlen(P);
    int i=0,j=0;
    while(i<tt && j<pp)
    {
        //如果j=-1，或者当前字符匹配成功（即T[i] == P[j]）,都令i++,j++
        if (j==-1 || T[i]==P[j])
        {
            i++;
            j++;
        }
        //如果j!=-1，且当前字符匹配失败（即T[i] != P[j]）,则令i不变,j=nxt[j]
        else
        {
            j=nxt[j];
        }
    }
    if (j==pp) return i-j;
    else return -1;
}

int kmp_count()
{//返回模式串在主串T中出现的次数(法1:较慢)
    int tt=strlen(T),pp=strlen(P);
    int i=0,j=0;
    int ans=0;
    while(i<tt)
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
        if (j>=pp)
        {
            ans++;
            j=0;
        }
    }
    return ans;
}
int kmp_count1()
{//返回模式串在主串T中出现的次数
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
    while(scanf("%s",T) && T[0]!='#')
    {
        scanf("%s",P);
        getnxt();
        printf("%d\n",kmp_count());
    }
    return 0;
}
