#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 5e4 + 5;

/*
problem :hdu 1166
单点更新: 加或者减一个值
区间查询: 求和


这道题也可以用树状数组做- -代码后面记得补上来
http://poj.org/summerschool/1_interval_tree.pdf	
http://blog.csdn.net/zxy_snow/article/details/6952046
http://www.voidcn.com/blog/a995549572/article/p-5795626.html
*/

inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }
typedef struct {
	int left, right;
	int value;//存区间最大值
}node;
node tree[maxn * 4];
int arr[maxn];//存放节点
int sum = 0;//查询到的和

void Build(int l, int r, int root)
{
	tree[root].left = l;
	tree[root].right = r;
	if (l == r) { tree[root].value = arr[l]; return; }//派到叶子了就给值
	int mid = MID(l, r);
	Build(l, mid, L(root));
	Build(mid + 1, r, R(root));
	tree[root].value = tree[L(root)].value+ tree[R(root)].value;
}


//更新区间(每个点加一个值)
void Insert(int l, int r, int val, int root)
{
	if (l == tree[root].left&&tree[root].right == r)
	{//如果找到了这个人,就更新他然后退出
		tree[root].value += val;
		return;
	}

	//没找到的话,继续二分查找这个同学...
	int mid = MID(tree[root].left, tree[root].right);
	//下面的判断只是说明要去左子树找还是右子树找
	if (mid < l) Insert(l, r, val, R(root));
	else if (mid >= r) Insert(l, r, val, L(root));
	else
	{
		Insert(l, mid, val, L(root));
		Insert(mid + 1, r, val, R(root));
	}
	tree[root].value = tree[L(root)].value+ tree[R(root)].value;
}

//求和,就是节点里的value
void Query(int l, int r, int root)
{
	if (l <= tree[root].left&&tree[root].right <= r)
	{
		sum += tree[root].value;
		return;
	}

	if (tree[root].left == tree[root].right) return;
	int mid = MID(tree[root].left, tree[root].right);
	//下面判断是到左子树找最大还是到右子树找最大
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
	int cas,n;
	scanf("%d", &cas);
	for (int k = 1; k <= cas;k++)
	{
		printf("Case %d:\n", k);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);
		Build(1, n, 1);//left,right,root
		char str[7];
		while (scanf("%s",str)!=EOF)
		{
			if (strcmp(str, "End") == 0) break;
			else if (strcmp(str, "Add") == 0)
			{
				int a,val;
				scanf("%d%d", &a, &val);
				Insert(a, a, val, 1);//left,right,val,root
			}
			else if (strcmp(str, "Sub") == 0)
			{
				int a, val;
				scanf("%d%d", &a, &val);
				Insert(a, a, -1 * val, 1);
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