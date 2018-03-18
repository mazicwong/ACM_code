#include <bits/stdc++.h>
using namespace std;
long long tree[101024];
const int maxn = 1e5+5;
int a[maxn];
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> G;
    
    G.push_back(n);
    G.push_back(m);
    for(vector<int>::iterator it=G.begin();it!=G.end();it++)
        cout << *it << endl;

    //G.pop_back();
    for(vector<int>::iterator it=G.begin();it!=G.end();it++)
        cout << *it << endl;

    cout << endl << *G.begin();
    cout << endl << *G.end();

    return 0;
}
