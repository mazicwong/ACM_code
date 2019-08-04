/*************************************************************************
	> File Name: hdu1029_sort.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月24日 星期一 09时42分48秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1e6+5;
int a[maxn];
int main()
{
    int n;
    freopen("in","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        printf("%d\n",a[(n+1)/2]);
    }
    return 0;
}
