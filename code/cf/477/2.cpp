#include <bits/stdc++.h>
using namespace std;
int n,a,b;
const int maxn = 1e5+5;
int s[maxn];
int main()
{
    cin>>n>>a>>b;
    for(int i=0;i<n;i++) scanf("%d",&s[i]);
    double del = (double)a*s[0]/b;
    int V = (int)del;
    int sum=s[0];
    for(int i=0;i<n-1;i++) s[i]=s[i+1];
    n--;
    sort(s,s+n);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(sum+s[i]<=del)
        {
            ans++;
            sum+=s[i];
        }
        else{
            break;
        }
    }
    cout << (n-ans);
    return 0;
}
