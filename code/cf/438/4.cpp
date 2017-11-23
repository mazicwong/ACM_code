/*************************************************************************
	> File Name: 4.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月05日 星期四 16时57分58秒
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
const int maxn = 105;
int str[maxn][maxn];

/*
 * 01
 * 10
 * 101
 * 11111
 * 0
 *
 * 0110
 * 01100
 * 1111111111
 */

int main()
{
    freopen("in","r",stdin);
    int n;cin>>n;
    for (int i=1;i<=n;i++)
    {
        scanf("%s",str[i]);
    }
    int m;cin>>m;
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);

    }

    
    return 0;
}

