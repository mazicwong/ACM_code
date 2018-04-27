#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000;
int t[maxn];
int p[maxn];
int f[maxn]; //f[i]: 当前第i个信息下来的最简单

int main()
{
    int n,m;
    
    while(cin>>n>>m) //n个T, m
    {
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&t[i],&p[i]);
        }
    }

    return 0;
}
