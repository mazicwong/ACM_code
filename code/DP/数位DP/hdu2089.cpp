#include <bits/stdc++.h>
using namespace std;

//可参考的博客: http://blog.csdn.net/wust_zzwh/article/details/52100392
//dfs写法: http://blog.csdn.net/mymilkbottles/article/details/51892716
//看第一篇博客看懂的

//ri=123,从百位开始枚举
//高位刚好是上界时,次位才会有上界
//比如,最高位是1,则次位上界是2  (limit变量表示)

//dp[len][state]: 长度len,不含4和62,首位是否6
int digit[20];
int dp[20][2];  //len位数,前一位是否为6

//依次把每位作为最高位,枚举可取的数字,决定后面的状态
int dfs(int pos,int pre,int state,bool limit)
{
    if(pos==-1) return 1;
    if(!limit && dp[pos][state]!=-1) return dp[pos][state];
    int up = limit?digit[pos]:9; //最高位
    int res=0;
    for(int i=0;i<=up;i++)
    {
        if(pre==6 && i==2) continue;
        if(i==4) continue;
        res += dfs(pos-1,i,i==6,limit&&i==digit[pos]);
    }
    if(!limit) dp[pos][state]=res;
    return res;
}

int solve(int n)
{
    int pos=0;
    while(n)
    {
        digit[pos++] = n%10;//61325; 5 2 3 1 6
        n/=10;
    }
    return dfs(pos-1,-1,false,true);
    //最高位开始枚举,刚开始最高位有限制,且都有前导0(最高位前一位)
}
int main()
{
    int l,r;
    memset(dp,-1,sizeof(dp));
    while(cin>>l>>r && l && r)
    {
        printf("%d\n",solve(r)-solve(l-1));
    }
    return 0;
}
