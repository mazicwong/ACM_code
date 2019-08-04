#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
/*
 * hdu2095 ����������,��һ��������������,������������ż����,�ҳ��������
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
//��set���ķ���
//��STL����,map,ÿ��ȡ��,�����еľ�ɾ��,û�оͷŽ�ȥ,���ʣ�µľ�����

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
            if (st.find(a) == st.end()) //�Ҳ���
                st.insert(a);
            else st.erase(st.find(a));  //�ҵ�
        }
        printf("%d\n",*st.begin());
    }
}
*/

/*
//��map�������ķ���
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
