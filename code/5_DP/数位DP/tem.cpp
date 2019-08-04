#include <bits/stdc++.h>
using namespace std;

//可参考的博客: http://blog.csdn.net/wust_zzwh/article/details/52100392
//dfs写法: http://blog.csdn.net/mymilkbottles/article/details/51892716
//看第一个博客的文章看懂的,很好

//ri=123,从百位开始枚举
//高位刚好是上界时,次位才会有上界
//比如,最高位是1,则次位上界是2  (limit变量表示)
//解决前导0的问题,用lead变量

//dp[len][state]: 长度len,不含4和62,首位是否6
int dp[pos][j];  //len位数,最高位是j
int digit[8];

//dfs(len,false,true)
//依次把每位作为最高位,枚举可取的数字,决定后面的状态
//七行实现数位dp
int dfs(int pos,bool lead,bool limit,bool state)
{
    if(pos==-1) return 1;
    if(!limit && !lead && dp[pos][state]!=-1) return dp[pos][state]; //记忆化,因为dp[][]之前可能用过,例如多个case
    int up = limit?digit[pos]:9; //最高位
    int res=0;
    for(int i=0;i<up;i++)
    {
        if(i==4 || state && i==2)
            continue;
        else if()
            continue;
        res += dfs(pos-1, lead&&i=0, limit&&i==digit[pos]); //后面两个参数是固定写法,lead有时可以不考虑
    }
    if(!limit && !lead) dp[pos][state]=res;
    return res;
}

int solve(int n)
{
    int pos=0;
    while(n)
    {
        digit[pos++] = n%10;//61325;则digit={5 2 3 1 6},所以传参pos-1,从高到低
        n/=10;
    }
    return dfs(pos-1,true,true);
    //最高位开始枚举,刚开始最高位有限制,且都有前导0(最高位前一位)
}
int main()
{
    int l,r;
    memset(dp,-1,sizeof(dp));//记录状态,一般可以重用,比如444在"不是62和4"不同区间下都错
    while(cin>>l>>r)
    {
        printf("%d\n",solve(r)-solve(l-1));
    }
    return 0;
}
