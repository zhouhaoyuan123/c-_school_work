#include <iostream>
using namespace std;
long long fac[5005];
int num[5005];
const long long mod = 998244353;

int main() {
	int n;cin>>n;
	fac[0] = 1;
	for(int i = 0;i<n;i++) {
		fac[i + 1] = fac[i] * (i + 1) % mod;
	}
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	long long ans = 0;
	for(int i = 1;i<=n;i++) {
		int tmp = 0;
		for(int j = 1;j<i;j++) {
			if(num[j] < num[i]) {
				tmp ++;
			}
		}
		ans += (num[i] - tmp - 1) * fac[n - i] % mod;
		ans %= mod;
	}
	cout << (ans + 1) % mod << endl;
	return 0;
}
