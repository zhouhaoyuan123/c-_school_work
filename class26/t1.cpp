#include <iostream>
using namespace std;
int v[2001],c[2001];
int dp[2001][40001];

int main() {
	int n,w;
	cin>>n>>w;
	int t = 0;
	for(int i = 0;i<n;i++) {
		int vi,wi,mi;
		cin>>vi>>wi>>mi;
		int p = 1;
		while(mi >= p) {
			t++;
			v[t] = p * vi;
			c[t] = p * wi;
			mi -= p;
			p *= 2;
		} 
		if(mi > 0) {
			t++;
			v[t] = mi * vi;
			c[t] = mi * wi;
		}
	}
	for(int i = 1;i<=t;i++) {
		for(int j = 1;j<=w;j++) {
			if(c[i] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - c[i]] + v[i]);
			}
		}
	}
	cout << dp[t][w];
	return 0;
}
