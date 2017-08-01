/*************************************************************************
	> File Name: A.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月25日 星期二 12时00分44秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
int main()
{
    freopen("in","r",stdin);
    int n;
    int cas=1;
    int ans=0;
    while(scanf("%d",&n)!=EOF)
    {
        ans = n*log(2)/log(10);
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
