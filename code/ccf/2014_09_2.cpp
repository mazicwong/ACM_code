#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    int mp[105][105];
    memset(mp,0,sizeof(mp));
    for(int i=1;i<=n;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for(int x=x1;x<x2;x++)
        {
            for(int y=y1;y<y2;y++)
            {
                mp[x][y]=1;
            }
        }
    }
    int cnt = 0;
    for(int i=0;i<=100;i++)
    {
        for(int j=0;j<=100;j++)
        {
            if(mp[i][j]==1)
            {
                cnt++;
            }
        }
    }
    cout<< cnt;
    return 0;
}
