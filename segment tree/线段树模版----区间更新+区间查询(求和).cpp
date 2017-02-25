#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long int;
const int maxn = 1e5 + 5;

/*
参考题型: 
poj 3468 裸的线段树区间更新与查询问题
	区间更新: 加上一个数
	区间查询: 求和
*/

/*
增加: 如果刚好覆盖一个节点,则增加add值,否则更新value,再继续下传
这样就不用每次都更新到叶子节点
查询: 如果不是正好覆盖一个节点,则将add往下传,把add加到value上然后add清零,
接着继续往下查询
*/


inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }
typedef struct {
	int left, right;
	int value, add;//add是可以存放加在整个区间的值,才不用一直更新到叶子
}node;
node tree[maxn * 4];
int arr[maxn];//存放节点
int sum = 0;//查询到的和
void Build(int l, int r, int root)
{
	tree[root].left = l;
	tree[root].right = r;
	tree[root].add = 0;
	if (l == r) { tree[root].value = arr[l]; return; }
	int mid = MID(l, r);
	Build(l, mid, L(root));
	Build(mid + 1, r, R(root));
	tree[root].value = tree[L(root)].value + tree[R(root)].value;
}


/*****以下Update和Insert是一个区间 *****/

//更新节点,把大区间的add值传给小区间
//小区间add加上大的add,小区间的value要更新他所有区间增加的值
void Update(int node)
{
	if (tree[node].add)
	{
		tree[L(node)].add += tree[node].add;
		tree[R(node)].add += tree[node].add;
		tree[L(node)].value += (tree[L(node)].right - tree[L(node)].left + 1)*tree[node].add;
		tree[R(node)].value += (tree[R(node)].right - tree[R(node)].left + 1)*tree[node].add;
		tree[node].add = 0;
	}
}

//更新区间(每个点加一个值)
void Insert(int l, int r, int val, int root)
{
	if (l <= tree[root].left&&tree[root].right <= r)
	{//这个节点在更新的区间里面,直接算完add和value然后退出
		tree[root].add += val;
		tree[root].value += (tree[root].right - tree[root].left + 1)*val;
		return;
	}
	Update(root);
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
	tree[root].value = tree[L(root)].value + tree[R(root)].value;
}

//计算给定区间内的和
void Query(int l, int r, int root)
{
	if (l <= tree[root].left&&tree[root].right <= r)
	{
		sum += tree[root].value;
		return;
	}
	Update(root);

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
Update 更新值到子区间
Query 查询区间和
*/
int main()
{
	int n, q;
	while (scanf("%d%d", &n, &q) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);
		Build(1, n, 1);//left,right,root
		char qq; // if qq=='C',Insert; if qq=='Q',calu the sum
		while (q--)
		{
			getchar();
			qq = getchar();
			if ('C' == qq)
			{
				int l, r;
				int val;
				scanf("%d%d%d", &l, &r, &val);
				Insert(l, r, val, 1);//left,right,value,root
			}
			else
			{
				int l, r;
				scanf("%d%d", &l, &r);
				sum = 0;
				Query(l, r, 1);//left,right,root
				printf("%d\n", sum);
			}
		}
	}
	return 0;
}