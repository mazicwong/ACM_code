#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
int arr[maxn];
bool cmp(int a,int b){return a>b;}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        arr[i]=a[i];
    }
    if(k==1){
        cout << "-1";
        return 0;
    }
    sort(arr+1,arr+n+1,cmp);

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            if(j+k>n) continue;
            if(a[j+k]>a[j]) swap(a[j+k],a[j]);
        }
        int test = n-i+k;
        if(test>n) continue;
        if(a[test]!=arr[test]){
            cout << n-test+1;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}
