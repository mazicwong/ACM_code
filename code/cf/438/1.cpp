/*************************************************************************
	> File Name: 1.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月05日 星期四 15时04分18秒
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

int main()
{
    //freopen("in","r",stdin);
    char str[3];
    scanf("%s",str);
    int n;cin>>n;
    map<char,int> left;
    map<char,int> right;
    left.clear();right.clear();
    char sss[3];
    bool flag=false;
    for (int i=0;i<n;i++)
    {
        scanf("%s",sss);
        left[sss[0]]=1;
        right[sss[1]]=1;
        if (sss[0]==str[0] && sss[1]==str[1])
            flag=true;
    }
    if (left[str[1]]==1 && right[str[0]]==1)
        flag=true;
    if (flag)
        cout <<"YES";
    else cout <<"NO";
    
    return 0;
}
