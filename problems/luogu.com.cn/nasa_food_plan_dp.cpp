#include <iostream>
using namespace std;
int dp[55][405][405];
int h[55],t[55],k[55];

int main() {
	int ht,tt,n;
	cin>>ht>>tt>>n;
	for(int i = 1;i<=n;i++) {
		cin>>h[i] >> t[i]>>k[i];
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=ht;j++) {
            for(int z = 1;z<=tt;z++) {
			// if(j >= c[i])
			// 	dp[j] = max(dp[j - c[i]] + v[i],dp[j]);
                if(j >= h[i] && z >= t[i]) {
                    dp[i][j][z] = max(dp[i - 1][j][z],dp[i - 1 ][j - h[i]][z - t[i]] + k[i]);
                }
                else {
                    dp[i][j][z] = dp[i - 1][j][z];
                }
            }
		}
	}
	cout << dp[n][ht][tt];
	return 0;
}