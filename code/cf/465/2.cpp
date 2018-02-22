//2.cpp
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    //freopen("in","r",stdin);
    int n;cin>>n;
    string str;cin>>str;
    int ans=0;
    bool pre=1;
    bool now=1;
    if (str[0]=='U') pre=1;
    else pre=0;
    bool flag=0;
    int res=0;
    for (int i=0;i<str.size();i++)
    {
        if(str[i]=='U')
        {
            ans++;
            now = ans>0?1:0;
            if(now==1 && pre==0 && flag)
            {
                res++;
            }
        }
        else
        {
            ans--;
            now = ans<0?0:1;
            if (now==0 && pre==1 && flag)
            {
                res++;
            }
        }
        if (ans==0) flag=1;
        else
        {
            flag=0;
            pre = ans>0?1:0;
        }
    }
    cout << res;
    
    return 0;
}
