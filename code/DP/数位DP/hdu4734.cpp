#include <bits/stdc++.h>
using namespace std;
//定义F(x)是x每个位的加权和
//给A,B,找到[0,b]有多少f(x)<=f(A)

const int maxn = 1e4+5;
int dp[10][maxn];//dp[pos][target-sum],target-sum初始是f(a),然后不断减掉,看最后是否大于0
int digit[10];
int a,b;
//符合要求的数: 从最高到最低每一个数都要小于等于A
//if前面有小于的,则接下来的不限制

//state: 0=前面都跟a一样 ; 1=前面有比a小的

//f(x)最多不超过1e4
int f(int x)
{
    int ans=0;
    int cnt=0;
    while(x)
    {
        ans += (x%10)*(1<<cnt++);
        x/=10;
    }
    return ans;
}
int target=0;
int dfs(int pos,int sum,bool limit)
{
    if(pos==-1) return sum<=target;
    if(sum>target) return 0;
    if(!limit && dp[pos][target-sum]!=-1) return dp[pos][target-sum];
    int up = limit?digit[pos]:9;
    int res=0;
    for(int i=0;i<=up;i++)
        res += dfs(pos-1,sum+i*(1<<pos),limit&&i==digit[pos]);
    if(!limit) dp[pos][target-sum]=res;
    return res;
}

int solve(int n)
{
    int pos=0;
    while(n)
    {
        digit[pos++]=n%10;
        n/=10;
    }
    return dfs(pos-1,0,true);
}

int main()
{
    int t;cin>>t;
    memset(dp,-1,sizeof(dp));
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&a,&b);
        target=f(a);
        printf("Case #%d: %d\n",cas,solve(b));
    }
    return 0;
}
