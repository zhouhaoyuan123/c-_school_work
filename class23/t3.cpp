#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n,bl,ml;
	cin>>n>>bl>>ml;
	int maxn = ml - bl;
	int c[n+1];
	memset(c,0,sizeof(c));
	for(int i = 1;i<=n;i++) {
		cin>>c[i];
	}
	int dp[n+1][maxn+1];
	memset(dp,0,sizeof(dp));
	bool flag = 1;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=maxn;j++) {
			if(j>=c[i]) {
				flag = 0;
				dp[i][j] = dp[i - 1][j - c[i]] + c[i];
				dp[i][j] = max(dp[i][j],dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	if(flag || dp[n][maxn] < 0) {
		cout << -1;return 0;
	}
	cout << bl + dp[n][maxn];
	return 0;
}
