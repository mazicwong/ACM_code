/*************************************************************************
	> File Name: 2.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月25日 星期五 00时43分12秒
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

const int maxn = 52;
int row1[maxn],row0[maxn];
int col1[maxn],col0[maxn];

int main()
{
    freopen("in","r",stdin);
    int n,m;
    cin >> n >> m;
    int mp;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            scanf("%d",&mp);
            if (mp==0)
            {
                row0[i]++;
                col0[j]++;
            }
            else 
            {
                row1[i]++;
                col1[j]++;
            }
        }
    }
    long long ans = 0;
    for (int i=0;i<n;i++)
    {
        if (row0[i]!=0)
        {
            ans += pow(2,row0[i]);
            ans--;
        }
        if (row1[i]!=0)
        {
            ans += pow(2,row1[i]);
            ans--;
        }
    }
    for (int i=0;i<m;i++)
    {
        if (col0[i]!=0)
        {
            ans += pow(2,col0[i]);
            ans--;
            ans-=col0[i];
        }
        if (col1[i]!=0)
        {
            ans += pow(2,col1[i]);
            ans--;
            ans-=col1[i];
        }       
    }
    cout << ans;
    return 0;
}
