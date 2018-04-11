#include <bits/stdc++.h>
using namespace std;
//i row,  j square,  k board:   a k,i,j
const int maxn = 105; 
int mp[maxn][maxn];

int f[4][2]; //0:0
int n;

int get0()
{
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i%2==1)
            {
                if(j%2==1)
                    ans += (mp[i][j]!=0);
                else
                    ans += (mp[i][j]!=1);
            }
            else
            {
                if(j%2==1)
                    ans += (mp[i][j]!=1);
                else 
                    ans += (mp[i][j]!=0);
            }
        }
    }
    return ans;
}
int get1()
{
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i%2==1)
            {
                if(j%2==1)
                    ans += (mp[i][j]!=1);
                else
                    ans += (mp[i][j]!=0);
            }
            else
            {
                if(j%2==1)
                    ans += (mp[i][j]!=0);
                else 
                    ans += (mp[i][j]!=1);
            }
        }
    }
    return ans;
}
int main()
{
    //freopen("in","r",stdin);
    scanf("%d%*c",&n);
    char tmp[105];

    for(int k=0;k<4;k++)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%s%*c",tmp);
            for(int j=1;j<=n;j++)
            {
                mp[i][j] = tmp[j-1]-'0';
            }
        }
        if(k<3)getchar();
        f[k][0] = get0();
        f[k][1] = get1();
    }
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout << mp[i][j];
        }
        cout << endl;
    }
    */
    int ans = 0x3f3f3f3f;
    //0011    0101  1001
    //1100  1010  0110
    ans = min(ans, f[0][0]+f[1][0]+f[2][1]+f[3][1]);
    ans = min(ans, f[0][0]+f[1][1]+f[2][0]+f[3][1]);
    ans = min(ans, f[0][1]+f[1][0]+f[2][0]+f[3][1]);
    ans = min(ans, f[0][1]+f[1][1]+f[2][0]+f[3][0]);
    ans = min(ans, f[0][1]+f[1][0]+f[2][1]+f[3][0]);
    ans = min(ans, f[0][0]+f[1][1]+f[2][1]+f[3][0]);
    cout << ans;
    return 0;
}
