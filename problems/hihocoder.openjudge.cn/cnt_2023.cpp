#include <iostream>
using namespace std;
const int maxn = 6000005;
const long long mod = 1000000007;
int num[maxn];
int tmp_num[10];
long long sum3[maxn],sum23[maxn],sum023[maxn];

int main() {
	int n;
	cin>>n;
	int cnt = 0;
	for(int i = 1;i<=n;i++) {
		int tmp = i,cnt2 = 0;
		while(tmp) {
			int cur = tmp % 10;
			if(cur == 2 || cur == 0 || cur == 3) {
				tmp_num[++cnt2] = cur;
			}
			tmp /= 10;
		}
		for(int i = cnt2;i>=1;i--) {
			num[++cnt] = tmp_num[i];
		}
	}
	for(int i = cnt;i>=1;i--) {
		sum3[i] = sum3[i + 1];
		if(num[i] == 3) {
			sum3[i] ++;
		}
		sum3[i] %= mod;
	}
	for(int i = cnt;i>=1;i--) {
		sum23[i] = sum23[i + 1];
		if(num[i] == 2) {
			sum23[i] += sum3[i + 1];
		}
		sum23[i] %= mod;
	}
	for(int i = cnt;i>=1;i --) {
		sum023[i] = sum023[i + 1];
		if(num[i] == 0) {
			sum023[i] += sum23[i + 1];
		}
		sum023[i] %= mod;
	}
	long long ans = 0;
	for(int i = cnt;i>=1;i--) {
		if(num[i] == 2) {
			ans += sum023[i + 1];
			ans %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}
