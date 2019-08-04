/*************************************************************************
	> File Name: hdu1907 nim.cpp
	> Author: mazicwong
	> Mail: mazicwong@gmail.com
	> Created Time: 2017年06月10日 星期六 02时22分22秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
/* http://blog.csdn.net/lttree/article/details/24874819
 * Nim 
 * John first,Brother second
 * anyone take the last one will lose
 *
 */

const int maxn = 50;
int arr[maxn];
int main()
{
    freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        memset(arr,0,sizeof(arr));
        int n;
        cin>>n;
        for (int i=0;i<n;i++) cin >> arr[i];
        sort(arr,arr+n);
        if (arr[n-1]==1)//全都是1,按奇偶判断谁胜
        {
            if (n%2==0) cout << "John" << endl;//这里跟n&1不一样的。。别搞错
            else cout << "Brother" << endl;
        }
        else//异或和
        {
            int ans = arr[0]^arr[1];
            for (int i=2;i<n;i++)
            {
                ans ^= arr[i];
            }
            if (ans==0) cout << "Brother" << endl;
            else cout << "John" << endl;
        }
        
    }

   return 0; 
}
