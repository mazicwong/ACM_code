/*************************************************************************
	> File Name: hdu1029_.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月24日 星期一 09时49分06秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    freopen("in","r",stdin);
    int n;
    int tmp;
    int cnt=0;
    int ans=0;
    while(scanf("%d",&n)!=EOF)
    {
        cnt=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            if (cnt==0)
                ans=tmp,cnt=1;
            else
            {
                if (ans==tmp) cnt++;
                else cnt--;
            }
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
