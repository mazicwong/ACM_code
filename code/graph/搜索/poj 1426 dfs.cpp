/*************************************************************************
	> File Name: poj1426.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月18日 星期二 09时13分17秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
/* 从1开始，每次分为两种情况
 * t*10  或者  t*10+1
 */
const int maxn = 200+5;
typedef unsigned long long ull;
int n;
ull ans = 0;
bool flag;
void dfs(ull t,int n,int k)
{
    if (flag)
        return;
    if (t%n==0)
    {
        //printf("%I64u\n",t);
        ans = t;
        flag = true;
        return ;
    }
    if (k==19) //第19层，回溯，否则溢出
        return;
    dfs(t*10,n,k+1);
    dfs(t*10+1,n,k+1);
}

int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    while(cin>>n && n)
    {
        ans = 0;
        flag = false;
        dfs(1,n,0);//从1开始，搜i的倍数，第k次搜索
        cout << ans << endl;
    }
    return 0;
}
