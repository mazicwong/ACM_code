/*************************************************************************
	> File Name: cf873b.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月19日 星期四 22时54分42秒
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
 * 问一个字符串的最长子串,字符串只由0/1组成
 * 子串要求,0和1的个数相同
 */

map<int,int> mp;
int main()
{
    //freopen("in","r",stdin);
    int n;cin>>n;
    int a;
    int cur=0;
    for (int i=0;i<n;i++)
    {
        cin>>a;
        if (a==1) cur++;
        else cur--;

        if (mp.count(cur))
            ans = max(ans, i-mp[cur]);
        else mp[cur] = i;
    }
    cout << ans << endl;
    return 0;
}
