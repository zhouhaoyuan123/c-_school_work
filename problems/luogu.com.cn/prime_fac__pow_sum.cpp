#include <iostream>
using namespace std;
int primes[10000005];
bool vis[10000005];
long long f[10000005];
void calc(int n) {
	int cnt = 0;
	for(int i = 2;i <= n;i++) {
		if(!vis[i]) {
			primes[++cnt] = i;
			f[i] = 1;
		}
		for(int j = 1;j<=cnt && (i * primes[j] <= n);j++) {
			vis[i * primes[j]] = 1;
			f[i * primes[j]] = f[i] + f[primes[j]];
			if(i % primes[j] == 0) break;
		}
	}
}

int main() {
	int n;
	cin>>n;
	calc(n);
	long long ans = 0;
	for(int i = 2;i<=n;i++) {
		ans += f[i];
	}
	cout << ans << endl;
	return 0; 
}
