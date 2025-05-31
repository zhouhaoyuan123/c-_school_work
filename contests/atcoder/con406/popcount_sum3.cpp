#include <iostream>
#include <cmath>
using namespace std;
const long long mod = 998244353;
long long calc(long long a,long long b,long long p) {
	if(b == 1) {
		return a % p;
	}
	if(b == 0) {
		return 1 % p;
	}
	if(b % 2 == 0) {
		long long res = calc(a,b/2,p);
		return res * res % p;
	}
	else {
		long long res = calc(a,b / 2,p);
		return res * res % p * a % p;
	}
}
long long comb(int a,int b,long long p) {
	long long ans = 1;
	for(int i = a;i>=b;i--) {
		ans *= i;
		ans %= p;
	}
	for(int i = 1;i<=b;i++) {
		ans *= calc(i,p - 2,p);
		ans %= p;
	}
	return ans;
}

int main() {
	int t;
	cin>>t;
	while(t --) {
		int n,k;
		cin>>n>>k;
		int length = int(log2(n)) + 1;
		long long ans = comb(length - 1,k,mod);
		long long tmp = 0,tmp2 = n;
		while(tmp2) {
			if(tmp2 % 2) {
				tmp ++;
			}
			tmp2 /= 2;
		}
		if(tmp >= k) ans += comb(tmp,k,mod);
		ans %= mod;
		cout << ans << endl;
	}
	return 0;
}
