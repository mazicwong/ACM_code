http://blog.csdn.net/lgdblue/article/details/15809893

hdu 1525 SG��������ÿһ���ұ�ʤ̬���򵥲���
hdu 1848 SG��������(dfsģ��)
hdu 3032 SG����ҹ���(���仯�������)--����һ�ѷֳ����ѵ�Nim
hdu 2176 ��Nim+������һ�ε�ȡ��
hdu 5795 ��Nim


����ؼ�:Ѱ�ұذ�̬

�������P̬����Previous�����ֱذܣ���N̬����Next�����ֱ�ʤ����
��һ��move�����б�ʤ���Եľ�����P - position��Ҳ���ǡ����ֱذܡ���
����move�����б�ʤ���Եľ�����N - position��Ҳ���ǡ����ֿɱ�֤��ʤ����


һ����ʲ����


������������


����Fibonacci����


�ġ���ķ����


�塢��ƽ��ϲ��ģ�Impartial Combinatori Games��




//http ://www.cnblogs.com/frog112111/p/3199780.html

SG����ģ��1
hdu 1848
//f[]������ȡ�ߵ�ʯ�Ӹ���
//sg[]:0~maxn��SG����ֵ
//hash[]:mex{}
int f[maxn], sg[maxn], hash[maxn];
void getSG(int n)
{//��n���ڵ�SG����
	int i, j;
	memset(sg, 0, sizeof(sg));
	for (i = 1; i <= n; i++)
	{
		memset(hash, 0, sizeof(hash));
		// ��������g(x)��̵�����1  
		for (j = 1; f[j] <= i; j++)
			hash[sg[i - f[j]]] = 1;
		// �ҵ���С�����ڸü��ϵ���  
		for (int j = 0; j <= n; j++)    //��mex{}��δ���ֵ���С�ķǸ�����
		{
			if (hash[j] == 0)
			{
				sg[i] = j;
				break;
			}
		}
	}
}




SG����ģ��2(dfs)
hdu 1536
//ע�� f����Ҫ����С�������� SG����Ҫ��ʼ��Ϊ-1 ����ÿ������ֻ���ʼ��1��
//n�Ǽ���f�Ĵ�С f[i]�Ƕ����ÿ�ο���ȡ���ٸ�ʯ�ӵ�����

int f[maxn];//����ȡ�ߵ�ʯ�Ӹ���
int sg[maxn];//0~maxn��SG����ֵ
int n;
int SG_dfs(int x)
{
	if (sg[x] != -1)
		return sg[x];
	bool vis[maxm];
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)
	{
		if (x >= f[i])
		{
			SG_dfs(x - f[i]);
			vis[sg[x - f[i]]] = 1;
		}
	}
	for (int i = 0;; i++)
		if (!vis[i])
			return sg[x] = i;
}