/*************************************************************************
	> File Name: 2.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月12日 星期六 22时45分01秒
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
    for (int i=0;i<k;i++)
        scanf("%d",&a[i]);
    int s4=n;
    int s2=2*n;

    for (int i=0;i<k;i++) //先塞4人的
    {
        int tt=min(a[i]/4,s4); //塞多少行
        s4-=tt;
        a[i]-=(4*tt);
    }

    s2+=s4; //所有2人的先坐下,所有4人的先坐2个,可以合起来写
    for (int i=0;i<k;i++) //再塞2人的
    {
        int tt=min(a[i]/2,s2);
        s2-=tt;
        a[i]-=(2*tt);
    }
    int cnt = s2+s4; //如果刚才是3人,则4人位0111,如果是2人,拼桌,则1011
    for (int i=0;i<k;i++)
        cnt-=a[i];

    if (cnt>=0) printf("YES");
    else printf("NO");
    return 0;
}
