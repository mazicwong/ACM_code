/*************************************************************************
	> File Name: poj3080.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月12日 星期六 02时10分53秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/*
 * poj3080 求n个串的最长公共子串
 */


const int N = 60+5;
char T[N];//母串
char P[N];//模板串  
int Next[N+1];//失配串(位数比模板串多1)
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
void kmp1(char *T, char *P) //(未验证)
{
	int tt=strlen(T),pp=strlen(P);
	int j=-1;
	for (int i = 0; i < tt; i++)
	{
		while (j!=-1 && T[i]!=P[j]) j=Next[j];
		if (T[i]==P[j]) j++;
		if (j==pp) printf("%d\n", i-pp+1);//就算j到pp了，也用Next[pp]继续匹配  
	}
}

int kmp(char *T,char *P)
{//返回模式串P在主串T中首次出现的位置,从0开始
    int tt=strlen(T),pp=strlen(P);
    int i=0,j=0;
    while(i<tt && j<pp)
    {
        //如果j=-1，或者当前字符匹配成功（即T[i] == P[j]）,都令i++,j++
        if (j==-1 || T[i]==P[j]) i++,j++;
        //如果j!=-1，且当前字符匹配失败（即T[i] != P[j]）,则令i不变,j=Next[j]
        else j=Next[j];
    }
    if (j==pp) return i-j;//return true;
    else return -1;//return false;
}


char str[11][N];
char ss[N];
int main()
{
    freopen("in","r",stdin);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        for (int i=0;i<n;i++)
            scanf("%s",str[i]);
        char pp[62]="";
        for (int len=1;len<=60;len++)
        {
            bool flag = true;
            for (int j=0;j+len<60;j++)
            {
                strncpy(ss,str+j,len);
                getNext(ss);
                if (kmp(str,ss)==-1)
                {
                    flag=false;
                }
            
            }
            if (flag)
            {
                printf("")
                break;
            }
        }

    }

    
    return 0;
}
