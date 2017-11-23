/*************************************************************************
	> File Name: 3.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年10月05日 星期四 15时41分15秒
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
int cnt[17]; //1<<4
int main()
{
    //freopen("in","r",stdin);
    int n,k; cin>>n>>k;
    int aa;
    for (int i=0;i<n;i++)
    {
        int tmp=0;
        for (int j=k-1;j>=0;j--)
        {
            scanf("%d",&aa);
            tmp+=(aa<<j);
            //tmp = tmp<<1|aa;  //get 
        }
        cnt[tmp]++;
    }
    if (cnt[0])
    {
        cout << "YES";
        return 0;
    }
    int tot = (1<<k)-1;
    for (int i=1;i<=tot;i++)
    {
        if (cnt[i])
        {
            for (int j=i+1;j<=tot;j++)
            {
                if (cnt[j] && (i&j)==0) //每个题所有人的状态压在cnt里面了,只要出现2个题满足就行
                {
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    cout << "NO";

    /*
    //WA 24
    int n,k;cin>>n>>k;
    int aa;
    memset(tt,0,sizeof(tt));
    for (int i=0;i<n;i++)
    {
        for (int j=k-1;j>=0;j--)
        {
            scanf("%d",&aa);
            tt[i]+=(aa<<j);
            //scanf("%d",&tt[i][j]);
        }
    }
    sort(tt,tt+n);
    //暴力伤..n/2又过不了QAQ
    for (int i=0;i<=n/2;i++)
    {
        for (int j=i+1;j<=n/2;j++)
        {
            if ((tt[i]&tt[j]) ==0 )
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    */
    return 0;
}
