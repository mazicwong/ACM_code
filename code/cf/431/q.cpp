/*************************************************************************
	> File Name: q.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月01日 星期五 22时16分30秒
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

#define INF 0x3f3f3f3f
const double PI=acos(-1.0);
using namespace std;
const int maxn=1e3+10;
int a[maxn];
int p[maxn];
map<int,int>mp;
int main()
{
    freopen("in","r",stdin);
    int N;
    int ans;
    while(~scanf("%d",&N))
    {
        ans=0;
        for(int i=0;i<N;i++)
        {
            scanf("%d",a+i);
            if(i==0)
                continue;
            else
                p[i]=a[i]-a[i-1];
        }
        for(int i=1;i<N;i++)
        {
            if(mp[p[i]]==0)
                ans++;
            mp[p[i]]++;
        }
        //cout<<ans<<endl;
        if(ans==2)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        mp.clear();
    }
    return 0;
}
