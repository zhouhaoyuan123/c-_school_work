#include <iostream>
using namespace std;
long long fac[1000005];
long long num[1000005];
long long num2[1000005];
const long long mod = 1e9 + 7;
long long pow(long long a,long long b,long long p) {
	if(a == 1) {
		return 1 % p;
	}
	if(b == 1) {
		return a % p;
	}
	if(b == 0) {
		return 1 % p;
	}
	long long res = pow(a,b/2,p);
	if(b % 2) {
		return res * res % p * a % p;
	}
	else {
		return res * res % p;
	}
}
long long comb(int a, int b, long long p) {
	if(a == 0) return 1 % p;
	if(a == b) return 1 % p;
	long long tmp = pow(fac[a],p - 2,p);
	cout << fac[b] * tmp % p << endl;
	return 1ll * fac[b] * tmp % p * tmp % p;
}


int main() {
	int n;
	cin>>n;
	fac[0] = 1;
	num[0] = 1;
	num2[0] = 1;
	for(int i = 1;i<=n;i++) {
		fac[i] = fac[i - 1] * i % mod;
		num[i] = num[i - 1] * 10 % mod;
		num2[i] = num2[i - 1] * 8 % mod;
	}
	cout << (((pow(10,n,mod) - pow(9,n,mod) + mod) % mod - pow(9,n,mod) + mod) % mod + pow(8,n,mod)) % mod << endl;
	return 0;
}
