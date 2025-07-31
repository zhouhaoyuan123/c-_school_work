#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int num[1005];
int dp[1005];
int n,m;

bool judge(long long x) {
	memset(dp,0x3f,sizeof(dp));
	for(int i = 1;i<=n;i++) {
		dp[i] = i - 1;
		for(int j = 1;j<i;j++) {
			if((abs(num[j] - num[i]) + i - j - 1) / (i - j) <= x) dp[i] = min(dp[i],dp[j] + i - j - 1);
		}
	}
	for(int i = 1;i<=n;i++) {
		if(dp[i] + n - i <= m) {
			return true;
		}
	}
	return false;
}

int main() {
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	long long l = 0,r = 2e9;
	long long ans = 2e9;
	while(l <= r) {
		long long mid = (l + r) / 2;
		if(judge(mid)) {
			r = mid - 1;
			ans = mid;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans << endl;
	return 0;
}
