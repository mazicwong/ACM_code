#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;cin>>n>>k;
    if(k==1)
    {
        cout << n;
        return 0;
    }
    queue<int> Q;
    for(int i=1;i<=n;i++)
    {
        if(i%k!=0 && i%10!=k)
            Q.push(i);
    }

    long long cnt=n;
    while(Q.size()>1)
    {
        int tmp=Q.front(); Q.pop();
        cnt++;
        if(cnt%k==0 || cnt%10==k) continue;
        else Q.push(tmp);
    }
    cout<<Q.front();
    return 0;
}
