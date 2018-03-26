#include <cstring>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int maxn = 100 + 4;

int ttime[6][2];//ttime[3][0]means pro_3's num; and ttime[3][1]means pro_3's appear times
typedef struct mazic {
	int p;
	int h, m, s;
	int score;

	int i;//for output sequence
}mm;

bool cmp(mm a, mm b)
{//sort by problem_num↓, h,m,s↑
	if (a.p == b.p)
	{
		if (a.h == b.h)
		{
			if (a.m == b.m)
			{
				if (a.s == b.s)
					return a.s < b.s;
			}
			return a.m < b.m;
		}
		return a.h < b.h;
	}
	return a.p > b.p;
}

bool cmp1(mm a, mm b)
{
	return a.i < b.i;
}

int input()
{//(char)06 => (int)06
	char qq = getchar();
	char ww = getchar();
	int tt = (int)qq - '0';
	int cc = (int)ww - '0';
	return tt * 10 + cc;
}
int main()
{
	int n;
	struct mazic mm[maxn];
	while (cin >> n && n>=0)
	{
		memset(ttime, 0, sizeof(ttime));
		for (int i = 0; i < n; i++)
		{
			mm[i].i = i;//for output sequence
			cin >> mm[i].p;
			ttime[mm[i].p][0]++;
			getchar();
			mm[i].h = input();
			getchar();
			mm[i].m = input();
			getchar();
			mm[i].s = input();
			//scanf("%d:%d:%d",&mm[i].h,&mm[i].m,&mm[i].s);

		}
		sort(mm, mm + n, cmp);
		/*for (int i = 0; i < n; i++)
		{
			cout << mm[i].p << " " << endl;
			cout << mm[i].h << mm[i].m << mm[i].s << endl;
		}*/
		for (int i = 0; i < n; i++)
		{
			ttime[mm[i].p][1]++;
			/*cout << ttime[mm[i].p][1] << " " << ttime[mm[i].p][0]<<endl;
			cout << (ttime[mm[i].p][0] >> 1)<<endl;*/
			if (mm[i].p == 5)
			{
				mm[i].score = 100;
				//puts("100");
			}
			else if (mm[i].p == 0)
			{
				mm[i].score = 50;
				//puts("50");
			}
			else if (ttime[mm[i].p][0] == 1)
			{//only one boy is in this pro_num stage
				mm[i].score = 5 + 100 - 10 * (5 - mm[i].p);
			}
			else if (ttime[mm[i].p][1] <= ((ttime[mm[i].p][0]) >> 1))
			{//最终主要还是这里<=写成<  所以才会WA到怀疑人生
				mm[i].score = 5 + 100 - 10 * (5 - mm[i].p);
				//printf("%d\n", 5 + 100 - 10 * (5 - mm[i].p));
			}
			else
			{
				mm[i].score = 100 - 10 * (5 - mm[i].p);
				//printf("%d\n", 100 - 10 * (5 - mm[i].p));
			}
		}
		sort(mm, mm + n, cmp1);
		for (int i = 0; i < n; i++)
			cout << mm[i].score << endl;
		cout << endl;
	}
	return 0;
}