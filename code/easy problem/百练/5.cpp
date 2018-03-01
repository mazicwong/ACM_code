#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <time.h>
using namespace std;

//poj2355
const int maxn = 1e5+5;
int a[maxn];
int dp[maxn];
int len[maxn];
int sum[maxn];
int cnt=0;

int L1,L2,L3,C1,C2,C3; 
int re(int ll, int rr)
{
    if (rr-ll <= L1)
        return C1;
    else if (rr-ll <= L2)
        return C2;
    else return C3;
}

int er(int i, int s)
{
    int num = sum[i]-s;//找大于等于num的最小
    int l=1,r=i;
    while(l<r)
    {
        int mid = (l+r)/2;
        if(sum[mid] < num)
            l=mid+1;
        else if (sum[mid] >= num)
            r=mid;
    }
    return r;
}

int err(int i,int s)
{
    int num=sum[i]-s;
    int idx=i;
    while(idx>=1)
    {
        if (sum[idx]>=num && sum[idx-1]<num)
            return idx;
        idx--;
    }
    return 0;
}


const int INF = 0x3f3f3f3f;
int main()
{
    freopen("in","r",stdin);
    ios::sync_with_stdio(false);
    cin>>L1>>L2>>L3>>C1>>C2>>C3;
    int n; cin>>n;
    int l,r; cin>>l>>r;
    for (int i=2;i<=n;i++) cin>>a[i];
    // 0  [3  7  8  13  15]  23
    //       4  1  5  2
    //       4  5  10 12
    //dp     30 30 60 70
    
    cnt=0;
    for (int i=l;i<r;i++) len[++cnt]=a[i+1]-a[i], sum[cnt]=len[cnt]+sum[cnt-1];
    //for (int i=1;i<=cnt;i++) cout << len[i] << "  " << sum[i] << endl;;
    //cout << endl << endl;

    dp[0]=0;
    dp[1]=re(sum[0], sum[1]);
    //dp[2]=min(dp[1]+re(sum[1],sum[2]), dp[0]+re(sum[0],sum[2]));
    for (int i=2;i<=cnt;i++)
    {
        int len_s1 = er(i,L1); if(len_s1<1 || len_s1>=i) len_s1=-1;
        int len_s2 = er(i,L2); if(len_s2<1 || len_s2>=i) len_s2=-1;
        int len_s3 = er(i,L3); if(len_s3<1 || len_s3>=i) len_s3=i-1;

        //cout << len_s1 << "  " << len_s2 << "  " << len_s3 << "  " << endl;

        dp[i] = min(len_s1==-1?INF:dp[len_s1]+C1,
                    min(len_s2==-1?INF:dp[len_s2]+C2, dp[len_s3]+C3) );
    }
    //for (int i=1;i<=cnt;i++) cout<<dp[i]<<' '; cout << endl;
    cout << dp[cnt];

    return 0;
}
