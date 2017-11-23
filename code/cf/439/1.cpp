/*************************************************************************
	> File Name: 1.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月06日 星期五 21时34分56秒
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
const int maxn = 2000+5;
int x[maxn],y[maxn];
bool vis[maxn];
//map<int,int> mp;
int main()
{
    //freopen("in","r",stdin);
    int n;cin>>n;
    //mp.clear();
    for (int i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
        vis[x[i]]=1;
        //mp[x[i]]++;
    }
    for (int i=0;i<n;i++)
    {
        scanf("%d",&y[i]);
        vis[y[i]]=1;
        //mp[y[i]]++;
    }
    int cnt=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (vis[x[i]^y[j]])
            {
                cnt++;
            }
        }
    }
    if (cnt%2==0)
        cout << "Karen";
    else cout << "Koyomi";
    return 0;
}
