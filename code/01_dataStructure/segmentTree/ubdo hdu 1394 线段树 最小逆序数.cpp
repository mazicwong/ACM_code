#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 5000 + 5;

/*

*/

/*
题意: permutation can ROL (循环左移),and find the minimum Inversion Number
	 序列可以循环左移,求最小逆序数
注意第一个元素移动到最后一个元素的逆序数变化是可以推出来的
s
解决: http://www.blogs8.cn/posts/AYKu6af 很好的解释


树状数组做法: http://kugwzk.info/index.php/archives/1398
*/


inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }
typedef struct {
	int left, right;
	int value;//value是
}node;
node tree[maxn * 4];
int arr[maxn];//存放节点
int sum = 0;//查询到的和

void PushUp(int root)
{
	tree[root].value = tree[L(root)].value + tree[R(root)].value;
}

void Build(int l, int r, int root)
{
	tree[root].left = l;
	tree[root].right = r;
	tree[root].value = 0;

	if (l == r)  return;

	int mid = MID(l, r);
	Build(l, mid, L(root));
	Build(mid + 1, r, R(root));
}

//更新区间(整个区间被替换)
void Insert(int l, int r, int val, int root)
{
	//找到叶子
	if (l == tree[root].left&&tree[root].right == r)
	{
		tree[root].value = 1;
		return;
	}

	//叶子在区间外
	if (tree[root].left>val || tree[root].right<val) return;

	//二分root为根的子树,缩小要更新的区间范围,用递归直到包含这个根节点
	int mid = MID(tree[root].left, tree[root].right);
	//下面的判断只是说明要去左子树找还是右子树找
	if (mid < l) Insert(l, r, val, R(root));
	else if (mid >= r) Insert(l, r, val, L(root));
	else
	{
		Insert(l, mid, val, L(root));
		Insert(mid + 1, r, val, R(root));
	}
	//tree[root].value = tree[L(root)].value + tree[R(root)].value;
	PushUp(root);
}

//计算给定区间内的和
void Query(int l, int r, int root)
{
	//节点在查找的区间外
	if (tree[root].left>r || tree[root].right > l)
		return ;

	//节点在查找区间内
	if (l == tree[root].left&&tree[root].right == r)
		sum += tree[root].value;

	int mid = MID(tree[root].left, tree[root].right);
	if (mid < l) Query(l, r, R(root));
	else if (mid >= r) Query(l, r, L(root));
	else
	{
		Query(l, mid, L(root));
		Query(mid + 1, r, R(root));
	}
}


/*
arr[]存点  (1...n)
Build 建树
Insert 更新值
Query 查询区间和
*/
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		Build(0, n - 1, 1);//left,right,root
		sum = 0;//先用下面的for算出最初的排列所有的逆序数,记在sum里
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);//这次是从0~n-1
			//前面比a[i]大的数出现过几个
			Query(arr[i] + 1, n - 1, 1);//left,right,root
			Insert(0,n-1,arr[i],1);//left,right,val,root
		}

		int ans = sum;
		for (int i = 0; i < n; i++)
		{//循环置换
//原来arr[0]的逆序数是arr[0](比他小),把arr[0]放到最后,则逆序数减少arr[0],增加了n-1-arr[0]
			sum = sum - arr[i] + (n - 1 - arr[i]);
			ans = min(ans, sum);
		}
		printf("%d\n", ans);
	}
	return 0;
}