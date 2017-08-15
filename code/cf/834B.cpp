/*************************************************************************
	> File Name: b.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月30日 星期日 22时55分27秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 1e6+5;
int n,k;
map<char,int>mp;
map<char,int>mpp;
int main()
{
    freopen("in","r",stdin);
    mp.clear();
    scanf("%d%d%*c",&n,&k);
    char str[maxn];
    int flag[maxn];
    memset(flag,0,sizeof(flag));
    scanf("%s",str);
    
    for (int i=0;i<n;i++)
    {
        if (!mp[str[i]])
        {
            flag[i]++;
            mp[str[i]]=1;
        }
    }
    mp.clear();
    mpp.clear();
    for (int i=n-1;i>=0;i--)
    {
        if(!mp[str[i]])
        {
            flag[i]--;
            mp[str[i]]=1;
        }
        mpp[str[i]]++;
    }
    int cnt=0;
    bool mmm=true;
    for (int i=0;i<n;i++)
    {
        cnt+=flag[i];
        if(cnt+(mpp[str[i]]==1) > k)
        {
            mmm=false;
            break;
        }
    }
    if (mmm)
        printf("NO");
    else printf("YES");

    return 0;
}
