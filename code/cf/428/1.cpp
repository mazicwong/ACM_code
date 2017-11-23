/*************************************************************************
	> File Name: 1.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月12日 星期六 22时33分52秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 100+5;
int a[maxn];
int main()
{
    freopen("in","r",stdin);
    int n,k;
    cin >> n >> k;
    int save=0;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    int ans = 0;
    int i =0;
    for (i=0;i<n;i++)
    {
        if (ans>=k)
            break;
        if (a[i]>=8)
        {
            save=save+(a[i]-8);
            ans+=8;
        }
        else 
        {
            if (a[i]+save>=8)
            {
                ans+=8;
                save=save-(8-a[i]);
            }
            else
            {
                ans+=(a[i]+save);
                save=0;
            }
        }
    }
    if (ans>=k)
        cout << i;
    else cout << "-1";
    return 0;
}
