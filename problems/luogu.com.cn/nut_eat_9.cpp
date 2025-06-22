#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long n;
long long primes[2000005];
int ans = 0;
bool vis[2000005];
int cnt = 0;
void calc_prime(int n) {
	for(int i = 2;i <= n;i++) {
		if(!vis[i]) {
			primes[++cnt] = i;
		}
		for(int j = 1;j<=cnt && (i * primes[j] <= n);j++) {
			vis[i * primes[j]] = 1;
			if(i % primes[j] == 0) break;
		}
	}
}

void calc(long long n) {
	for(int i = 1;i<=12;i++) {
		if(1ll * primes[i] * primes[i] * primes[i] * primes[i] * primes[i] * primes[i] * primes[i] * primes[i] <= n) {
			ans ++;
		}
		else break;
	}
	for(int i = 1;i<=cnt;i++) {
		long long tmp = n / (primes[i] * primes[i]);
		tmp = sqrt(tmp);
		ans += max(int(upper_bound(primes+i + 1,primes+1+cnt,tmp) - primes - i - 1),0);
	}
}

int main() {
	cin>>n;
	calc_prime(max(int(sqrt(n)),12));
	calc(n);
	cout << ans << endl;
	return 0;
}
