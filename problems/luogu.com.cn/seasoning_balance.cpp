#include <iostream>
using namespace std;
int a[105],b[105];
int dp[100005];

int main() {
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>a[i]>>b[i];
	}
	for(int i = 0;i<=100000;i++) {
		dp[i] = -1e9;
	}
	dp[50000] = 0;
	for(int i = 1;i<=n;i++) {
		int tmp1 = a[i] + b[i],tmp2 = a[i] - b[i];
		if(tmp2 <= 0) {
			for(int j = -50000;j <= 50000;j++) {
				if(j - tmp2 + 50000 <= 100000 && dp[j - tmp2 + 50000] >= 0) {
					dp[j + 50000] = max(dp[j + 50000],dp[j - tmp2 + 50000] + tmp1);
				}
			}
		}
		else {
			for(int j = 50000;j >= -50000;j--) {
				if(j - tmp2 + 50000 >= 0 && dp[j - tmp2 + 50000] >= 0) dp[j + 50000] = max(dp[j + 50000],dp[j - tmp2 + 50000] + tmp1);
			}
		}
//		cout << dp[50000 - 1] << endl;
	}
	cout << dp[50000] << endl;
	return 0;
}
