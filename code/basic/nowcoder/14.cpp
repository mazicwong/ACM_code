#include <bits/stdc++.h>
using namespace std;

//dp[n][m] = dp[m][m]   (n<m)
//dp[n][m] = dp[n][m-1]+dp[n-m][m]  (n<=m) 有一个空盘，全都满(每个拿走一个)
const int maxn = 15;
int dp[maxn][maxn]; //dp[n][m]: n个苹果放在m个盘子里

int dfs(int n,int m)
{
    if(n==0 || m==1) return 1;
    if(n<m) return dfs(n,n);
    else return dfs(n,m-1)+dfs(n-m,m);
}

int main()
{
    int m,n;
    cin>>n>>m;
    cout << dfs(n,m);
    return 0;
}
