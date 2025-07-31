#include <iostream>
using namespace std;
int dp[100005][25][3];
int input[100005];
bool getscore(int a,int b) {
	return (a == (b + 1) % 3);
}
int main() {
	int n,k;
	cin>>n>>k;
	string op;
	cin>>op;
	for(int i = 0;i<op.size();i++) {
		if(op[i] == 'R') {
			input[i + 1] = 2;
		}
		else if(op[i] == 'S') {
			input[i + 1] = 1;
		}
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 0;j <= k;j ++) {
			for(int z = 0;z <= 2;z ++) {
				dp[i][j][z] = dp[i - 1][j][z] + getscore(z,input[i]);
				if(j) {
					for(int a = 0;a <= 2;a ++) {
						dp[i][j][z] = max(dp[i][j][z],dp[i - 1][j - 1][a] + getscore(z,input[i]));
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0;i<=2;i++) ans = max(ans,dp[n][k][i]);
	cout << ans << endl;
	return 0;
}
