#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
map<pii,bool> mp;
int main()
{
    int n;
    while(cin>>n)
    {
        int x,y;
        mp.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            mp[make_pair(x,y)]=1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {

            }
        }
    }

    return 0;
}
