/*************************************************************************
	> File Name: 8.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月22日 星期二 12时15分01秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;
/*
 * 题意:
 * 对于数列a[]和b[],其中a[]是由b[i]+b[j]组成的,
 * 现给出数列a[],请求出数列b[]
 *
 * 思路:
 * 将a[]排序后,每次取出最小的1个数存入ans[],然后将ans[]中已有的数加上这个数所得到的从a[]中删除
 * 由于a[]要不断进行删除且a[]中有重复,所以采用multiset
 *
 *
 * *st.begin()              //取最小的数
 * st.find(a)               //找一个数
 * st.erase(st.find(a))     //删除数a
 */

const int maxn = 125250+5;
multiset<int> st;
vector<int>vec;
int main()
{
    freopen("in","r",stdin);
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        st.clear();
        vec.clear();
        int a;
        for (int i=0;i<m;i++)
        {
            scanf("%d",&a);
            st.insert(a);
        }
        int n = (sqrt(8*m+1+0.5)-1)/2;

        while(!st.empty())
        {
            int a = *st.begin();
            st.erase(st.find(a));
            for (int i=0;i<vec.size();i++)
                st.erase(st.find(vec[i]+a));

            vec.push_back(a);
        }

        //cout << vec.size() << endl;
        printf("%d\n",vec.size());
        for (int i=0;i<n;i++)
            printf(i==n-1?"%d\n":"%d ",vec[i]);
    }
    
    return 0;
}

