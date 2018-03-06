#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int maxn = 1e3+5;
//dp[pos][sta]: 第pos位,状态为sta时满足的个数
int dp[maxn][17];
//state: 1111 (压位)
ll dfs(int pos,int state,bool lead,bool limit)
{
    if(pos==-1)
    {
        if(state==15 && !lead) return 1;
        else return 0;
    }
    if(!limit && dp[pos][state]!=-1) return dp[pos][state];
    ll res=0;
    //0-1  2-3
    for(int i=0;i<=3;i++)
    {
        if(i==0 && lead) continue;
        if((state&2) && i==0) continue; //有过1,不能再放0
        if((state&8) && i==2) continue; //有过3,不能再放2
        //对一个数字,其实状态还是从左往右更新的

        int next_state = state|(1<<i);
        res += dfs(pos-1,next_state,lead&&i==0,limit&&i==3);
        res%=mod;
    }
    if(!limit) dp[pos][state]=res;
    return res;
}

int main()
{
    int n;cin>>n;
    memset(dp,-1,sizeof(dp));
    printf("%lld",dfs(n-1,0,true,true)%mod);
    return 0;
}
 
