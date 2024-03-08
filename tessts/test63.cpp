#include <iostream>
#include <cstdio>
using namespace std;
int dp[205][200005];
int w[205],t[205];

int main() {
//	freopen("tugofwar.in","r",stdin);
//	freopen("tugofwar.out","w",stdout);
	int N;
	cin>>N;
	int cnt = 0;
	for(int i = 1;i<=N;i++) {
		cin>>w[i];
	}
	for(int i = 1;i<=N;i++) {
		cin>>t[i];
		cnt+=t[i] * w[i];
	}
	for(int i = 1;i<=N;i++) {
		for(int j = 0;j<=cnt / 2;j++) {
			dp[i][j] = dp[i - 1][j];
			for(int k = 1;k<=t[i];k++) {
				if(j >= k * w[i]) {
					dp[i][j] = max(dp[i - 1][j - k * w[i]] + k * w[i],dp[i][j]);
				}
			}
			cout << dp[i][j]<<" ";
		}
		cout << endl;
	}
	cout << abs((cnt - dp[N][int(cnt / 2)]) - dp[N][int(cnt / 2)]);
	return 0;
}
