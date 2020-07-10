/*************************************************************************
	> File Name: poj3616.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月04日 星期三 09时18分30秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;

/*
 * poj3616.cpp
 * 共n个小时,其中有m段时间,每段时间配一个效率表示该时间能够收货的牛奶数
 * 每次收集牛奶后牛要休息r个小时,问最多能收集多少牛奶
 *
 * 这里m=1000,如果m足够小可以直接压缩状态
 *
 * 状态 dp[i]: 第i个时间段挤奶时收获最大是多少
 * 边界 dp[i]=tt[i].num
 * 转移 dp[i] = max(dp[i-1],dp[j]+tt[j].num)   其中j=[0..i),且tt[j].end<=tt[i].start;
 *
 * 最终,答案应该是max(dp[i])  其中i=[1..m],因为不知道哪一次是最后
 */

const int maxn = 1e6+5;
const int maxm = 1000+5;
int dp[maxm]; //第i个时间段挤奶时收获最大是多少
struct node{
    int start,end;
    int num;
    bool operator < (const node& i) const{
        return start<i.start;
    }
}tt[maxm];

bool cmp(struct node a,struct node b)
{
    if (a.start==b.start)
        return a.end<b.end;
    return a.start<b.start;
}

int main()
{
    freopen("in","r",stdin);
    int n,m,r;
    cin>>n>>m>>r;
    for (int i=0;i<m;i++)
    {
        scanf("%d%d%d",&tt[i].start,&tt[i].end,&tt[i].num);
        //dp[i] = tt[i].num; 不能在这,dp要存排序后的
    }
    sort(tt,tt+m);
    for (int i=0;i<m;i++)
    {
        dp[i]=tt[i].num;
        for (int j=0;j<i;j++)
        {
            if (tt[j].end+r <= tt[i].start)
            {
                dp[i] = max(dp[i], dp[j]+tt[i].num);
            }
        }
    }
    //cout << *max_element(dp,dp+m) << endl;
    int ans = 0; 
    for (int i=0;i<m;i++)
        ans = max(ans,dp[i]);
    cout << ans;
    return 0;
}
