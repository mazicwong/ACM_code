/*************************************************************************
	> File Name: a.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月30日 星期日 22时36分21秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
map<char,int>mp;
int n;
int main()
{
    freopen("in","r",stdin);
    mp['v']=0;
    mp['<']=1;
    mp['^']=2;
    mp['>']=3;
    char a,b;
    scanf("%c%*c%c",&a,&b);
    scanf("%d",&n);
    n%=4;
    int tt = (mp[a]+n)%4;
    int qq = (mp[a]+4-n)%4;
    if (qq==mp[b] && tt==mp[b])
        printf("undefined");
    else if (tt==mp[b])
        printf("cw");
    else
        printf("ccw");

    return 0;
}
