//hdu1518.cpp
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

//给一堆树枝，问能否连成一个正方形
//即分成４部分
//从大往小选取的思想，结合dfs
int len[25];

bool vis[25];
int m;
int sum=0;
bool dfs(int tot,int now,int left) {
    //
    if (tot==3) {
        return true;
    }
    for (int i=now;i<m;i++) {
        if (vis[i]) //排列数转化为子集树，用vis(这题可以看成对ｍ个数排列)
            continue;
        vis[i]=true;
        if (len[i]==left) {
            if (dfs(tot+1,0,sum)) //搜到一个了，从头开始搜另一个
                return true;
        }
        else if (len[i]<left) {
            if (dfs(tot,i+1,left-len[i]))
                return true;
        }
        vis[i]=false;
        //if (dfs(tot,i+1,left)) 
          //  return true;
    }
    return false;
}
bool cmp(const int a,const int b){
    return a>b;
}
int main()
{
    freopen("in","r",stdin);
    int n; cin>>n;
    while(n--) {
        cin>>m;
        sum=0;
        for (int i=0;i<m;i++){
            scanf("%d",&len[i]);
            sum+=len[i];
        }
        if (sum%4!=0) {
            cout <<"no"<<endl;
            continue;
        }
        sum = sum/4;

        bool ff=true;
        for (int i=0;i<m;i++) {
            if (len[i]>sum) {
                cout << "no" << endl;
                ff=false;
                break;
            }
        }
        if (ff==false) continue;
        //上面，dfs先把特例判掉，后面省事多了

        sort(len,len+m,cmp);
        memset(vis,0,sizeof(vis));
        if (dfs(0,0,sum))
            cout << "yes" << endl;
        else cout << "no" << endl;
        
    }
    return 0;
}
