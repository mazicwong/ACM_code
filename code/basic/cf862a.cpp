/*************************************************************************
	> File Name: 1.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月19日 星期二 23时26分21秒
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

int a[105];
int main()
{
    //freopen("in","r",stdin);
	int n;
	int x;
    cin>>n>>x;
	for(int i=0;i<n;i++)
	{
        scanf("%d",&a[i]);
	} 
	sort(a,a+n);
	int num=0;int num2=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<x)
			++num;
		if(a[i]==x)
			++num2;
		
	}
	printf("%d\n",x-num+num2);
	return 0;
}
