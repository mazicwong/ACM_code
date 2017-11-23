/*************************************************************************
	> File Name: b.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月18日 星期五 23时23分20秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1e6+5;
typedef long long ll;
int main()
{
    freopen("in","r",stdin);
    int n;
    int a;
    cin >> n;
    ll sum = 0;
    int odd=0;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a);
        sum+=a;
        if (a%2==1)
            odd=1;
    }
    if (sum%2==1)
        printf("First");
    else if (sum%2==0)
    {
        if (odd==1)
        {
            printf("First");
        }
        else printf("Second");
    }
    
    return 0;
}
