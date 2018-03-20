#include <bits/stdc++.h>
using namespace std;
//找一个最短的串,使得给定n个串都是他的子串

//只有15个串,尝试状压,2^15种状态

const int maxn = 17;
int dp[1<<maxn][maxn]; //dp[st][i]: 包含st集合,且最前面字符串是i时的最小长
int cost[maxn][maxn];  //cost[i][j]: j串前放i串需要加多少
string str[maxn];
string ans;
void 

int main()
{
    int t;cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        int n;cin>>n;
        cout << "Scenario #" << cas++ << ":\n";
        for(int i=0;i<n;i++) cin>>str[i];
        if(n==1) {cout<<str[0]; continue;}
        init();

        for(int i=0;i<n;i++)
            dp[1<<i][i] = str[i].size();

        for(int st=0;st<(1<<n);st++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[st][j]!=INF)

            }
        }

    }

    return 0;
}
