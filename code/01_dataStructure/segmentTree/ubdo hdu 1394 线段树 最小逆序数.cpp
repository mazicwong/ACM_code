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
����: permutation can ROL (ѭ������),and find the minimum Inversion Number
	 ���п���ѭ������,����С������
ע���һ��Ԫ���ƶ������һ��Ԫ�ص��������仯�ǿ����Ƴ�����
s
���: http://www.blogs8.cn/posts/AYKu6af �ܺõĽ���


��״��������: http://kugwzk.info/index.php/archives/1398
*/


inline int L(int l) { return l << 1; }
inline int R(int r) { return (r << 1) + 1; }
inline int MID(int l, int r) { return (l + r) >> 1; }
typedef struct {
	int left, right;
	int value;//value��
}node;
node tree[maxn * 4];
int arr[maxn];//��Žڵ�
int sum = 0;//��ѯ���ĺ�

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

//��������(�������䱻�滻)
void Insert(int l, int r, int val, int root)
{
	//�ҵ�Ҷ��
	if (l == tree[root].left&&tree[root].right == r)
	{
		tree[root].value = 1;
		return;
	}

	//Ҷ����������
	if (tree[root].left>val || tree[root].right<val) return;

	//����rootΪ��������,��СҪ���µ����䷶Χ,�õݹ�ֱ������������ڵ�
	int mid = MID(tree[root].left, tree[root].right);
	//������ж�ֻ��˵��Ҫȥ�������һ�����������
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

//������������ڵĺ�
void Query(int l, int r, int root)
{
	//�ڵ��ڲ��ҵ�������
	if (tree[root].left>r || tree[root].right > l)
		return ;

	//�ڵ��ڲ���������
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
arr[]���  (1...n)
Build ����
Insert ����ֵ
Query ��ѯ�����
*/
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		Build(0, n - 1, 1);//left,right,root
		sum = 0;//���������for���������������е�������,����sum��
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);//����Ǵ�0~n-1
			//ǰ���a[i]��������ֹ�����
			Query(arr[i] + 1, n - 1, 1);//left,right,root
			Insert(0,n-1,arr[i],1);//left,right,val,root
		}

		int ans = sum;
		for (int i = 0; i < n; i++)
		{//ѭ���û�
//ԭ��arr[0]����������arr[0](����С),��arr[0]�ŵ����,������������arr[0],������n-1-arr[0]
			sum = sum - arr[i] + (n - 1 - arr[i]);
			ans = min(ans, sum);
		}
		printf("%d\n", ans);
	}
	return 0;
}