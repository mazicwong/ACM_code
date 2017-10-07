/*************************************************************************
	> File Name: 1.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月29日 星期五 14时10分30秒
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

const int maxn = 105;
int a[maxn];
int main()
{
    //freopen("in","r",stdin);
    int n;cin>>n;
    set<int> st;st.clear();
    multiset<int> sst;sst.clear();
    int a;
    if (n&1)
    {
        cout << "NO";
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        st.insert(a);
        sst.insert(a);
    }
    if (st.size()!=2)
        cout << "NO";
    else
    {
        set<int>::iterator it = st.begin();
        if (sst.count(*it)!=n/2)
        {
            cout << "NO";
            return 0;
        }
        cout << "YES" << endl;
        for (;it!=st.end();it++)
        {
            cout << *it;
            if (it==st.begin())
                cout << ' ';
        }
    }
    return 0;
}
