#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
char str[maxn][maxn];

bool check(string s1, string s2)
{

}
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int minn = 105;
        for(int i=0;i<n;i++)
        {
            scanf("%s",str[i]);
            int tmp = strlen(str[i]);
            minn = min(minn, tmp);
        }
        for(int i=0;i<strlen(str[0]);i++)
        {
            for(int j=i+1;)
        }


        for(int len=minn-1; len>=0; len--)
        {
            
        }
    }
    return 0;
}
