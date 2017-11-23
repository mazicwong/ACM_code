/*************************************************************************
	> File Name: 1.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月15日 星期日 16时06分27秒
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

int a[12];
int b[12];
const int INF = 0x3f3f3f3f;
map<int,int> mp;
int main()
{
    //freopen("in","r",stdin);
    int n,m;cin>>n>>m;
    mp.clear();
    int mina=INF;
    int minb=INF;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        mina = min(mina,a[i]);
        mp[a[i]]++;
    }
    for (int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
        minb=min(minb,b[i]);
        mp[b[i]]++;
    }
    for (int i=1;i<=9;i++)
    {
        if (mp[i]>1)
        {
            cout << i;
            return 0;
        }
    }
    if (mina<minb)
        swap(mina,minb);
    cout << minb << mina;

    
    return 0;
}
