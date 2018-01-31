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
#include <cmath>
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
        for (int j=0;j<m;j++)
        {
            if (j+k-1>=m) break;
            int kk=j;
            for (kk=j;kk<=j+k-1;kk++)
            {
                if (mp[i][kk]=='.')
                    continue;
                else break;
            }
            if (kk==j+k) ans++;
        }
    }
    for (int j=0;j<m;j++)
    {
        for (int i=0;i<n;i++)
        {
            if (i+k-1>=n) break;
            int kk=i;
            for (kk=i;kk<=i+k-1;kk++)
            {
                if (mp[kk][j]=='.')
                    continue;
                else break;
            }
            if (kk==i+k) ans++;
        }
    }
    printf("%d",ans);
    return 0;
}
