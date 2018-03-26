/*************************************************************************
	> File Name: 1.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月01日 星期日 01时04分47秒
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
char str[105];
int n;
int main()
{
    scanf("%d%*c",&n);
    int ans1=0;
    int ans2=0;
    char pre;
    char now;
    for (int i=0;i<n;i++)
    {
        scanf("%c",&now);
        if (i==0)
        {
            pre=now;
            continue;
        }
        if (pre!=now)
        {
            if (now=='F')
                ans1++;
            else ans2++;
        }

        pre = now;
    }
    if (ans1>ans2)
        cout << "YES";
    else cout << "NO";

    
    return 0;
}
