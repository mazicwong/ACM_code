/*************************************************************************
	> File Name: 1.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月28日 星期一 18时39分46秒
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
char a[105];
int main()
{
    freopen("in","r",stdin);
    int n,k;
    cin >> n >> k;
    getchar();
    int st,en;
    for (int i=0;i<n;i++)
    {
        scanf("%c",&a[i]);
        if (a[i]=='G')
            st=i;
        if (a[i]=='T')
            en=i;
    }
    if (st>en)
        swap(st,en);
   // cout << st << "  " << en << endl;
    int i=0;
    for (i=st+k;i<=en;i+=k)
    {
        if (a[i]=='G' || a[i]=='T')
        {
            cout <<"YES";
            return 0;
        }
        if (a[i]=='#')
        {
            cout << "NO";
            return 0;
        }
    }
    if (i!=en) cout <<"NO";
    else cout << "YES";
    
    return 0;
}
