/*************************************************************************
	> File Name: hdu1026.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年11月16日 星期四 00时31分30秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
using namespace std;
//.可行    X不可行    n怪物
//from (0,0) to (n-1,n-1)
//
//100个点，直接搜最短路+记录路径
const int inf = 0x3f3f3f3f;
const int maxn = 105;
int to[4][2] = {
    (1,0),(-1,0),(0,1),(0,-1)
};
char mp[maxn][maxn];

void dfs(int x,int y,int tt)
{
    if (x<0 || x>n-1 || y<0 || y>m-1){
        return;
    }
    if (x==n-1 && y==m-1) {
        
        return ;
    }
    for (int i=0;i<4;i++){
        int nx=to[i][0]; int ny=to[i][1];
        if (mp[x+nx][y+ny]=='.') {
            dfs(x+nx,y+ny);
        }
        else if (mp[x+nx][y+ny]=='X'){
            return;
        }
        else {

        }
    }
}
int main()
{
    //freopen("in","r",stdin);
    int n,m;
    while(scanf("%d%d%*c",&n,&m)!=EOF) {
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++) {
                scanf("%c",&mp[i][j]);
            }
            getchar();
        }
        dfs(0,0);
    }
    
    return 0;
}
