离散化:就是将n个数字和1~n对应起来
使用STL算法离散化：
思路：先排序，再删除重复元素，然后就是索引元素离散化后对应的值。

/*
 * eg:
 * 一组数据:1,4,1000,100000;直接开线段树很浪费,则先离散化
 *
 * 离散化前 a[i]: 1,    4,   1000, 100000,
 * 离散化后 a[i]: 1,    2,    3,    4,
 *               a[0], a[1], a[2], a[3],
 */

const int maxn = 100;
int n=6;
int a[maxn];//离散化后的数组a
void lisan(int *arr)//传入数组arr[0..n-1],返回a[0..n-1]
{
    for (int i=0;i<n;i++) a[i]=arr[i];

    sort(a,a+n);
    int size = unique(a,a+n)-a; //size是离散化后元素个数
    for (int i=0;i<n;i++)
        a[i] = lower_bound(a,a+size,arr[i])-a+1;
}

int main()
{
    int qq[20]={0,1,4,6,7,800,1000};
    lisan(qq);
    for (int i=0;i<=n;i++)
        cout << "i:" << i << "   a:[" << i << "]: "<<  a[i] << endl;

    return 0;
}
