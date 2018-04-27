//hdu1677
//Dilworth is the world’s most prominent collector of Russian nested dolls
//找到有多少个递增子序列，二维偏序
//逆序求一个最长非递减子序列,LIS
#include <bits/stdc++.h>
using namespace std;
const int maxn = 20000+5;
int stac[maxn];  
int dp[maxn];  
int maxx;  
int n;  
struct node  
{  
    int w;  
    int h;  
}a[maxn];  
int cmp(struct node b,struct node c)  
{  
    if(b.w==c.w)  
    return b.h<c.h;  
    else return b.w>c.w;  
}  
void LIS()  
{  
    memset(dp,0,sizeof(dp));  
    memset(stac,0,sizeof(stac));  
    int top=0;  
    stac[top]=-99999999;  
    maxx=-1;  
    for(int i=1; i<=n; i++)  
    {  
        if(a[i].h>=stac[top])  
        {  
            stac[++top]=a[i].h;  
            dp[i]=top;  
        }  
        else  
        {  
            int l=1,r=top;  
            while(l<=r)  
            {  
                int mid=(l+r)>>1;  
                if(a[i].h>=stac[mid])  
                {  
                    l=mid+1;  
                }  
                else  
                    r=mid-1;  
            }  
            stac[l]=a[i].h;  
            dp[i]=l;  
        }  
        if(dp[i]>maxx)  
        maxx=dp[i];  
    }  
}  
  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d",&n);  
        for(int i=1;i<=n;i++)  
        {  
            scanf("%d%d",&a[i].w,&a[i].h);  
        }  
        sort(a+1,a+n+1,cmp);  
        LIS();  
        printf("%d\n",maxx);  
    }  
    return 0;  
}  
