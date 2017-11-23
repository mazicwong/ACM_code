

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<iomanip>
#include<set>
#include<cctype>
#include<ctime>
#define INF 0x3f3f3f3f
const double PI=acos(-1.0);
using namespace std;
string s;
int num[1200];
void init()
{
    num[0]=num[1]=0;
    num[2]=1;
    for(int i=3;i<1100;i++)
    {
        num[i]=num[i-1]+i-1;
    }
    return ;
}
int main()
{
    freopen("in3","r",stdin);
    int n;
    init();
    while(~scanf("%d",&n))
    {
        if(n==0)
        {
            cout<<"a"<<endl;
            continue;
        }
        s="";
        int alp=0;
        while(n>0)
        {
            //cout<<n<<endl;
            int p=upper_bound(num,num+1000,n)-num;
            p--;
            n-=num[p];
            while(p--)
            {
                s+=char('a'+alp);
            }
            alp++;
        }
        cout<<s<<endl;
    }
    return 0;
}
