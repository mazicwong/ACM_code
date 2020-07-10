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


/* hdu3068
 * manacher“马拉车”算法: 计算字符串的最长回文字串 O(n)
 *
 * 算法:每两个相邻字符中插入一个分隔符'#'
 * 新串下标从1开始
 *
 * 把奇偶长度的回文串同意考虑了
 * 为了避免更新P的时候导致越界，我们在字符串T的前增加一个特殊字符，
 *
 * 比如说‘$’,所以算法中字符串是从1开始的
*/

/*
  原串：       w   a   a   b   w   s   w   f   d
  新串：     # w # a # a # b # w # s # w # f # d #
辅助数组P：  1 2 1 2 3 2 1 2 1 2 1 4 1 2 1 2 1 2 1

P[id]: 记录以str[id]为中心的最长回文串
当以str[id]为第一个字符,这个最长回文串向右延伸了P[id]个字符
P[id]-1就是该回文子串在原串中的长度（包括‘#’）

参数说明:
str[i]:  存原串
Ma[i]:   存插入#扩展后的新串
Mp[i]:   
*/


const int MAXN=110010;
char Ma[MAXN*2];//新串,插入#后的
int Mp[MAXN*2]; //Mp[i]-1是Ma[i]所在的回文子串在原串的长度
void Manacher(char s[],int len)
{
    //计算Ma[0..2*len)   
    int l=0;
    Ma[l++]='$';//字符串开头增加一个特殊字符，防止越界
    Ma[l++]='#';
    for(int i=0;i<len;i++)
    {
        Ma[l++]=s[i];
        Ma[l++]='#';
    }
    Ma[l]=0;

    //计算Mp[0..2*len)
    int mx=0,id=0;//mx为当前计算回文串最右边字符的最大值
    for(int i=0;i<l;i++)
    {
        Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
        while(Ma[i+Mp[i]]==Ma[i-Mp[i]])Mp[i]++;
        if(i+Mp[i]>mx)
        {
            mx=i+Mp[i];
            id=i;
        }
    }
}
 /*
  *
  * * abaaba
  * * i:     0 1 2 3 4 5 6 7 8 9 10 11 12 13
  * * Ma[i]: $ # a # b # a # a # b  #  a  #
  * * Mp[i]: 1 1 2 1 4 1 2 7 2 1 4  1  2  1
  * */
char str[MAXN];
int main()
{
    //freopen("in","r",stdin);
    while(scanf("%s",str)!=EOF)
    {
        int len=strlen(str);
        Manacher(str,len);
        int ans=0;
        for(int i=0;i<2*len+2;i++)
            ans=max(ans,Mp[i]-1);
        printf("%d\n",ans);
    }
    return 0;
}
