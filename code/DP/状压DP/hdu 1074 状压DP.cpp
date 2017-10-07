/*************************************************************************
	> File Name: hdu1074.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月02日 星期三 11时19分20秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 15;
int n;
struct node{
    string str;
    int dead;//deadline
    int cost;//time to finish the work
}mm[maxn];

struct kode{
    int time;//时间
    int score;//损失分数
    int pre;//前一个状态
    int now;
}dp[1<<maxn];//i状态下包含的信息  (输出dp[(1<<n)-1].score)

int main()
{
    freopen("in","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            cin >> mm[i].str >> mm[i].dead >> mm[i].cost;
        int bit=1<<n;
        for (int st=1;st<bit;st++)//所有状态
        {
            dp[st].score=INF;
            for (int i=n-1;i>=0;i--)//所有作业
            {
                if (st & (1<<i))//i位已完成
                {
                    int past = st&(~(1<<i));//i位置0
                    int st_now = dp[past].time+mm[i].cost-mm[i].dead;//这次超时多少
                    if (st_now<0) st_now=0;//这次不超
                    if (st_now+dp[past].score < dp[st].score)
                    {
                        dp[st].score = dp[past].score+st_now;
                        dp[st].now = i;
                        dp[st].pre = past;
                        dp[st].time = dp[past].time+mm[i].cost;
                    }
                }
            }
        }
        stack<int> S;
        int tmp = (1<<n)-1;
        cout << dp[tmp].score << endl;
        while(tmp)
        {
            S.push(dp[tmp].now);
            tmp = dp[tmp].pre;
        }
        while(!S.empty())
        {
            cout << mm[S.top()].str << endl;
            S.pop();
        }
    }
    return 0;
}
