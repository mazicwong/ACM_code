//1007.cpp
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;

/*
 * 按字符串的逆序数从小到大输出
 */

struct Node{
    string str;
    int oppo;
}node[105];

bool cmp(Node a, Node b)
{
    return a.oppo<b.oppo;
}

int ni(string str, int m)
{
    int cnt = 0;
    for (int i=0;i<m;i++)
    {
        for (int j=i+1;j<m;j++)
        {
            if (str[i]>str[j])
                cnt++;
        }
    }
    return cnt;
}


int main()
{
    //freopen("in","r",stdin);
    ios::sync_with_stdio(false);
    int m,n; cin>>m>>n;
    string str;
    for (int i=0;i<n;i++)
    {
        cin>>str;
        node[i].str = str;
        node[i].oppo = ni(str, m);
    }
    sort(node, node+n, cmp);
    for (int i=0;i<n;i++)
    {
        cout << node[i].str << endl;
    }
    return 0;
}
