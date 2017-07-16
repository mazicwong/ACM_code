/*************************************************************************
	> File Name: hdu1902.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年06月10日 星期六 01时40分27秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
/* one dragon for some heads,and let knights to kill them
 * one knights for a head (the heights of the knights >= dragon)
 * the ans is the total knights heights,minimize the ans
 * Obviously,it is an easy greedy problem! 
 */
const int maxn = 20000+5;
int dragon[maxn];
int knights[maxn];
bool vis[maxn];
int main()
{
    freopen("in.txt","r",stdin);
    int n,m;//dragon & knights
    while(cin>>n>>m && (n||m))
    {
        memset(vis,false,sizeof(vis));
        for (int i=0;i<n;i++) cin>>dragon[i];
        for (int i=0;i<m;i++) cin>>knights[i];
        sort(dragon,dragon+n);
        sort(knights,knights+m);
        //for (int i=0;i<n;i++) cout<<dragon[i];
        //for (int i=0;i<m;i++) cout<<knights[i];
        bool flag = true;
        bool fflag = true;
        int ans = 0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (vis[j]) continue;
                vis[j] = true;
                if (dragon[i]<=knights[j])
                {
                    flag = false;
                    ans += knights[j];
                    break;
                }
            }
            if (!flag)
                flag = true;
            else
            {
                fflag = false;
                break;
            }
        }
        if (!fflag) cout << "Loowater is doomed!" << endl;
        else cout << ans << endl;
    }

    return 0;
}
