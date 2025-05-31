#include <iostream>
#include <cstring>
using namespace std;
int dp[2005][55];
int train[2005][55][2];
int t[55];
int start1[55],start2[55];
int sum1[55];

int main() {
	int n,cnt = 0;
	while(cin>>n && n != 0) {
		cnt ++;
		memset(dp,0x3f,sizeof(dp));
		memset(train,0,sizeof(train));
		memset(sum1,0,sizeof(sum1));
		memset(t,0,sizeof(t));
		int T;
		cin>>T;
		for(int i = 2;i<=n;i++) {
			cin>>t[i];
			sum1[i] = sum1[i - 1] + t[i];
		}
		int m1,m2;
		cin>>m1;
		for(int i = 1;i<=m1;i++) {
			cin>>start1[i];
		}
		cin>>m2;
		for(int i = 1;i<=m2;i++) {
			cin>>start2[i];
		}
		for(int i = 1;i<=m1;i++) {
			train[start1[i]][1][0] = 1;
			for(int j = 2;j<=n;j++) {
				if(sum1[j] + start1[i] <= T)
					train[sum1[j] + start1[i]][j][0] = 1;
			}
		}
		for(int i = 1;i<=m2;i++) {
			train[start2[i]][n][1] = 1;
			for(int j = 1;j<n;j++) {
				if(sum1[n] - sum1[j] + start2[i] <= T) 
					train[sum1[n] - sum1[j] + start2[i]][j][1] = 1;
			}
		}
		dp[T][n] = 0;
		for(int i = T - 1;i>=0;i--) {
			for(int j = 1;j<=n;j++) {
				dp[i][j] = dp[i+1][j] + 1;
				if(train[i][j][0] == 1 && j < n && T - i >= t[j + 1]) {
					dp[i][j] = min(dp[i][j],dp[i + t[j + 1]][j + 1]);
				}
				if(train[i][j][1] == 1 && j > 1 && train[i][j][1] <= T - i) {
					dp[i][j] = min(dp[i][j],dp[i + t[j]][j - 1]);
				}
			}
		}
		if(dp[0][1] >= 0x3f3f3f3f) {
			cout << "Case Number " << cnt << ": " << "impossible" << endl;
			continue;
		}
		cout << "Case Number " << cnt << ": " << dp[0][1] << endl;
	}
	return 0;
}
