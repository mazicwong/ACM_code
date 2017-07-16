/*************************************************************************
	> File Name: hdu1160 DP类似最长上升自序列.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年06月14日 星期三 00时15分25秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
//http://www.cnblogs.com/Penn000/p/6665217.html
/* size and speed
 * size -> increase
 * speed -> decrease
 *
 * 先排序，然后是一个最长下降自序列，中间需记录顺序
 * dp[i]=max(dp[i],dp[j]+1);
 */

const int maxn = 1000+5;
struct mazic{
    int cur;//输入时的下标
    int w;//increase
    int s;//decrease
}mm[1000+5];

int dp[maxn];//到第i个数,最长单调递增子序列的长度
int path[maxn];//第i个数的上一个数
int res[maxn];//存结果序号
bool cmp(mazic a,mazic b)
{
    if (a.s==b.s)
        return a.w<b.w;
    else return a.s>b.s;
}

int main()
{
    int cnt = 1;
    while(cin>>mm[cnt].w>>mm[cnt].s)
    {
        mm[cnt].cur = cnt;
        cnt++;
    }
    sort(mm+1,mm+cnt+1,cmp);
    




    return 0;
}
