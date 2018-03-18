#include <bits/stdc++.h>
using namespace std;
int dp[22][6];
int len[22];
int st[22];
void upd(int row)
{
    int cnt=0;
    int idx=1;
    int ans=0;
    bool first=true;
    int tmp_st=1;
    while(idx<=5)
    {
        if(dp[row][idx]==0 && first==true)
        {
            first=false;
            tmp_st=idx;
            cnt++;
        }
        else if (dp[row][idx]==0 && first==false)
        {
            cnt++;
        }
        else
        {
            first=true;
            cnt=0;
        }
        if(cnt>ans)
        {
            st[row]=tmp_st;
            ans=cnt;
        }
        idx++;
    }
    len[row]=ans;
}
int main()
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=20;i++)len[i]=5;
    for(int i=1;i<=20;i++)st[i]=1;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int num;cin>>num;
        bool flag=false;
        for(int row=1;row<=20;row++)
        {
            if(len[row] >= num)
            {
                flag=true;
                for(int t=st[row];t<st[row]+num;t++)
                {
                    dp[row][t]=1;
                    cout<<(row-1)*5+t<<' ';
                }
                cout<<endl;
                upd(row);
                break;
            }
        }
        if(flag==false)
        {
            for(int _row=1;_row<=20;_row++)
            {
                for(int _col=1;_col<=5;_col++)
                {
                    if(num==0)break;
                    if(dp[_row][_col]==0)
                    {
                        cout<<(_row-1)*5+(_col)<<' ';
                        num--;
                    }
                }
                if(num==0)break;
            }
            cout<<endl;
        }
    }
    return 0;
}
