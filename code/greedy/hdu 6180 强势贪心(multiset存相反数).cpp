/*************************************************************************
	> File Name: 10.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月24日 星期四 14时44分12秒
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

const int maxn=1e5+5;
struct Task
{
	int s,e;
	bool operator <(const Task &in)const
	{
		return s<in.s;
	}
}t[maxn];
multiset<int> st;
int n;
long long ans;
int main()
{
    freopen("in10","r",stdin);
    int T;cin>>T;
	while(T--)
	{
		st.clear();
		ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
            scanf("%d%d",&t[i].s,&t[i].e);

		sort(t,t+n);
		multiset<int>::iterator tmp;
		for(int i=0;i<n;i++)
		{
			tmp = st.lower_bound(-t[i].s);
			if(tmp==st.end())//找不到可以续的
			{
				st.insert(-(t[i].e));
				ans+=t[i].e-t[i].s;
			}
			else//找到可以续的
			{
				st.insert(-(t[i].e));
				ans+=t[i].e-(-(*tmp));
				st.erase(tmp);
			}
		}
		cout<<st.size()<<" "<<ans<<endl; 
	}
} 
