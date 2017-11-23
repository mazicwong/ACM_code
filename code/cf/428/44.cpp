
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn = 1e6+10;
const int Mod = 1e9+7;
ll a[Maxn]={};
ll b[Maxn]={},p[Maxn]={};

int main() {  
	freopen("in4","r",stdin);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
    	int x;
    	scanf("%d",&x);
    	a[x]++;
	}
	ll ans=0,x=1;
	for (int i=0;i<=1e6;i++){
		b[i]=x;
		x = (x*2) % Mod;
	}
	for (int i=2;i<=1e6;i++){
		p[i] = i; 
	}
	for (int i=2;i<=1e6;i++){
		for (int j=i+i;j<=1e6;j+=i) p[j]-= p[i];
	}
	for (ll i=2;i<=1e6;i++){
		ll cnt=0;
		for (int j=i;j<=1e6;j+=i) cnt+=a[j];
		if (cnt==0) continue;
		ans+= (cnt * p[i]) % Mod * b[cnt-1] % Mod;
		//cout << ans << endl;
		ans %= Mod;
	}
	cout << ans << endl;
    return 0;  
}  
