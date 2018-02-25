#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n;
int a[maxn];
int b[maxn];
char str[maxn];

int main()
{
    cin>>n;
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%s",str);
    int cnt_0=0;
    int cnt_1=0;
    int max_l=-1e9;
    int min_r=1e9;
    for (int i=0;i<n;i++)
    {
        
        if(cnt_0 >= 4)
        {
            if (str[i]=='1')
            {
                for (int j=i-4;j<=i;j++)
                {
                    max_l = max(a[j],max_l);
                }
            }
        }
        else if (cnt_1 >= 4)
        {
            if (str[i]=='0')
            {
                for (int j=i-4;j<=i;j++)
                {
                    min_r = min(min_r, a[j]);
                }
            }
        }

        if (str[i] == '0')
        {
            cnt_1 = 0;
            cnt_0++;
        }
        else if (str[i] == '1')
        {
            cnt_1++;
            cnt_0 = 0;
        }

    }
    cout << (max_l+1) << ' ' << (min_r-1);
    
    return 0;
}
