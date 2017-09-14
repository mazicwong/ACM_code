/*
五分钟博客..  http://blog.csdn.net/yxuanwkeith/article/details/50636898
写的真好      http://blog.csdn.net/jarily/article/details/8706230
末班参考:   https://www.coder4.com/archives/3577
题型总结:   http://www.voidcn.com/article/p-afvmixig-qq.html
kuangbin:   https://vjudge.net/contest/70655

后缀数组 SA

Str ：需要处理的字符串(长度为Len) 
Suffix[i]：从i开始的字符串后缀
Rank[i] : Suffix[i]在所有后缀中的排名,即i处后缀按字典序的排名
SA[i] : 满足Suffix[SA[1]] < Suffix[SA[2]] …… < Suffix[SA[Len]],即排名为i的后缀为Suffix[SA[i]] (与Rank是互逆运算) 


eg:
i      0  1  2  3  4  5  6  7
rank = 4  6  8  1  2  3  5  7
       a  a  b  a  a  a  a  b 

排名 该串首字母下标  对应串
i    sa[i]          Suffix[sa[i]
1    3              aaaab
2    4              aaab
3    5              aab
4    0              aabaaaab
5    6              ab
6    1              abaaaab
7    2              baaaab
8    7              b

使用SA[i]: 实现找不同子串个数,连续重复子串
求SA[i]算法: 倍增和DC3
*/








const int maxn = 1e5+5;
char ch[MAXN], All[MAXN];
int SA[MAXN], rank[MAXN], Height[MAXN], tax[MAXN], tp[MAXN], a[MAXN], n, m; 
char str[MAXN];
//rank[i] 第i个后缀的排名; SA[i] 排名为i的后缀位置; Height[i] 排名为i的后缀与排名为(i-1)的后缀的LCP
//tax[i] 计数排序辅助数组; tp[i] rank的辅助数组(计数排序中的第二关键字),与SA意义一样。
//a为原串,a[1..n]
void RSort() {
    //rank第一关键字,tp第二关键字。
    for (int i=0;i<=m;i++) tax[i] = 0;
    for (int i=1;i<=n;i++) tax[rank[tp[i]]] ++;
    for (int i=1;i<=m;i++) tax[i] += tax[i-1];
    for (int i=n;i>=1;i--) SA[tax[rank[tp[i]]] --] = tp[i]; //确保满足第一关键字的同时，再满足第二关键字的要求
} //基数排序,把新的二元组排序。

int cmp(int *f, int x, int y, int w) { return f[x]==f[y] && f[x+w]==f[y+w]; } 
//通过二元组两个下标的比较，确定两个子串是否相同

void Suffix() {
    //SA
    for (int i=1;i<=n;i++) rank[i]=a[i], tp[i]=i;
    m = 127 ,RSort(); //一开始是以单个字符为单位，所以(m = 127)

    for (int w=1,p=1,i; p<n; w+=w,m=p) { //把子串长度翻倍,更新rank

        //w 当前一个子串的长度; m 当前离散后的排名种类数
        //当前的tp(第二关键字)可直接由上一次的SA的得到
        for (p=0,i=n-w+1;i<=n;i++) tp[++p] = i; //长度越界,第二关键字为0
        for (i=1;i<=n;i++) if (SA[i] > w) tp[++p] = SA[i] - w;

        //更新SA值,并用tp暂时存下上一轮的rank(用于cmp比较)
        RSort(), swap(rank, tp), rank[SA[1]] = p = 1;

        //用已经完成的SA来更新与它互逆的rank,并离散rank
        for (i=2;i<=n;i++) rank[SA[i]] = cmp(tp, SA[i], SA[i-1], w) ? p : ++ p;
    }
    //离散：把相等的字符串的rank设为相同。
    //LCP
    int j, k = 0;
    for(int i=1;i<=n;Height[rank[i++]] = k) 
        for(k=k?k-1:k,j=SA[rank[i]-1]; a[i+k]==a[j+k]; k++)
            ;
    //这个知道原理后就比较好理解程序
}

void Init() {
    scanf("%s", str);
    n = strlen(str);
    for (int i=0;i<n;i++) a[i+1] = str[i];
}

int main() {
    Init();
    Suffix();

    int ans = Height[2];
    for (int i=3;i<=n;i++) ans += max(Height[i]-Height[i-1],0);
    printf("%d\n", ans);
}





