#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[30]={
    258055, 69760, 163908, 249856, 53440,
    151684, 77958, 176134, 8262, 229446,
    245953, 20676, 45189, 69826, 131075,
    28672, 155717, 118851, 221318, 254150,
    135235, 86083, 41089, 28743, 32772,
    225475, 118855, 249862, 184320, 217154
};

map<int,ll> mp; //mp[state] = num
int n=16;
ll ans=0;
void dfs(int st,int idx)
{
    ans=max(ans,mp[st]);
    if(idx==n)
        return;
    mp[st+(1<<idx)] = mp[st]^a[idx];
    dfs(st+(1<<idx),idx+1);
    dfs(st,idx+1);
}
bool cmp(ll a,ll b)
{
    return a>b;
}

int main()
{
    //sort(a,a+30,cmp);
    dfs(0,0); //因为第一个数就有可取可不取,所以从st=0开始,idx=0
    cout<<ans;
    return 0;
}
