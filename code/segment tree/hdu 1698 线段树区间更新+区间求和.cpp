#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 5;

/*

*/

/*
增加: 如果刚好覆盖一个节点,则增加lazy值,否则更新value,再继续下传
这样就不用每次都更新到叶子节点
查询: 如果不是正好覆盖一个节点,则将lazy往下传,把lazy加到value上然后lazy清零,
接着继续往下查询
*/


inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }
typedef struct {
	int left, right;
	int value, lazy;//lazy是可以存放加在整个区间的值,才不用一直更新到叶子
}node;
node tree[maxn * 4];
//int arr[maxn];//存放节点
int sum = 0;//查询到的和

//更新节点,把大区间的lazy值传给小区间
//小区间lazy加上大的lazy,小区间的value要更新他所有区间增加的值
void PushUp(int root)
{
	tree[root].value = tree[L(root)].value + tree[R(root)].value;
}

void PushDown(int node)
{//往下推,更新子区间的lazy
 //如果有lazy,则左右子树lazy更新一次,左右子树的值也更新一次
	if (tree[node].lazy)
	{
		tree[L(node)].lazy = tree[node].lazy;
		tree[R(node)].lazy = tree[node].lazy;
		tree[L(node)].value = (tree[L(node)].right - tree[L(node)].left + 1)*tree[node].lazy;
		tree[R(node)].value = (tree[R(node)].right - tree[R(node)].left + 1)*tree[node].lazy;
		tree[node].lazy = 0;
	}
}

void Build(int l, int r, int root)
{
	tree[root].left = l;
	tree[root].right = r;
	tree[root].lazy = 0;
	if (l == r) { tree[root].value = 1; return; }
	int mid = MID(l, r);
	Build(l, mid, L(root));
	Build(mid + 1, r, R(root));
	PushUp(root);
}

//更新区间(整个区间被替换)
void Insert(int l, int r, int val, int root)
{
	if (l <= tree[root].left&&tree[root].right <= r)
	{//这个节点在更新的区间里面,直接算完lazy和value然后退出
		tree[root].lazy = val;
		tree[root].value = (tree[root].right - tree[root].left + 1)*val;
		return;
	}
	PushDown(root);
	if (tree[root].left == tree[root].right) return;

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
	if (l <= tree[root].left&&tree[root].right <= r)
	{
		sum += tree[root].value;
		return;
	}
	PushDown(root);

	if (tree[root].left == tree[root].right)return;

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
	int cas, n, q;
	scanf("%d", &cas);
	for (int k = 1; k <= cas;k++)
	{
		scanf("%d%d", &n, &q);
		Build(1, n, 1);//left,right,root
		while (q--)
		{
			int l, r, val;
			scanf("%d%d%d", &l, &r, &val);
			Insert(l, r, val, 1);
		}
		sum = 0;
		Query(1, n, 1);
		printf("Case %d: The total value of the hook is %d.\n", k, sum);
	}
	return 0;
}