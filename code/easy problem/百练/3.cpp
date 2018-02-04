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
#include <time.h>
using namespace std;

const int maxn = 105;
int grid[maxn][maxn];

int area=0;
int cc=0;

int main()
{
    //freopen("in","r",stdin);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>grid[i][j];


    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (grid[i][j]<=50)
            {
                area++;
                if (i==1 || i==n || j==1 || j==n) cc++;
                else if (grid[i+1][j]>50 || grid[i-1][j]>50 || grid[i][j-1]>50 || grid[i][j+1]>50) cc++;
            }
        }
    }
    cout << area << ' ' << cc;
    return 0;
}
