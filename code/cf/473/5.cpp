#include <bits/stdc++.h>
using namespace std;
//1, 3, 4, 8, 9, 11, 12, 20, 21
//oeis: 
long long dfs(long long n)
{
    if(n==1) return 1;
    else if (n%2==0) return 2*dfs(n/2)+n/2;
    else return 2*dfs((n-1)/2)+(n-1)/2+1;
}
int main()
{
    long long n; cin>>n;
    n--;
    cout << dfs(n);
    return 0;
}
