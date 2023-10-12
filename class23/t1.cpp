#include <iostream>
#include <cstring>
using namespace std;
int sum(int n) {
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		if(n % i == 0) {
			ans+=i;
		}
	}
	return ans - n;
}

int main() {
	int s;
	cin>>s;
	int v[s+1];
	v[0] = 0;
	int w[s + 1];
	w[0] = 0;
	for(int i = 1;i<=s;i++) {
		v[i] = sum(i);
		w[i] = i;	
	}
	int dp[s+1][s+1];
	memset(dp,0,sizeof(dp));
	for(int i = 1;i<=s;i++) {
		for(int j = 1;j<=s;j++) {
			if(j >= w[i]) {
				dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - w[i]] + v[i]);	
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[s][s];
	return 0;
}
