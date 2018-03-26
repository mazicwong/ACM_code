#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <time.h>
using namespace std;
const int maxn = 305;
const int mod = 1e9+7;
int s[maxn][maxn];
void init()//预处理  
{  
    memset(s,0,sizeof(s));  
    s[1][1]=1;  
    for(int i=2;i<=maxn-1;i++)  
        for(int j=1;j<=i;j++)  
    {  
        s[i][j]=s[i-1][j-1]+j*s[i-1][j];  
        if(s[i][j]>=mod)  
            s[i][j]%=mod;  
    }  
}  

void init1()//预处理  
{  
    memset(s,0,sizeof(s));  
    s[1][1]=1;  
    for(int i=2;i<=maxn-1;i++)  
        for(int j=1;j<=i;j++)  
    {  
        s[i][j]=s[i-1][j-1]+(i-1)*s[i-1][j];  
        if(s[i][j]>=mod)  
            s[i][j]%=mod;  
    }  
}  
int main()
{
    //freopen("in","r",stdin);
	init1();
    int n,k;
    cin>>n>>k;
    cout << s[n][k];
	

    return 0;
}

