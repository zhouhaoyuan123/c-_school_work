#include <iostream>
using namespace std;
int matrix[105][105];
int sum[105][105];

int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=m;j++) {
			cin>>matrix[i][j];
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i][j];
		}
	}
	int ans = 0;
	for(int i =1;i<=n;i++) {
		for(int j = 1;j<=m;j++) {
			for(int k = 1;k<=min(i,j);k++) {
				if(sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k] == k*k) {
					ans = max(ans,k);
				}
			}
		}
	}
	cout << ans;
	return 0;
}
