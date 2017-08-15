/*************************************************************************
	> File Name: b1.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月31日 星期一 10时31分28秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    freopen("in","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    string str;
    cin >> str;
    vector<int> sum(n+100,0), l(30,1e9), r(30,-1e9);
    for (int i=0;i<str.size();i++)
    {
        l[str[i]-'A'] = min(l[str[i]-'A'], i);
        r[str[i]-'A'] = max(r[str[i]-'A'], i);
    }
    for (int i=0;i<26;i++)
        if (l[i]!=1e9 && r[i]!=-1e9)
            sum[l[i]]++,sum[r[i]+1]--;
    for (int i=1;i<str.size();i++)
        sum[i]+=sum[i-1];
    int flag = *max_element(sum.begin(), sum.end());
    puts(flag>k? "YES":"NO");
    return 0;
}
