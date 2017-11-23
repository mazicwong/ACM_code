/*************************************************************************
	> File Name: c.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月18日 星期五 23时41分44秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <map>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 2e5+5;
int a[maxn];
int ans[maxn];
int tmpb[maxn];
bool cmp(int a,int b)
{
    return a>b;
}
typedef pair<int,int> pii;
pii b[maxn];

//vector<int> V[maxn];
int main()
{
    freopen("in","r",stdin);
    int n;
    cin >> n;
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&b[i].first);
        b[i].second=i;
    }
    sort(a,a+n,cmp);
    sort(b,b+n);

    for (int i=0;i<n;i++)
    {
        ans[b[i].second] = a[i];
    }
    for (int i=0;i<n;i++)
        printf("%d ",ans[i]);
    return 0;
}
