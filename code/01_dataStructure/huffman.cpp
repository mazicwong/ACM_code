【问题描述】
 已知输入n个正整数，正整数之间用空格键分开，请以这n个正整数为权值建立一棵有n个叶子节点的哈夫曼树，求这棵哈夫曼树的带权路径长度。

【输入形式】
 首先输入正整数的个数，然后接下来为接下来的正整数，正整数个数不超过10个，每个数字之间用空格隔开。

【输出形式】
 输出相应的权值

【样例输入】
 5
 4 5 6 7 8

【样例输出】
69

# 解法1(会T)
ll leaf[maxn];
int rising(const void *a, const void *b)    
{
    return *(ll*)a - *(ll*)b;
}
int main()
{
    int n;
    ll sum = 0;
    int t; cin>>t;
    while(t--)
    {
        cin>>n;
        memset(leaf,0,sizeof(leaf));
        for(int i=0;i<n;i++) cin>>leaf[i];
        for(int i=0; i<n-1; i++)
        {
            qsort(leaf+i, n-i, sizeof(leaf[0]), rising);    //排序并剔除已使用的叶结点
            leaf[i+1] += leaf[i];     //合并两个最小的叶结点成一新的节点（放在leaf[i+1]中）
            sum += leaf[i+1];         //总路径长 = 所有非叶结点之和
        }
        cout << sum << endl;
    }
    return 0;
}

# 解法2(pque优化)
priority_queue<int, vector<int>, greater<int> > Q;   // 建立一个小顶堆
int main()
{
    int n; cin>>n;
    while (!Q.empty()) Q.pop();
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        Q.push(x);  // 将权值放入堆中
    }
    int ans = 0;
    while (Q.size() > 1) {
        // 取出堆中最小的两个元素
        int a = Q.top();
        Q.pop();
        int b = Q.top();
        Q.pop();
        
        ans += a + b;
        Q.push(a + b);
    }
    cout << ans << endl;
    return 0;
}
