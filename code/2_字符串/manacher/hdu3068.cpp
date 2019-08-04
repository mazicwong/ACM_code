/*************************************************************************
	> File Name: hdu3068.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月12日 星期六 10时57分41秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 110000+5;
char s[maxn];
int main()
{
    freopen("in","r",stdin);
    while(scanf("%s",s)!=EOF)
    {
        int n =strlen(s);
        int ans=0;
        for (int mid=0;mid<n;mid++)
        {
            int tt = 0;
            int tmp=1;
            while(mid-tt>=0 && mid+tt<n)
            {
                tt++;
                if(s[mid-tt]==s[mid+tt])
                {
                    tmp++;
                }
                else break;
            }
            ans = max(ans,tmp);
        }
        cout << ans << endl;
    }
    return 0;
}
