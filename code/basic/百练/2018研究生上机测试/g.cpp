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
const int maxn = 1e4+5;
int a[maxn];
int sum[maxn];
bool vis[maxn];

int main()
{
    int n; cin>>n;;
    scanf("%d",&a[0]); sum[0]=a[0]; sum[0]%=n;
    for(int i=1;i<n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
        sum[i]%=n;
    }
    for(int i=0;i<n;i++)
    {
        if(sum[i]==0)
        {
            cout << i+1 << endl;
            for(int j=0;j<i;j++)
                cout << a[j] << ' ';
            cout << a[i];
            return 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(vis[sum[i]]==0)
        {
            vis[sum[i]]=1;
        }
        else
        {
            for(int j=0;j<n;j++)
            {
                if(sum[j]==sum[i])
                {
                    cout << (i-j)<<endl;
                    for(int k=j+1;k<i;k++)
                    {
                        cout << a[k] << ' ';
                    }
                    cout<<a[i];
                    return 0;
                }
            }
        }
        
    }

    return 0;
}
