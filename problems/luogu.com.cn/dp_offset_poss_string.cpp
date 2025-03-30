#include <iostream>
#include <string>
using namespace std;
int n;
long long dp[1 << 26];
int sum[200005];
long long ans;

int main() {
	cin>>n;
	string s;
	cin>>s;
	for(int i = 0;i<n;i++) {
		sum[i + 1] = sum[i] ^ (1 << (s[i] - 'a'));
	}
	//ans ++;
	for(int i = 1;i<=n;i++) {
		ans += dp[sum[i]];
		if(sum[i] == 0) {
			ans ++;
		}
		dp[sum[i]] ++;
	}
	cout << ans << endl;
	return 0;
}
