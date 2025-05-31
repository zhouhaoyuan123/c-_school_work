#include <iostream>
#include <cstring>
using namespace std;
const long long mod = 998244353;
typedef long long ll;
long long fac[4000005];
ll qpow(ll a,ll b,ll p)
{
	ll tmp = 1;
	a=a%p;
	while(b)
	{
		if(1&b) tmp = tmp*a%p;
		a = a*a%p;
		b>>=1;
	}
	return tmp%p;
}
ll inv(ll a,ll p)
{
	return qpow(a,p-2,p);
}
void init(int n) {
	fac[0] = 1;
	for(int i = 1;i<=n;i++) {
		fac[i] = fac[i - 1] * (1ll * i) % mod;
	}
}
long long calc(int a,int b) {
	//factorial(n) / (factorial(m) * factorial(n - m))
	long long ans = 1;
	ans = fac[b];
	ans *= inv(fac[a],mod);
	ans %= mod;
	ans *= inv(fac[b - a],mod);
	ans %= mod;
	return ans;
} 

int main() {
	init(4000005);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	long long ans = 0;
	for(int i = d;i<=c+d;i++) {
		//c
		ans += calc(d - 1,i - 1) % mod * calc(b,a +b + c+d - i) % mod;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
