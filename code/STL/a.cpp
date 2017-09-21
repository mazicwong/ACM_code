/*************************************************************************
	> File Name: a.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月21日 星期四 02时02分09秒
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
int list[3]={0,1,2};
template<class type>
void perm(type list[],int k,int m)
{
    if (k==m)
    {
        for (int i=0;i<=m;i++) cout<<list[i];
        cout << endl;
    }
    else
    {
        for (int i=k;i<=m;i++)
        {
            swap(list[k],list[i]);
            perm(list,k+1,m);
            swap(list[k],list[i]);
        }
    }
}
int main()
{
    freopen("in","r",stdin);
    perm(list,0,2);
    
    return 0;
}
