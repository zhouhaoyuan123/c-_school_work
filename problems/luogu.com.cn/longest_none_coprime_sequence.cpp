#include <iostream>
#include <cstring>
using namespace std;
int primes[1000005];
int dp[1000005];
int cnt = 0;
bool ans[1000005];
int num[1000005];
int f[1000005];
void calc(int n) {
	memset(ans,1,sizeof(ans));
	for(int i = 2;i<=n;i++) {
		if(ans[i]) {
			f[i] = i;
			primes[++cnt] = i;
		}
		for(int j = 1;i * primes[j] <= n;j++) {
			ans[i * primes[j]] = 0;
			f[i * primes[j]] = primes[j];
			if(i % primes[j] == 0) break;
		}
	}
}

int main() {
	int n;
	cin>>n;
	calc(1e6 + 5);
	for(int i = 1;i<=n;i++) cin>>num[i];
	for(int i = 1;i<=n;i++) {
		int tmp = 0;
		int tmp2 = num[i];
		while(tmp2 > 1) {
			tmp = max(tmp,dp[f[tmp2]]); 
			tmp2 /= f[tmp2];
		}
		tmp ++;
		tmp2 = num[i];
		while(tmp2 > 1) {
			dp[f[tmp2]] = max(dp[f[tmp2]],tmp);
			tmp2 /= f[tmp2];
		}
	}
	int res = 1;
	for(int i = 1;i<=n;i++) {
		res = max(res,dp[i]);
	}
	cout << res << endl;
	return 0;
}
