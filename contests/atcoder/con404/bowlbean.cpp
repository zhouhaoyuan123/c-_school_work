#include <iostream>
#include <cstring>
using namespace std;
int c[2005],a[2005],dp[2005];

int main() {
	memset(dp,0x3f,sizeof(dp));
	int n;
	cin>>n;
	for(int i = 1;i<n;i++) {
		cin>>c[i];
	}
	for(int i = 1;i<n;i++) {
		cin>>a[i];
	}
	dp[0] = 0;
	int ans = 0;
	for(int i = 1;i<n;i++) {
		for(int j = i - c[i];j<=i - 1;j++) {
			dp[i] = min(dp[i],dp[j] + 1);
		}
		if(a[i]) {
			ans += dp[i];
			dp[i] = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
