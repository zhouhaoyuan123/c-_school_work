#include <iostream>
#include <cstring>
using namespace std;
bool ans[10000005];
int prime[10000005];
int sum[10000005];
const int maxn = 10000000;
void calc(int n) {
	memset(ans,1,sizeof(ans));
	int cnt = 0;
	for(int i = 2;i<=n;i++) {
		if(ans[i]) {
			prime[++cnt] = i;
		}
		sum[i] = sum[i - 1] + ans[i];
		for(int j = 1;j<=cnt && i * prime[j] <= n;j++) {
			ans[i * prime[j]] = 0;
			if(i % prime[j] == 0) break;
		}
	}
}
bool check(long long x) {
	for(int i = 1;i * i <= x;i++) {
		if(x % i == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	calc(maxn);
	long long l,r;
	cin>>l>>r;
	if(r <= maxn) {
		cout << sum[r]  - sum[l - 1] << endl;
	}
	else {
		long long res = 0;
		for(long long i = max(l,1ll * maxn + 1);i<=r;i++) {
			if(check(i)) {
				res ++;
			}
		}
		if(l <= maxn) {
			res += 1ll * (sum[maxn] - sum[l - 1]);
		}
		cout << res << endl;
	}
	return 0;
}
