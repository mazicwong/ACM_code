#include "iostream"
#include "cstdio"
#include "cstring"
#include "string"
#include "cmath"
using namespace std;
typedef long long LL;
int q;
int n;
int main()
{
	cin>>q;
	for(int cas=1;cas<=q;cas++)
    {
		int n;
		scanf("%d",&n);
		int num=n%4;
		int res=n/4;
		if(num==0)
			cout<<res<<endl;
        else if(num==1)
        {
			if(res<2)
				cout<<"-1"<<endl;
            else
				cout<<res-1<<endl;
		}
        else if(num==2)
        {
			if(res<1)
				cout<<"-1"<<endl;
            else
				cout<<res<<endl;
		}
        else if(num==3)
        {
			if(res<3)
				cout<<"-1"<<endl;
			else
				cout<<res-1<<endl;
		}
	}
	return 0;
}
