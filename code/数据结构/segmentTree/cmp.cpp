typedef struct {
	int left, right;
	int sum;
} NODE;

#define MAXSIZE 5001  

int n;
int a[MAXSIZE];
NODE segTree[MAXSIZE * 2];

// 构造线段树  
void build(int id, int left, int right)
{
	segTree[id].left = left;
	segTree[id].right = right;
	segTree[id].sum = 0;

	if (left == right)
		return;

	int mid = (left + right) / 2;
	build(id * 2, left, mid);
	build(id * 2 + 1, mid + 1, right);
}

int query(int id, int left, int right)
{
	// 当前节点所代表的区间与要查找的区间 (left, right) 没有交集  
	if (segTree[id].left > right || segTree[id].right < left)
		return 0;
	// 当前节点所代表的区间在要查找的区间之内  
	if (left == segTree[id].left && segTree[id].right == right)
		return segTree[id].sum;

	int mid = (segTree[id].left + segTree[id].right) / 2;
	int sum = 0;

	if (right < mid)         // 若待查区间在当前区间的左半边  
		sum += query(id * 2, left, right);
	// 若待查区间在当前区间的右半边, 可能是 hdu 数据不严谨，  
	// 下面判断中换成 mid < left 也能过……  
	else if (mid + 1 < left)
		sum += query(id * 2 + 1, left, right);
	else                        // 若待查区间 横跨 当前区间的中部  
		sum += query(id * 2, left, mid) + query(id * 2 + 1, mid + 1, right);

	return sum;
}

int update(int id, int val)
{
	// 找到叶子  
	if (segTree[id].left == val && segTree[id].right == val)
	{
		return segTree[id].sum = 1;
	}

	// val 不在当前节点所代表的范围内  
	if (segTree[id].left > val || segTree[id].right < val)
		return 0;

	int mid = (segTree[id].left + segTree[id].right) / 2;

	// val 分布在当前区间的右半边  
	if (mid < val)   // 不能等于  
		segTree[id].sum += update(id * 2 + 1, val);
	// val 分布在当前区间的左半边  
	else
		segTree[id].sum += update(id * 2, val);

	return 1;
}

int main()
{
	int i, j;
	int sum, res;
	while (scanf("%d", &n) != EOF)
	{
		// 构造线段树  
		build(1, 1, n);
		sum = 0;
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			// 查询比 a[i] 大的数是否出现过，返回出现的次数，  
			// 即为 满足 x > a[i] 的逆序数对  
			sum += query(1, a[i] + 1, n - 1);
			// 查询完之后，将 a[i] 加入线段树中  
			update(1, a[i]);
		}

		// 首先要知道这么个性质：对任意的一列逆序数，设其第一个数为 a   
		// 则在 a 之后比 a 小的数必然有 a 个：0, 1, 2, ... , a - 1  
		res = sum;
		for (i = 0; i < n; ++i)
		{
			sum = sum - a[i] + (n - a[i] - 1);
			res = min(res, sum);
		}
		printf("%d\n", res);
	}
	return 0;
}


*****************************************************
#include
#include
using namespace std;
#define lson l , m , rt << 1
#define rson m + 1, r , rt << 1 | 1
const int maxn = 5005;
int sum[maxn << 2];

void PushUp(int rt)
{
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int l, int r, int rt)
{
	sum[rt] = 0;
	if (l == r) return;
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
}


void upd(int p, int l, int r, int rt)
{
	if (l == r)
	{
		sum[rt]++;
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m) upd(p, lson);
	else    upd(p, rson);
	PushUp(rt);
}

int qry(int L, int R, int l, int r, int rt)
{
	if (L <= l && r <= R)
	{
		return sum[rt];
	}
	int m = (l + r) >> 1;
	int ret = 0;
	if (L <= m) ret += qry(L, R, lson);
	if (R > m)  ret += qry(L, R, rson);
	return ret;
}

int main()
{
	int N;
	while (~scanf("%d", &N))
	{
		int ans[maxn];
		build(0, N - 1, 1);
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &ans[i]);
			sum += qry(ans[i], N - 1, 0, N - 1, 1);
			upd(ans[i], 0, N - 1, 1);
		}
		int ret = sum;
		for (int i = 0; i < N; i++)
		{
			sum += N - ans[i] - ans[i] - 1;
			ret = min(ret, sum);
		}
		printf("%d\n", ret);
	}
	return 0;
}