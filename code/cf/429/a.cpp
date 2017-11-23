/*************************************************************************
	> File Name: a.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月18日 星期五 23时01分48秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 100+5;
char str[maxn];
map<char,int> mp;

int main()
{
    freopen("in","r",stdin);
    int n,k;
    mp.clear();
    cin >> n >> k;
    scanf("%s",str);
    for (int i=0;i<n;i++)
    {
        mp[str[i]]++;
    }
    int ans = 0;
    for (char i='a';i<='z';i++)
    {
        ans = max(ans,mp[i]);
    }
    if (ans > k)
        cout<<"NO";
    else cout<<"YES";
    
    return 0;
}
