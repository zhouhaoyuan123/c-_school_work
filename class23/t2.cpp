#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int w1, w2;
	cin >> w1 >> w2;
	int n;
	cin >> n;
	int num[n + 1], num2[n + 1], num3[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> num[i] >> num2[i] >> num3[i];
	}
	int dp[w1 + 1][w2 + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = w1; j >= 1; j--) {
			for (int x = w2; x >= 1; x--) {
				if (j >= num[i] && x >= num2[i]) {
					dp[j][x] = max(dp[j][x], dp[j - num[i]][x - num2[i]] + num3[i]);
				}
			}
		}
	}
	cout << dp[w1][w2];
	return 0;
}
