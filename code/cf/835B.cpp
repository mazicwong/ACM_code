/*************************************************************************
	> File Name: 2.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月31日 星期一 22时32分33秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
map<int,int> mp;
int main()
{
    freopen("in","r",stdin);
    int k;
    string str;
    cin >> k >> str;
    mp.clear();
    for (int i=0;i<10;i++)
        mp[i]=0;
    for (int i=0;i<str.size();i++)
    {
        mp[str[i]-'0']++;
    }
    int cnt=0;
    for (int i=0;i<10;i++)
    {
        if (mp[i])
        {
            cnt += mp[i]*i;
        }
    }
    int ans=0;
    if (cnt >= k)
    {
        printf("0");
        return 0;
    }
    int i=0;
    cnt = k-cnt;
    while(cnt>0)
    {
        if (mp[i]*(9-i) >= cnt)
        {
            ans += (cnt/(9-i));
            if (cnt%(9-i)!=0)
                ans++;
            break;
        }
        else
        {
            cnt -= (mp[i]*(9-i));
            ans += mp[i];
        }
        i++;
    }
    printf("%d",ans);

    return 0;
}
