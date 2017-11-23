/*************************************************************************
	> File Name: 1.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月01日 星期五 21时33分04秒
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
const int maxn = 100+5;
int a[maxn];
int main()
{
   // freopen("in","r",stdin);
    int n;cin>>n;
    int sum=0;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }

    if (a[0]%2==0 || a[n-1]%2==0)
    {
        cout << "NO";
        return 0;
    }
    if (n%2==1)
    {
        cout << "YES";
        return 0;
    }
    else 
    {
        cout << "NO";
        return 0;
    }
    
    return 0;
}
