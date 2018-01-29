//3.cpp
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;
char str[5010];

int ans = 0;
int n;

int num[5010];

void dfs(int st, int cnt, bool flag, int now_ans)
{
    for (int i=st;i<=n;i++)
    {
        if (str[i] == '(')
        {
            cnt++;
        }
        else if (str[i] == ')')
        {
            cnt--;
            if (cnt>0) 
            {
                ans++;
                cout << cnt << i << endl; 
            }
            else if (cnt<0)
            {
                cnt=0;
            }
            else
            {
                ans++;
                cout << cnt << i << endl; 
            }
        }
        else if (str[i] == '?')
        {
            //(
            dfs(i+1, cnt+1,flag,now_ans);
            //)
            cnt--;
            if (cnt>0)       {ans++; cout << cnt << i << endl;dfs(i+1,cnt,flag,now_ans);}
            else if (cnt<0)  {dfs(i+1,0,false,0);}
            else if (cnt==0) {ans++;ans+=now_ans; cout << cnt << i << endl; dfs(i+1,0,true,now_ans+1);}
            //
            break;
        }
    }
}

bool f[5010][5010];

int main()
{
    //freopen("in","r",stdin);
    scanf("%s",str);
    int len = strlen(str);
    
    dfs1(1,0);
    ans = 0;
    for (int i=1;i<=n;i++)
    {
        cout << num[i] << ' ';
    }
    cout << endl;
    dfs(1,0,true,0);

    cout << ans;
    return 0;
}
