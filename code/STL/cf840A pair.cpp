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
/*
 * 给出a[]和b[],现在固定b[],对a[]重排列,使得b[]中的最小到最大分别对应a[]中的最大到最小,
 * 输出排列后的a[]
 *
 * 思路:a存数组,b存pair<num,index>
 * a从大到小排,b按first从小到大排
 * 然后直接ans[b[i].second] = a[i]
 *
 * 适用于排序后还要记住原来的下标的
 */
const int maxn = 2e5+5;
int a[maxn];
int ans[maxn];
bool cmp(int a,int b)
{
    return a>b;
}
typedef pair<int,int> pii;
pii b[maxn];

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
