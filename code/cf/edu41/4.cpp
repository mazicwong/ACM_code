#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int x[maxn];
int y[maxn];

struct P{
    int x,y;
    double k;
}p[maxn];
bool cmp(struct P a,struct P b)
{
    return a.k < b.k;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].x>>p[i].y;
        p[i].k = (double)p[i].x/(double)p[i].y;
    }
    sort(p,p+n,cmp);

    int cnt=1;
    int num=0;
    double tmp = 0;
    int max_cnt=0;
    for(int i=1;i<n;i++)
    {
        if(p[i].k == p[i-1].k)
        {
            cnt++;
            max_cnt=max(cnt,max_cnt);
        }
        else cnt=1;
        if(cnt==3) num++, tmp=p[i].k;
    }
    if(num>=2) 
    {
        cout << "NO";
        return 0;
    }
    if(num==1)
    {
        if(n-max_cnt<=2)
        {
            cout << "YES"; return 0;
        }
        int qq=0;
        int qaq[2];
        for(int i=0;i<n;i++)
        {
            if(p[i].k != tmp)
            {
                qaq[qq++]=i;
            }
            if(qq==2) break;
        }
        double now_k = ;
    }


    return 0;
}
