#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
//给一个2e9以内的区间,问有多少个数满足,二进制下0的个数大于等于1的个数

//dp[pos][num]: 到pos时,0-1不少于num的方案数,由于num可能有负数且是正确的(因为没到最终状态),所以做一个简单加法的哈希就好了
//9个数,最多0-1等于9,2e9二进制下最多30多个位
//注意1:这题有前导0限制

const int maxn = 2e9+5;
int dp[35][66];//pos,0的个数减去1的个数
int digit[66];
int hash(int x) {return x+32;}
int dfs(int pos,int state,bool lead,bool limit)
{
    if(pos==-1) return state>=32;
    if(!limit && !lead && dp[pos][state]!=-1) return dp[pos][state];
    int up=limit?digit[pos]:1;
    int res=0;
    for (int i=0;i<=up;i++)
    {
        if(lead && i==0) res+=dfs(pos-1,state,lead,limit&&i==digit[pos]);
        else res+=dfs(pos-1,state+(i==0?1:-1),lead&&i==0,limit&&i==digit[pos]);
    }
    if(!limit && !lead) dp[pos][state]=res;
    return res;
}

int solve(int n)
{
    int pos=0;
    while(n)
    {
        digit[pos++]=n%2;
        n>>=1;
    }
    return dfs(pos-1,32,true,true);
}
int main()
{
    int l,r;cin>>l>>r;
    memset(dp,-1,sizeof(dp));
    printf("%d",solve(r)-solve(l-1));
    return 0;
}
