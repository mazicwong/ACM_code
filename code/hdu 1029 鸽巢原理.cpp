/*
* hdu 1029
* author  : mazciwong
* creat on: 2016-1-19
*/

/*
多元素即在数列中出现次数多于n/2的元素

我们很容易的看出来，在一个序列中如果去掉2个不同的元素，
那么原序列中的多元素，在新的序列中还是多元素，
因此我们只要按照序列依次扫描，先把t赋值给result，
增加个计数器，cnt = 1；然后向右扫描，
如果t跟result相同，则cnt++，不同，那么cnt --，
这个真是我们从上面那个结论里得出的，一旦cnt == 0了，
那么必定c不是多元素，这个时候把t赋值为result,cnt = 1；，
重复该过程，直到结束，这个时候，result就是多元素，
这个的时间复杂度为n，该题本来可以用数组保存每个元素，
然后递归上述过程，可是，用数组超内存，
因此我们可以直接按照上述过程计算
*/


#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	int result=0;
	while (scanf("%d", &n) != EOF)
	{
		int t;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &t);
			if (cnt == 0)
			{
				cnt = 1;
				result = t;
			}
			else
			{
				if (t == result)
					cnt++;
				else
					cnt--;
			}
		}
		printf("%d\n", result);
	}
	return 0;
}