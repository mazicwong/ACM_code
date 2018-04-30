/*
#include <bits/stdc++.h>
using namespace std;
int nowh,nowm;
int preh,prem;
int calc()
{
    int delh=nowh-preh;
    int delm=nowm-prem;
    if(delm<0){
        delm+=60;
        delh-=1;
    }
    return delh*60+delm;
}

int main()
{
    int n,s; cin>>n>>s;
    cin>>preh>>prem;
    if(preh*60+prem>=s+1)
    {
        for(int i=1;i<n;i++)
        {
            cin>>nowh>>nowm;
        }
        cout << "0 0";
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        cin>>nowh>>nowm;
        int tmp = calc();
        if(tmp>=2*(s+1))
        {
            nowm=prem+s+1;
            if(nowm>=60){
                preh+=(nowm/60);
                nowm%=60;
            }
            cout<<preh << ' ' << nowm;
            return 0;
        }
        else
        {
            preh=nowh;
            prem=nowm;
        }
    }
            nowm=nowm+s+1;
            if(nowm>=60){
                nowh+=(nowm/60);
                nowm%=60;
            }
            cout<<nowh << ' ' << nowm;   

    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int l[maxn],e[maxn];
const int INF = 0x3f3f3f3f;
int main()
{
    int n,m,cl,ce,v;
    cin>>n>>m>>cl>>ce>>v;
    for(int i=0;i<cl;i++)
    {
        scanf("%d",&l[i]); //stairs
    }
    for(int i=0;i<ce;i++)
    {
        scanf("%d",&e[i]); //elevator
    }

    
    int q; cin>>q;
    int x1,y1,x2,y2;
    while(q--)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1>x2) swap(x1,x2);
        if(y1>y2) swap(y1,y2);
        if(x1==x2){
            cout << abs(y2-y1) << endl;
            continue;
        }
        //[y1,y2]
        int del = lower_bound(e,e+ce,y1)-e;
        if(del==ce) del--;
        int ans1 = abs(e[del]-y1);
        ans1 = ans1 + (x2-x1)/v + ((x2-x1)%v!=0);
        ans1 += abs(y2-e[del]);

        int ans2;
        int del1;
        if(del==0) ans2=INF;
        else{
            del1=del-1;
            ans2 = abs(e[del1]-y1);
            ans2 = ans2 + (x2-x1)/v + ((x2-x1)%v!=0);
            ans2 += abs(y2-e[del1]);
        }

        int ans3;
        int del2;
        if(del==ce-1) ans3=INF;
        else{
            del2=del+1;
            ans3 = abs(e[del2]-y1);
            ans3 = ans3 + (x2-x1)/v + ((x2-x1)%v!=0);
            ans3 += abs(y2-e[del2]);
        }
        
        int ans4;
        int del4 = lower_bound(l,l+cl,y1)-l;
        if(del4==cl) del4--;
        ans4 = abs(l[del4]-y1);
        ans4 = ans4 + abs(x2-x1) + abs(y2-l[del4]);

        int ans5;
        int del5;
        if(del4==0) ans5=INF;
        else {
            del5=del4-1;
            ans5 = abs(l[del5]-y1);
            ans5 = ans5 + abs(x2-x1) + abs(y2-l[del5]);
        }

        int ans6;
        int del6;
        if(del4==cl-1) ans6=INF;
        else {
            del6=del4+1;
            ans6 = abs(l[del6]-y1);
            ans6 = ans6 + abs(x2-x1) + abs(y2-l[del6]);
        }
        if(cl==0){
            cout << min(ans1,min(ans2,ans3)) << endl;
        }
        else if (ce==0){
            cout << min(ans4,min(ans5,ans6)) << endl;
        }
        else {
            cout << min(ans1,min(ans2,min(ans3,min(ans4,min(ans5,ans6))))) << endl;
        }
    }
    return 0;
}
