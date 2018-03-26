//1.cpp
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    while(cin>>n>>m)
    {
        set<int,less<int> > st;
        int a;
        for (int i=0;i<n+m;i++)
        {
            cin>>a; //scanf("%d",&a);
            st.insert(a);
        }


        bool flag=true;
        for (set<int,less<int> >::iterator it = st.begin();it!=st.end();it++)
        {
            if (flag) flag=false,cout<<*it;
            else cout << ' ' << *it;
        }
        cout << endl;
    }

    return 0;
}
