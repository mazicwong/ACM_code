#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+5;
ll hp[maxn],dmg[maxn];
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct Node{
    ll hp,dmg;
    ll del;
    ll ddd;
}node[maxn];
struct Reser{
    ll hp,dmg;
    ll del;
    ll ddd;
}reser[maxn];
bool cmp(const Node a,const Node b){
    return a.del > b.del;
}
bool cmp1(const Node a,const Node b)
{
    return a.ddd > b.ddd;
}
int main()
{
    ll n,a,b; cin>>n>>a>>b;
    ll sum=0;
    ll tmp=a,power=1; while(tmp--)power*=1LL*2;
    //cout << power << endl;
    for(int i=0;i<n;i++)
    {
        node[i].hp=read(); node[i].dmg=read();
        sum += node[i].dmg;
        node[i].del = node[i].hp*power - node[i].dmg;
        node[i].ddd = node[i].hp - node[i].dmg;
    }
    if(b==0){
        cout << sum;
    }
    else if(a==0){
        sort(node,node+n,cmp1);
        for(int i=0;i<b;i++){
            node[i].dmg = max(node[i].dmg,node[i].hp);
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            ans += node[i].dmg;
        }
        cout << ans;
    }
    else if(a==1){
        sort(node,node+n,cmp);
        //node[0].dmg = node[0].hp*power;
        node[0].hp = node[0].hp*power;
        node[0].ddd = node[0].hp-node[0].dmg;
        sort(node,node+n,cmp1);
        for(int i=0;i<b;i++)
        {
            node[i].dmg = max(node[i].dmg,node[i].hp);
        }
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ans += node[i].dmg;
        }
        cout << ans;
    }
    else{
        for(int i=0;i<n;i++)
        {
            reser[i].hp = node[i].hp;
            reser[i].dmg = node[i].dmg;
            reser[i].del = node[i].del;
            reser[i].ddd = node[i].ddd;
        }
        sort(node,node+n,cmp);
        ll ans=0;
        for(int i=0;i<a*1000,i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                node[j].hp = reser[j].hp;
                node[j].dmg = reser[j].dmg;
                node[j].del = reser[j].del;
                node[j].ddd = reser[j].ddd;
            }
            node[i].hp = node[i].hp*power;
            node[i].ddd = node[i].hp-node[i].dmg;
            sort(node,node+n,cmp1);
            for(int i=0;i<b;i++){
                node[i].dmg = max(node[i].dmg,node[i].hp);
            }
            ll res=0;
            for(int i=0;i<n;i++) res+=node[i].dmg;
            ans = max(ans,res);
        }
        cout<<ans;
    }
    return 0;
}
