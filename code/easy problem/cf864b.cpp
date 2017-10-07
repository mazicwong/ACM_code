/*************************************************************************
	> File Name: 2.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月29日 星期五 14时18分47秒
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
char str[205];
int main()
{
    //freopen("in","r",stdin);
    int n;cin>>n;
    scanf("%s",str);
    map<char,int> mp;
    mp.clear();

    int cnt=0;
    int cur = 0;
    int maxans=0;
    while(cur<n)
    {
        if (isupper(str[cur]))
        {
            mp.clear();
            cnt=0;
            cur++;
            continue;
        }
        if (mp[str[cur]])
        {
            cur++;
            continue;
        }
        mp[str[cur]]=1;
        cnt++;
        maxans=max(maxans,cnt);
        cur++;
    }
    cout << maxans;

    return 0;
}
