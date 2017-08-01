/*************************************************************************
	> File Name: 1.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年07月31日 星期一 22时31分58秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
int main()
{
    freopen("in","r",stdin);
    int s,v1,v2,t1,t2;
    scanf("%d%d%d%d%d",&s,&v1,&v2,&t1,&t2);
    int a=s*v1+2*t1;
    int b=s*v2+2*t2;
    if (a<b)
        printf("First");
    else if (a>b)
        printf("Second");
    else printf("Friendship");

    
    
    return 0;
}
