#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
bool ans[10000005];
int prime[10000005];
int cnt = 0;
void calc(int n) {
	memset(ans,1,sizeof(ans));
	cnt = 0;
	for(int i = 2;i<=n;i++) {
		if(ans[i]) {
			prime[++cnt] = i;
		}
		for(int j = 1;j<=cnt && i * prime[j] <= n;j++) {
			ans[i * prime[j]] = 0;
			if(i % prime[j] == 0) break;
		}
	}
}

int main() {
	long long n;
	cin>>n;
	calc(n);
	int tmp = log2(n),cnt2 = 2;
	long long ans = pow(2,tmp);
	while(tmp > 0) {
		long long buf = 1;
		while(tmp > 0 && cnt2 <= 5000005) {
			if(ans / buf * prime[cnt2] <= n) {
				break;
			}
			buf *= 2;
			tmp --;
			if(buf > prime[cnt2]) {
				cnt2 ++;
			}
			if(ans / buf * prime[cnt2] <= n) {
				break;
			}
		}
		if(ans / buf * prime[cnt2] <= n)
			ans = ans / buf * prime[cnt2];
	}
	cout << ans << endl;
	return 0;
}
