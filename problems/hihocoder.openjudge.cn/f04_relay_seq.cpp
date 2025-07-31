#include <iostream>
using namespace std;
int dp[100005][10];
int num[100005];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>num[i];
	}
	for(int i = 1;i<=n;i++) {
		int tmp = num[i];
		int x = 0,y = tmp % 10;
		while(tmp) {
			x = tmp % 10;
			tmp /= 10;
		}
		for(int j = 0;j<=9;j++) {
			dp[i][j] = dp[i - 1][j] + 1;
		}
		dp[i][y] = min(dp[i][y],dp[i - 1][x]);
	}
	int ans = 1e9;
	for(int i = 0;i<=9;i++) ans = min(ans,dp[n][i]);
	cout << ans << endl;
	return 0;
}
