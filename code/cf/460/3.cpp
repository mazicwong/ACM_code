//3.cpp
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cstdlib>
using namespace std;
const int maxn = 2010;

char mp[maxn][maxn];
int main()
{
    int n,m,k;
    scanf("%d%d%d%*c",&n,&m,&k);
    int xingxing=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            scanf("%c",&mp[i][j]);
            if (mp[i][j]=='.')
                xingxing++;
        }
        getchar();
    }
    if (k==1)
    {
        cout << xingxing;
        return 0;
    }

    int ans = 0;
    for (int i=0;i<n;i++)
    {
        int cnt = 0;
        for (int j=0;j<m;j++)
        {
            if (mp[i][j]=='.') cnt++;
            else cnt=0;
            if (cnt>=k) ans++;
        }
    }
    for (int j=0;j<m;j++)
    {
        int cnt = 0;
        for (int i=0;i<n;i++)
        {
            if (mp[i][j]=='.') cnt++;
            else cnt=0;
            if (cnt>=k) ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
