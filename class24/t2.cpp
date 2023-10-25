#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int t,n;
	cin>>t>>n;
	int cost[n],value[n];
	for(int i = 0;i<n;i++) {
		cin>>value[i]>>cost[i];
	}
	int dp[t+1];
	memset(dp,0,sizeof(dp));
	for(int i = 1;i<=n;i++) {
		for(int j = cost[i - 1];j<=t;j++) {
			dp[j] = max(dp[j - cost[i - 1]] + value[i - 1],dp[j]);
		}
	}
	cout << dp[t];
	return 0;
}
