#include <bits/stdc++.h>
using namespace std;

int grid[22][12];
int kuai[6][6];
int get_row()
{
    int cnt=0;
    for(int row=4;row>=1;row--)
    {
        bool flag=true;
        for(int j=1;j<=4;j++)
        {
            if(kuai[row][j]==0)
            {
                ;
            }
            else
            {
                flag=false;
                break;
            }
        }
        if(flag==true) cnt++;
        else
        {
            break;
        }
    }
    return cnt;
}
int roo=4;
void tianchong(int row,int col)
{
    int iii=4-roo;
    int jjj=1;
    for(int i=row;i>row-4 && iii>=1;i--,iii--)
    {
        jjj=1;
        for (int j=col;j<col+4;j++)
        {
            if (kuai[iii][jjj]==1 && grid[i][j]==0)
            {
                grid[i][j]=1;
            }
            jjj++;
        }
    }
}
bool is_ok(int row,int col)
{
    int iii=4-roo;
    int jjj=1;
    for(int i=row;i>row-4 && iii>=1;i--,iii--)
    {
        jjj=1;
        for (int j=col;j<col+4;j++)
        {
            if(kuai[iii][jjj]==0)
            {
                ;
            }
            else if (kuai[iii][jjj]==1 && grid[i][j]==0)
            {
                ;
            }
            else if (kuai[iii][jjj]==1 && grid[i][j]==1)
            {
                return 0;
            }
            jjj++;
        }
    }
    return 1;
}
int main()
{
    //freopen("in","r",stdin);
    for(int i=1;i<=15;i++)
    {
        for(int j=1;j<=10;j++)
        {
            cin>>grid[i][j];
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            cin>>kuai[i][j];
        }
    }

    int num; cin>>num;
    roo = get_row();
    for(int row=15;row>=1;row--)
    {
        if(is_ok(row,num)==true)
        {
            tianchong(row,num);
            break;
        }
    }
    for(int i=1;i<=15;i++)
    {
        for(int j=1;j<=10;j++)
        {
            cout<<grid[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
