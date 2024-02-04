#include <iostream>
#include <cstdio>
using namespace std;
int maze[1005][1005];
int dp[1005][1005];

int main() {
//	freopen("escape.in","r",stdin);freopen("escape.out","w",stdout);
	int n,m,x,y,v,c,maxn = 0;
	cin>>n>>m>>x>>y>>v>>c;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=m;j++) {
			cin>>maze[i][j];
		}
	}
	for(int i = x;i>=1;i--) {
		for(int j = y;j>=1;j--) {
			if(i == x && j == y) {
				dp[i][j] = v;
			}
			else if(i == x && dp[i][j + 1] != 0) {
				dp[i][j] = dp[i][j + 1] + maze[i][j];
			}
			else if(j == y && dp[i + 1][j] != 0) {
				dp[i][j] = dp[i + 1][j] + maze[i][j];
			}
			else if(i != x && j != y && dp[i][j + 1] != 0 && dp[i + 1][j] != 0){
				dp[i][j] = max(dp[i + 1][j],dp[i][j + 1]) + maze[i][j];
			}
			if(dp[i][j] > c) dp[i][j] = c;
			if(dp[i][j] < 0) dp[i][j] = 0;
		}
	}
	maxn = max(maxn,dp[1][1]);
	for(int i = x;i>=1;i--) {
		for(int j = y;j<=m;j++) {
			if(i == x && j == y) {
				dp[i][j] = v;
			}
			else if(i == x && dp[i + 1][j] != 0) {
				dp[i][j] = dp[i][j - 1] + maze[i][j];
			}
			else if(j == y && dp[i][j - 1] != 0) {
				dp[i][j] = dp[i + 1][j] + maze[i][j];
			}
			else if(i != x && j != y && dp[i][j - 1] != 0 && dp[i + 1][j] != 0){
				dp[i][j] = max(dp[i + 1][j],dp[i][j - 1]) + maze[i][j];
			}
			if(dp[i][j] > c) dp[i][j] = c;
			if(dp[i][j] < 0) dp[i][j] = 0;
		}
	}
	maxn = max(maxn,dp[1][m]);
	for(int i = x;i<=n;i++) {
		for(int j = y;j>=1;j--) { 
			if(i == x && j == y) {
				dp[i][j] = v;
			}
			else if(i == x && dp[i - 1][j] != 0) {
				dp[i][j] = dp[i][j + 1] + maze[i][j];
			}
			else if(j == y && dp[i][j + 1] != 0) {
				dp[i][j] = dp[i - 1][j] + maze[i][j];
			}
			else if(i != x && j != y && dp[i][j+1] != 0 && dp[i - 1][j] != 0){
				dp[i][j] = max(dp[i - 1][j],dp[i][j + 1]) + maze[i][j];
			}
			if(dp[i][j] > c) dp[i][j] = c;
			if(dp[i][j] < 0) dp[i][j] = 0;
		}
	}
	maxn = max(maxn,dp[n][1]);
	for(int i = x;i<=n;i++) {
		for(int j = y;j<=m;j++) {
			if(i == x && j == y) {
				dp[i][j] = v;
			}
			else if(i == x && dp[i - 1][j] != 0) {
				dp[i][j] = dp[i][j - 1] + maze[i][j];
			}
			else if(j == y && dp[i][j - 1] != 0) {
				dp[i][j] = dp[i - 1][j] + maze[i][j];
			}
			else if(i != x && j != y && dp[i - 1][j] != 0 && dp[i][j - 1] != 0){
				dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]) + maze[i][j];
			}
			if(dp[i][j] > c) dp[i][j] = c;
			if(dp[i][j] < 0) dp[i][j] = 0;
		}
	}
	maxn = max(maxn,dp[n][m]);
	if(maxn == 0) maxn = -1;
	cout << maxn;
	return 0;
}
