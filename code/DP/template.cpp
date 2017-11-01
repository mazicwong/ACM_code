1. LCS
2. LIS
3. DP+dfs
4. 状压DP
5. 数位DP
6. 背包

/*
 * 1. LCS:最长公共子序列
 */
const int maxn = 1000 + 5;

//dp[i][j]: the maximum common length of string "x[1]..x[i]" and "y[1]..y[j]"
char str1[maxn],str2[maxn];
int dp[maxn][maxn];
int b[maxn][maxn];
bool vis[maxn];

//LCS计算长度 O(len1*len2)
void LCSLength()
{
    memset(vis,0,sizeof(vis));
    int len1 = strlen(str1), len2 = strlen(str2);
    for (int i = 0; i <= len1; i++) dp[i][0] = 0;
    for (int i = 0; i <= len2; i++) dp[0][i] = 0;

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i-1] == str2[j-1])
                {dp[i][j]=dp[i-1][j-1]+1; vis[i-1]=1;}
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
}

//LCS输出路径 O(len1)
void LCS()
{
    for (int i=0;i<strlen(str1);i++)
    {
        if (vis[i]==1)
        {
            cout << str1[i];
        }
    }
    cout << endl;
}

int main()
{
	while (scanf("%s%s%*c", str1, str2) != EOF)
	{
        LCSLength();
        int len1=strlen(str1),len2=strlen(str2);
        printf("%d\n", dp[len1][len2]);
        LCS();
	}
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////

2. LIS O(nlogn)
/*
 * poj2533  LIS+记录最大模板
 * 复杂度: O (nlogn)
 * b[i]:保存每个以a[i]结尾的最长上升子序列
 * 其中low_bound 返回第一个大于它的数的下标。
 * b[0...max(dp[i])]: 记录LIS结果
 */

const int maxn = 1e3+5;
const int INF = 0x3f3f3f3f;
int a[maxn];
int b[maxn];
int dp[maxn];
int main()
{
    int n; cin >> n;
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    memset(b,INF,sizeof(b));
    memset(dp,0,sizeof(dp));
    for (int i=0;i<n;i++)
    {
        int pos = lower_bound(b,b+n,a[i])-b;//a[i]在b[]中的位置
        dp[i] = pos+1;
        b[pos] = a[i];
    }
    int ans = 0;
    for (int i=0;i<n;i++)
        ans=max(ans,dp[i]);
    cout << ans;
    /*cout << endl;
    for (int i=0;i<ans;i++)
        cout << b[i] << " ";*/
    return 0;
}



/////////////////////////////////////////////////////////////////////////////////
3. DP+dfs区别
/*
 * n*n矩阵,吃奶酪
 * 走四个方向,每次最多走k步
 * 且要求走的地方的奶酪是递增的,问最多能迟到多少奶酪
 * 
 * 明显,直接DP,虽然子问题重复,但是不满足无后效性,因为每次移动的方向不是固定的,而且四个方向,所以用记忆花搜搜
 * 这题要DP的话,先将所有点按权值排列,这样找到一个方向后,可以进行DP
 */

//DP写法   
const int maxn = 100+5;
int mp[maxn][maxn],dp[maxn][maxn];
int n,k;
struct Node{
    int i,j;
    int val;
    bool operator <(const Node& mm) const{
        return val<mm.val;
    }
}node[maxn*maxn];
int main()
{
    freopen("in","r",stdin);
    while(scanf("%d%d",&n,&k) && n!=-1)
    {
        int tot=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                scanf("%d",&mp[i][j]);
                if (i==0 && j==0)
                    continue;
                node[tot].i=i; node[tot].j=j; node[tot++].val=mp[i][j];
            }
        }
        sort(node,node+tot);
        memset(dp,-1,sizeof(dp));
        dp[0][0]=mp[0][0];
        int ans = dp[0][0];
        for (int tt=0;tt<tot;tt++) //找到范围内比他小的点
        {
            //自底向上更新点(i,j)
            int i=node[tt].i, j=node[tt].j;
            for (int rr=max(0,i-k);rr<=min(n-1,i+k);rr++)
            {
                if (mp[rr][j]>=mp[i][j]) continue;
                if (dp[rr][j]==-1) continue;
                dp[i][j] = max(dp[i][j], dp[rr][j]+mp[i][j]);
            }
            for (int cc=max(0,j-k);cc<=min(n-1,j+k);cc++)
            {
                if (mp[i][cc]>=mp[i][j]) continue;
                if (dp[i][cc]==-1) continue;
                dp[i][j] = max(dp[i][j], dp[i][cc]+mp[i][j]);
            }
            ans = max(ans,dp[i][j]);
        }
        cout << ans << endl;
    }
    return 0;
}

