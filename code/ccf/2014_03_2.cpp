#include <bits/stdc++.h>
using namespace std;
const int maxn = 12;
struct Window{
    int x1,y1;
    int x2,y2;
    int rank;
    int flag;
}win[maxn];

int main()
{
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>win[i].x1>>win[i].y1;
        cin>>win[i].x2>>win[i].y2;
        win[i].flag=1;
        win[i].rank=i+1;
    }
    int maxx = n;
    for(int i=0;i<m;i++)
    {
        int x,y; cin>>x>>y;
        bool ff=false;
        for (int j=maxx;j>=0;j--)
        {
            if(win[j].flag==0) continue;
            if(x>=win[j].x1&&x<=win[j].x2 && y>=win[j].y1&&y<=win[j].y2)
            {
                win[++maxx].x1 = win[j].x1;
                win[maxx].x2 = win[j].x2;
                win[maxx].y1 = win[j].y1;
                win[maxx].y2 = win[j].y2;
                win[maxx].rank = win[j].rank;
                win[j].flag=0; win[maxx].flag=1;
                cout << win[j].rank << endl;
                ff=true;break;
            }
        }
        if(ff==false) cout << "IGNORED" << endl;
    }
    return 0;
}
