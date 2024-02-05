#include <iostream>
using namespace std;
int a[30005];
int dp[30005][3];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>a[i];
	}
	dp[1][a[1]] = 0;
	dp[1][!(a[1] - 1) + 1] = 1;
	for(int i = 2;i<=n;i++) {
		if(a[i] == 1) {
			dp[i][1] = dp[i - 1][1];
			dp[i][2] = min(dp[i - 1][2],dp[i - 1][1]) + 1;
		}
		else {
			dp[i][1] = dp[i - 1][1]+ 1;
			dp[i][2] = min(dp[i - 1][2],dp[i - 1][1]);
		}
		//cout << dp[i][1]<<" "<<dp[i][2]<<endl;
	}
	int ans = min(dp[n][1],dp[n][2]);
	//cout << ans;
	cout << ans;
	return 0;
}
