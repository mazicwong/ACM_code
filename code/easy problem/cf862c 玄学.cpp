/*************************************************************************
	> File Name: 3.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年09月19日 星期二 23时59分01秒
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
const int maxn = 1e5+5;

int main()
{
    freopen("in","r",stdin);
    int n,num;
    cin>>n>>num;
    
    if (n==1)
        printf("YES\n%d",num);
    else if (n==2)
    {
        if (num==0) printf("NO");
        else printf("YES\n0 %d",num);
    }
    else 
    {
        vector<int> vec;
        vec.push_back(1<<17);
        vec.push_back(1<<18);
        for (int i=0;i<n-3;i++)
            vec.push_back(i);

        int ans = 0;
        for (int i=0;i<vec.size();i++)
            ans^=vec[i];
        vec.push_back(ans^num);
        sort(vec.begin(),vec.end());
        printf("YES\n");
        for (int i=0;i<vec.size();i++)
            printf("%d ",vec[i]);
    }
    cout << (1<<17) << endl;
    cout << pow(2,17) << endl;
    return 0;
}
