/*************************************************************************
	> File Name: 5.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月01日 星期日 10时33分23秒
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
const int maxn = 3e5+5;
/*
 * priority_queue && multiset
 * 这两个大部分功能是重复的,而且都已经排好序,
 * 区别:队列是线性的,集合可以从中间进行处理(一般用于查询)
 */

typedef long long ll;
priority_queue<int,vector<int>,greater<int> > pque;
multiset<int> st;

int main()
{
    freopen("in5","r",stdin);
    int n;cin>>n;
    ll ans=0;
    for (int i=0;i<n;i++)
    {
        ll x; cin>>x;
        if (!pque.empty() && pque.top()<x)
        {
            ans += (ll)(x-pque.top());
            pque.pop();
            pque.push(x);
            pque.push(x);
        }
        else
        {
            pque.push(x);
        }
        /*
        //法2 multiset
        if (!st.empty() && *st.begin()<x)
        {
            ans += (ll)(x-*st.begin());
            st.erase(st.begin());
            st.insert(x);
            st.insert(x);
        }
        else 
        {
            st.insert(x);
        }*/
    }
    cout << ans;
    return 0;
}
