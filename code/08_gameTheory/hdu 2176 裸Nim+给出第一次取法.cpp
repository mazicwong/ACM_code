#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*
裸Nim博弈，
并输出先取者第1次取子的所有方法，（a，b），从a中取b个

最后在输出第一次取石子情况那里：num[1]^num[2]^.......^num[n]=ans,(其中ans不为零)，
那么我们的目的是要把必胜状态转化为必败状态从而使得先手胜利
若num[1]^num[2]^....^num[n]!=0，一定存在某个合法的移动，将num[i]改变成num[i]'后满足num[1]^num[2]^.......^num[n]=0

且一定存在某个num[i]，它的二进制形式 在ans的最高位上是1
这时num[i]^ans<num[i]一定成立。即我们可以将num[i]改变成num[i]'=num[i]^ans，这时候就是必败态
此时...^(num[i]')^...=...(num[i]...^ans=0
*/
const int maxn = 2e5 + 5;
int num[maxn];
int main()
{
	std::ios_base::sync_with_stdio(false);
	int n;
	while (cin >> n&&n)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> num[i];
			ans ^= num[i];
		}
		if (ans == 0)
			cout << "No" << endl;
		else
		{
			cout << "Yes" << endl;
			for (int i = 1; i <= n; i++)
			{//取完剩下ans^num[i]就可以从必胜态转化为必败态
				if (num[i] >= (ans^num[i]))
					cout << num[i] << ' ' << (ans^num[i]) << endl;
			}
		}
	}
	return 0;
}