/*************************************************************************
	> File Name: a.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月25日 星期五 00时36分13秒
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
const int maxn = 1000+5;
char str[maxn];
map<char,int> mp;
int main()
{
    freopen("in","r",stdin);
    int k;
    scanf("%s",str);
    cin >> k;
    int len = strlen(str);
    for (int i=0;i<len;i++)
    {
        mp[str[i]]++;
    }
    int cnt = 0;
    int num=0;
    for (char i='a';i<='z';i++)
    {
        if (mp[i]>0)
            cnt++;
    }
    if (len<k)
    {
        cout << "impossible" << endl;
        return 0;
    }
    if (cnt>=k)
    {
        cout << "0" << endl;
        return 0;
    }
    cout << k-cnt << endl;

    
    return 0;
}
