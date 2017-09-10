/*************************************************************************
	> File Name: poj3320.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月11日 星期五 01时20分57秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 1e6+5;
const int INF = 0x3f3f3f3f;
int a[maxn];
map<int,int> cnt;
set<int> t;
int n;

void solve()
{
    int num = t.size();
    int ans = INF;
    int s=0,t=0,sum=0;

    while(1)
    {
        while(t<n && sum<num)
        {
            if (cnt[a[t++]]++ == 0) sum++;
        } 
        if (sum<num) break;
        ans = min(ans,t-s);
        if(--cnt[a[s++]] == 0) sum--;
    }
    printf("%d\n",ans);
}
int main()
{
    freopen("in","r",stdin);
    cin >> n;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        t.insert(a[i]);
    }
    solve();
    return 0;
}
