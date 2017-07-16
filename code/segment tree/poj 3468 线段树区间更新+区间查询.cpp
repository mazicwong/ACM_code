#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
/*
problem: poj 3468 裸的线段树区间更新与查询问题
solve：
thinking: 
*/


/*
增加: 如果刚好覆盖一个节点,则增加add值,否则更新value,再继续下传
	  这样就不用每次都更新到叶子节点
查询: 如果不是正好覆盖一个节点,则将add往下传,把add加到value上然后add清零,
	  接着继续往下查询
*/


const int maxn = 1e5 + 5;
inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }
typedef struct {
	int left, right;
	ll value, add;
}node;
node tree[maxn * 4];
ll arr[maxn];
ll sum = 0;
void Creat(int l, int r, int root)
{
	tree[root].left = l;
	tree[root].right = r;
	tree[root].add = 0;
	if (l == r) {tree[root].value = arr[l]; return;}
	int mid = MID(l, r);
	Creat(l, mid, L(root));
	Creat(mid + 1, r, R(root));
	tree[root].value = tree[L(root)].value + tree[R(root)].value;
}

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
void Add(int l, int r, ll val, int root)
{
	if (l <= tree[root].left&&tree[root].right<=r)
	{//这个节点在更新的区间里面,直接算完add和value然后退出
		tree[root].add += val;
		tree[root].value += (tree[root].right - tree[root].left + 1)*val;
		return;
	}
	Update(root);
	if (tree[root].left == tree[root].right) return;

	//二分root为根的子树,缩小要更新的区间范围,用递归直到包含这个根节点
	int mid = MID(tree[root].left, tree[root].right);
	if (mid < l) Add(l, r, val, R(root));
	else if (mid >= r) Add(l, r, val, L(root));
	else
	{
		Add(l, mid, val, L(root));
		Add(mid + 1, r, val, R(root));
	}
	tree[root].value = tree[L(root)].value + tree[R(root)].value;
}

//计算给定区间内的和
void Solve(int l,int r,int root)
{
	if (l <= tree[root].left&&tree[root].right <= r)
	{
		sum += tree[root].value;
		return;
	}
	Update(root);

	if (tree[root].left == tree[root].right)return;
	
	int mid = MID(tree[root].left, tree[root].right);
	if (mid < l) Solve(l, r, R(root));
	else if (mid >= r) Solve(l, r, L(root));
	else
	{
		Solve(l, mid, L(root));
		Solve(mid + 1, r, R(root));
	}
}

int main()
{
	int n, q;
	while (scanf("%d%d", &n, &q) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf("%I64d", &arr[i]);
		Creat(1, n, 1);
		char qq;
		while (q--)
		{
			getchar();
			qq = getchar();
			if ('C' == qq)
			{
				int l, r;
				ll val;
				scanf("%d%d%I64d", &l, &r, &val);
				Add(l, r, val, 1);//left,right,value,root
			}
			else
			{
				int l, r;
				scanf("%d%d", &l, &r);
				sum = 0;
				Solve(l, r, 1);//left,right,root
				printf("%I64d\n", sum);
			}
		}
	}
	return 0;
}