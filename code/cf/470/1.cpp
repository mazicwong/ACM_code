#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
char str[maxn][maxn];

bool check(int i,int j)
{
    if(str[i][j-1]=='W' || str[i][j+1]=='W' || str[i-1][j]=='W' || str[i+1][j]=='W')
        return false;
    return true;
}
int main()
{
    int n;cin>>n;
    int m;cin>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",str[i]+1);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str[i][j]=='.') str[i][j]='D';
            else if (str[i][j]=='S')
            {
                if(check(i,j)==false)
                {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    cout << "YES" << endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout << str[i][j];
        }
        cout << endl;
    }
    return 0;
}
