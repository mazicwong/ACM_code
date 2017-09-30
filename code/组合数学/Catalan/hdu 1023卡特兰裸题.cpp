/*************************************************************************
	> File Name: hdu 1023.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月16日 星期日 20时21分37秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
//hdu 1023 Catalan裸题
//h(n) = (4*n-2)/(n+1)*h(n-1)

/* 打表卡特兰数
 * 第n个卡特兰数存a[n]中，a[n][0]是长度
 * 数是倒过来存放的，个位是a[n][1];输出时注意倒过来
 */

int a[105][100];
void catalan()
{//a[1]=1;a[2]=2;
    freopen("in.txt","r",stdin);
    int i,j;
    a[2][0]=1;
    a[2][1]=2;
    a[1][0]=1;
    a[1][1]=1;
    int len=1;
    int yu;
    for (i=3;i<101;i++)
    {
        yu = 0;
        for (j=1; j<=len; j++)
        {
            int tmp = (a[i-1][j])*(4*i-2)+yu;
            yu = tmp/10;
            a[i][j] = tmp%10;
        }
        while(yu)
        {
            a[i][++len]=yu%10;
            yu/=10;
        }
        for (j=len; j>=1; j--)
        {
            int tmp = a[i][j] + yu*10;
            a[i][j] = tmp/(i+1);
            yu = tmp%(i+1);
        }
        while(!a[i][len])
            len--;
        a[i][0]=len;
    }
}

int main()
{
    catalan();
    int n;
    while(cin >> n)
    {
        for(int i=a[n][0];i>0;i--)
            printf("%d",a[n][i]);
        cout << endl;
    }
    return 0;
}
