#include <bits/stdc++.h>
using namespace std;

const int maxn = 200+5;
int p[maxn];
map<int,int> mp;

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        mp[p[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(mp[p[i]] == 1)
            cout << "BeiJu" << endl;
        else cout << mp[p[i]]-1 << endl;
    }
    return 0;
}
