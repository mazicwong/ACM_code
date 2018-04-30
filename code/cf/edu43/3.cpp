#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+5;
int l[maxn];
int r[maxn];
struct Node{
    int l,r;
    int idx;
    bool operator<(const Node & rhs){

        if(l == rhs.l) return r>rhs.r;
        else return l<rhs.l;
    }
}node[maxn];
int main()
{
    int n; cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d%d",&node[i].l,&node[i].r);
        node[i].idx=i+1;
        //scanf("%d%d",&l[i],&r[i]);
    }
    sort(node,node+n);
    int nowr=node[0].r;
    for(int i=1;i<n;i++)
    {
        if(node[i].l>=node[i-1].l && node[i].r<=node[i-1].r){
            cout << node[i].idx << " " << node[i-1].idx;
            return 0;
        }

        //cout << node[i].l << ' ' << node[i].r<<endl;
    }
    cout << "-1 -1";
    return 0;
}
