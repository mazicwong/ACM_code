#include <bits/stdc++.h>
using namespace std;
int n;
bool check(int x)
{
    int res=0;
    while(x>0)
    {
        res += x%10;
        x/=10;
    }
    return res==n;
}

bool judge(int x)
{
    int a[10];
    int b[10];
    int cnt=0;
    while(x>0)
    {
        a[cnt++] = x%10;
        x/=10;
    }
    for(int i=0;i<cnt;i++)
    {
        if(a[i]!=a[cnt-i-1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin>>n;
    int cnt=0;
    for(int i=10000;i<=999999;i++)
    {
        if(check(i)==true && judge(i)==true)
        {
            cout<<i<<endl;
            cnt++;
        }
        //if(cnt==n) break;
    }
    if(cnt==0) cout<<"-1";
    return 0;
}
