#include<bits/stdc++.h>
#define LL long long int
using namespace std;
LL f(LL x)
{
	if(x==1)return 1;
	if(x%2==0) return 2*f(x/2)+x/2;
	else return 2*f((x-1)/2)+(x-1)/2+1; 
}
int main()
{
	LL n;
for(LL i=2;i<=20;i++)
{
   n=i;
	n--;
	cout<<f(n)<<',';
}
	return 0;
}