/*
//搜索写法  109ms, 1.8MB
const int maxn = 100+5;
int mp[maxn][maxn];
int dp[maxn][maxn];
int to[4][2]={
    {0,1},{0,-1},{1,0},{-1,0}
};
int n;int k;
int dfs(int i,int j)
{
    int ans=0;
    if (!dp[i][j]) //这里是记忆化搜索
    {
        for (int len=1;len<=k;len++)//最多走k次
        {
            for (int tt=0;tt<4;tt++)//4个方向
            {
                int nx = i+to[tt][0]*len;
                int ny = j+to[tt][1]*len;
                if (nx>=0 && nx<n && ny>=0 && ny<n && mp[nx][ny]>mp[i][j])
                    ans = max(ans,dfs(nx,ny));//ans:最大的dp[nx][ny]
            }
        }
        dp[i][j] = ans+mp[i][j];
    }
    return dp[i][j];
}

int main()
{
    while(scanf("%d%d",&n,&k) && n!=-1)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                scanf("%d",&mp[i][j]);
            }
        }
        memset(dp,0,sizeof(dp));
        int ans = dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
*/


/////////////////////////////////////////////////////////////////////////////////
4. 状压DP
/*
 * n点,m边,有money前
 * 经过城市i操作:
 * 1.路过,money不变
 * 2.先花费cost[i],再赚earn[i],获取license
 *
 * h个点,问能否获取所有的lincense 
 *
 * h<=15; 必须经过的点只有15个,直接状压dp,枚举所有状态
 * dp[i,j]: 到达状态i切到达的最后一个城市是j时剩余最多的钱
 *
 * 状压DP: dp[1<<bit][j],在每种状态情况下,更新dp最优值O(n^3)
 */

const int INF = 0x3f3f3f3f;
int dp[1<<16][16];
int dist[100+5][100+5];
int num[20],cost[20],earn[20];
void init(int n)
{
    for (int i=0;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            dist[i][j]=dist[j][i]=INF;
}
int n,m,val;
void floyd()
{
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
}
int h;
void DP()
{
    int bit = 1<<(h+1);
    memset(dp,-1,sizeof(dp));
    dp[1][0]=val;
    for (int i=1;i<bit;i++) //遍历所有状态
    {
        for (int j=0;j<=h;j++)  //在i状态下O(n^2)找一遍图
        {
            if (dp[i][j]==-1) continue;
            for (int k=1;k<=h;k++)
            {
                if (dp[i][j] > dist[num[j]][num[k]]+cost[k])//钱够用,则松弛,路过k
                {
                    int p = 1<<k, del=earn[k]-cost[k];
                    if (i&p) continue;
                    dp[i|p][k]=max(dp[i|p][k], dp[i][j]-dist[num[j]][num[k]]+del);
                }
            }
        }
    }
    bool flag=false;
    for (int i=0;i<=h;i++)
        if (dp[bit-1][i] >= dist[num[i]][1])
            flag=true;
    if (flag) puts("YES");
    else puts("NO");
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&val);
        init(n);
        int u,v,c;
        for (int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            dist[u][v]=dist[v][u]=min(dist[u][v],c);
        }
        scanf("%d",&h);
        for (int i=1;i<=h;i++)
        {
            scanf("%d%d%d",&num[i],&earn[i],&cost[i]);
        }
        floyd();
        num[0]=1; earn[0]=cost[0]=0;
        DP();
    }
    return 0;
}


