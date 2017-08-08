/*************************************************************************
	> File Name: poj1015.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年08月07日 星期一 13时25分53秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
/*
 * http://blog.csdn.net/lyy289065406/article/details/6671105
 * 选几个人,每个人对defence & prosecution 打分0..20
 * D{J}=sum{d[j]..}
 * P{J}=sum{p[j]..}
 * D{J}-P{J} minimal
 */
const int maxn = 200+5;

int p[maxn];
int d[maxn];
int s[maxn];//p+d
int v[maxn];//p-d
int dp[21][801];//dp[i,j]: 取i个人,使得差值为j
int path[21][801];//dp[i][j]最后选的那个人的编号

bool select(int j,int k,int i,int *v)
{
    while(j>0 && path[j][k]!=i)
    {
        k -= v[path[j][k]];
        j--;
    }
    return j?0:1;
}
int main()
{
    freopen("in","r",stdin);
    int n,m;//candidate & jury
    int ans = 0;
    while(scanf("%d%d",&n,&m)!=EOF && (n||m))
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&p[i],&d[i]);
            s[i]=p[i]+d[i];
            v[i]=p[i]-d[i];
        }
        memset(dp,-1,sizeof(dp));
        memset(path,0,sizeof(path));
        int fix=m*20;  //总修正值，修正极限为从[-400,400]映射到[0,800]  
        
        dp[0][fix]=0;   //由于修正了数值，因此dp[0][fix]才是真正的dp[0][0]  
        for (int j=1;j<=m;j++)
        {
            for (int k=0;k<=2*fix;k++)
            {
                if (dp[j-1][k]>=0)
                {
                    for (int i=1;i<=n;i++)
                    {
                        if (dp[j][k+v[i]] < dp[j-1][k]+s[i])
                        {
                            if (select(j-1,k,i,v))
                            {
                                dp[j][k+v[i]] = dp[j-1][k]+s[i];
                                path[j][k+v[i]] = i;
                            }
                        }
                    }
                }
            }
        }
        int k=0;
        for(k=0;k<=fix;k++)  
            if(dp[m][fix-k]>=0 || dp[m][fix+k]>=0)//从中间向两边搜索最小辨控差的位置k
                break;

        int div=dp[m][fix-k]>dp[m][fix+k]?(fix-k):(fix+k);//最小辨控差
        printf("Jury #%d\nBest jury has value ",++ans);
        //辩方总值 = （辨控和+辨控差+修正值）/2
        printf("%d for prosecution and value ",(dp[m][div]+div-fix)/2);
        //控方总值 = （辨控和-辨控差+修正值）/2  
        printf("%d for defence:",(dp[m][div]-div+fix)/2);

        int id[25];//最后选的人
        for (int i=0,j=m,k=div;i<m;i++,j--)
        {
            id[i]=path[j][k];
            k-=v[id[i]];
        }
        sort(id,id+m);
        for (int i=0;i<m;i++)
            printf(" %d",id[i]);
        puts("");
    }
    return 0;
}
