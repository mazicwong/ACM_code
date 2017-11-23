/*************************************************************************
	> File Name: 22.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月01日 星期五 22时27分01秒
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
const int maxn = 1000+5;
int a[maxn];
int del[maxn];


map<int,int> mp;
set<int> st;

int get(int a,int b,int c)
{
    for (int i=2;i<=n;i++)
    {
        mpp[del[i]]++;
    }
}

int main()
{
    freopen("in","r",stdin);
    int n;cin>>n;
    scanf("%d",&a[1]);
    mp.clear();st.clear();
    for (int i=2;i<=n;i++)
    {
        scanf("%d",&a[i]);
        del[i]=a[i]-a[i-1];//del[2..n]
        mp[del[i]]++;
        st.insert(del[i]);
    }
    
    int cnt = st.size();
    if (cnt==2)
    {
        cout << "Yes";
        return 0;
    }
    if (cnt==3)
    {
        /*
        for (set<int>::iterator it=st.begin();it!=st.end();it++)
        {
            cout << *it << "  ";
        }*/

        int a1=0,a2=0,a3=0;
        for (int i=2;i<=n;i++)
        {
            
        }

        cout << "Yes";
        return 0;
    }
    cout << "No";
    

    return 0;
}