/////////////////////////////////////////////////////////////////////////////////
5. 数位DP
//hdu2089: 不要62
//对一个区间[l,r],问有多少个数满足没有连续的62出现

int dp[10][3];//dp[i][j]，i代表数字的位数，j代表状况  
//dp[i][0],表示不存在不吉利数字  
//dp[i][1],表示不存在不吉利数字，且最高位为2  
//dp[i][2],表示存在不吉利数字  
void Init()  
{  
    memset(dp,0,sizeof(dp));  
    int i;  
    dp[0][0] = 1;  
    for(i = 1; i<=6; i++)//数字最长为6  
    {  
        dp[i][0] = dp[i-1][0]*9-dp[i-1][1];//最高位加上不含4的9个数字的状况，但因为会放6，所以要减去前一种开头为2的情况  
        dp[i][1] = dp[i-1][0];//开头只放了2  
        dp[i][2] = dp[i-1][2]*10+dp[i-1][0]+dp[i-1][1];//已经含有的前面放什么数都可以，或者是放一个4，或者是在2前面放6  
    }  
}  
int solve(int n)  
{  
    int i,len = 0,tem = n,ans,flag,a[10];  
    while(n)//将每一位拆分放入数组  
    {  
        a[++len] = n%10;  
        n/=10;  
    }  
    a[len+1] = ans = 0;  
    flag = 0;  
    for(i=len; i>=1; i--)  
    {  
        ans+=dp[i-1][2]*a[i];  
        if(flag)//如果已经是不吉利了，任意处理  
            ans+=dp[i-1][0]*a[i];  
        if(!flag && a[i]>4)//首位大于4，可以有放4的情况  
            ans+=dp[i-1][0];  
        if(!flag && a[i+1]==6 && a[i]>2)//后一位为6，此位大于2  
            ans+=dp[i][1];  
        if(!flag && a[i]>6)//此位大于6，可能的62状况  
            ans+=dp[i-1][1];  
        if(a[i]==4 || (a[i+1]==6&&a[i]==2))//标记为不吉利  
            flag = 1;  
    }  
    return tem-ans;  
}  
int main()  
{  
    int l,r;  
    Init();  
    while(~scanf("%d%d",&l,&r),l+r)  
    {  
        printf("%d\n",solve(r+1)-solve(l));  
        //因为solve函数中并没有考虑n是不是不幸数的情况，所以r+1只算了1~r，而l只算了1~l-1,这两者相减才是正确答案  
    }  
    return 0;  
}  



/////////////////////////////////////////////////////////////////////////////////
6.背包
//01背包
const int maxn = 1000+5;
int dp[maxn];
int w[maxn];
int v[maxn];
int main()
{
    int t; cin >> t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        int n,vv;
        cin >> n >> vv;
        for (int i=0;i<n;i++)
            scanf("%d",&w[i]);
        for (int i=0;i<n;i++)
            scanf("%d",&v[i]);
        for (int i=0;i<n;i++)
            for (int j=vv;j>=v[i];j--)
                dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
        printf("%d\n",dp[vv]);
    }
    
    return 0;
}

//多重背包
//题意：给你这些一些东西的价值和数量，让你将总价值分为两个数使其最为接近。
//多重背包的题目，我们可以先求sum/2可以获得的最大价值。
//dp[k]是价格为k时，大于j且离j最近的能取到的数
//状态转移方程：dp[k]  = max ( dp[k], dp[k-val[i]] + val[i] )
const int maxn = 50 * 50 * 100 + 5;
const int maxm = 50 * 100 + 5;
int dp[maxn];
int val[maxm];
int num[maxm];
int main()
{
	int n;
	while (cin >> n&&n >= 0)
	{
		memset(dp, 0, sizeof(dp));
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> val[i] >> num[i];
			sum += val[i] * num[i];
		}
		for (int i = 0; i < n; i++)
			for (int j = 1; j <= num[i]; j++)
				for (int k = sum / 2; k >= val[i] * j; k--)
					dp[k] = max(dp[k], dp[k - val[i]] + val[i]);

		cout << sum - dp[sum / 2] << " " << dp[sum / 2] << endl;
	}
	return 0;
}

//完全背包

