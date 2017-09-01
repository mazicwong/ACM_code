#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
/*
 * hdu2095 给奇数个数,有一个数出现奇数次,其他数都出现偶数次,找出这个奇数
 */

typedef pair<int,int> pii;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
        int a; scanf("%d",&a);
    }
}

/*
//用set过的方法
//用STL不难,map,每次取数,里面有的就删掉,没有就放进去,最后剩下的就是了

#include <set>
set<int> st;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF && n)
    {
        st.clear();
        for (int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            if (st.find(a) == st.end()) //找不到
                st.insert(a);
            else st.erase(st.find(a));  //找到
        }
        printf("%d\n",*st.begin());
    }
}
*/

/*
//用map暴力过的方法
int main()
{
	int n;
	map<int, int >mp;
	int a;
	while (scanf("%d", &n) && n)
	{
		mp.clear();
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a);
			mp[a]++;
		}
		for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
		{
			if (it->second == 1)
			{
				printf("%d\n", it->first);
				break;
			}
		}
	}
	return 0;
}*/
